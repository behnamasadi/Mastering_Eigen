#include <random>
#include <iostream>
#include <ctime>
#include <chrono>
#include <Eigen/Dense>

/////////////////////////////////////////////////////// first solution ///////////////////////////////////////////////////////
/*
Refs :
1) https://stackoverflow.com/questions/6142576/sample-from-multivariate-normal-gaussian-distribution-in-c
2) http://blog.sarantop.com/notes/mvn
*/
struct normal_random_variable
{
    normal_random_variable(Eigen::MatrixXd const& covar)  : normal_random_variable(Eigen::VectorXd::Zero(covar.rows()), covar)
    {}

    normal_random_variable(Eigen::VectorXd const& mean, Eigen::MatrixXd const& covar) : mean(mean)
    {
        Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigenSolver(covar);
        transform = eigenSolver.eigenvectors() * eigenSolver.eigenvalues().cwiseSqrt().asDiagonal();
    }

    Eigen::VectorXd mean;
    Eigen::MatrixXd transform;

    Eigen::VectorXd operator()() const
    {
        static std::mt19937 gen{ std::random_device{}() };
        static std::normal_distribution<> dist;

        return mean + transform * Eigen::VectorXd{ mean.size() }.unaryExpr([&](auto x) { return dist(gen); });
    }
};




/////////////////////////////////////////////////////// second solution ///////////////////////////////////////////////////////

/*
  We need a functor that can pretend it's const, but to be a good random number generator, it needs mutable state.
*/
namespace Eigen
{
    namespace internal
    {
        template<typename Scalar>
        struct scalar_normal_dist_op
        {
          static std::mt19937 rng;    // The uniform pseudo-random algorithm
          mutable std::normal_distribution<Scalar> norm;  // The gaussian combinator

          EIGEN_EMPTY_STRUCT_CTOR(scalar_normal_dist_op)

          template<typename Index>
          inline const Scalar operator() (Index, Index = 0) const { return norm(rng); }
        };

        template<typename Scalar> std::mt19937 scalar_normal_dist_op<Scalar>::rng;

        template<typename Scalar>
        struct functor_traits<scalar_normal_dist_op<Scalar> >
        {
            enum { Cost = 50 * NumTraits<Scalar>::MulCost, PacketAccess = false, IsRepeatable = false };
        };
    } // end namespace internal
} // end namespace Eigen


int main()
{

std::cout <<"/////////////////////////////////////////////////////// first solution ///////////////////////////////////////////////////////"<< std::endl;
    {
        int size = 2;
        Eigen::VectorXd  mean(size);
        mean<<10,20;
        Eigen::MatrixXd covar(size,size);
        covar << 1, .5,
                .5, 1;

        normal_random_variable sample {mean, covar };


        std::cout << "Mean\n" << mean << std::endl;
        std::cout << "Covar\n" << covar << std::endl;
        std::cout << "Samples\n" << sample() << std::endl;



    }

std::cout <<"/////////////////////////////////////////////////////// second solution ///////////////////////////////////////////////////////"<< std::endl;
    {
        int size = 2; // Dimensionality (rows)
        int numberOfSamples=5;     // How many samples (columns) to draw
        Eigen::internal::scalar_normal_dist_op<double> randN; // Gaussian functor
        Eigen::internal::scalar_normal_dist_op<double>::rng.seed(1); // Seed the rng

        // Define mean and covariance of the distribution
        Eigen::VectorXd mean(size);
        Eigen::MatrixXd covar(size,size);

        mean  <<  0,  0;
        covar <<  1, .5,
        .5,  1;

        Eigen::MatrixXd normTransform(size,size);

        Eigen::LLT<Eigen::MatrixXd> cholSolver(covar);

        // We can only use the cholesky decomposition if the covariance matrix is symmetric, pos-definite.
        // But a covariance matrix might be pos-semi-definite. In that case, we'll go to an EigenSolver
        if (cholSolver.info()==Eigen::Success)
        {
            // Use cholesky solver
            normTransform = cholSolver.matrixL();
        } else
        {
            // Use eigen solver
            Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigenSolver(covar);
            normTransform = eigenSolver.eigenvectors()
            * eigenSolver.eigenvalues().cwiseSqrt().asDiagonal();
        }

        Eigen::MatrixXd samples = (normTransform* Eigen::MatrixXd::NullaryExpr(size,numberOfSamples,randN)).colwise() + mean;

        std::cout << "Mean\n" << mean << std::endl;
        std::cout << "Covar\n" << covar << std::endl;
        std::cout << "Samples\n" << samples << std::endl;

    }

}


