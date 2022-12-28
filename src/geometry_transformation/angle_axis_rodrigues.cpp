#include <iostream>
#include <Eigen/Dense>
#include <iostream>

#include "euler_angles_to_rotation_matrix.hpp"

int main()
{
    //////////////////////////////////////// Rodrigues ///////////////////////////////////////////
    Eigen::Matrix3d rotationMatrix;

    double roll, pitch, yaw;
    roll=M_PI/2;
    pitch=M_PI/2;
    yaw=M_PI/6;

    rotationMatrix= eulerAnglesToRotationMatrix(roll, pitch,yaw);

    //Rotation Matrix to Rodrigues
    Eigen::AngleAxisd rodrigues(rotationMatrix );
    std::cout<<"Rodrigues Angle:\n"<<rodrigues.angle() <<std::endl;

    std::cout<<"Rodrigues Axis:" <<std::endl;

    std::cout<<rodrigues.axis().x() <<std::endl;
    std::cout<<rodrigues.axis().y() <<std::endl;
    std::cout<<rodrigues.axis().z() <<std::endl;



}
