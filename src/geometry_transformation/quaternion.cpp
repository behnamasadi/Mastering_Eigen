#include <iostream>
#include <Eigen/Dense>

//////////////////////////////////////// Quaternion ///////////////////////////////////////////
void quaternionFromRollPitchYaw()
{
    Eigen::Vector3d vector3d(2.3,3.1,1.7);
    Eigen::Vector3d vector3dNormalized=vector3d.normalized();
    double theta=M_PI/7;
    Eigen::AngleAxisd angleAxisConversion(theta,vector3dNormalized);
    Eigen::Matrix3d rotationMatrixConversion;

    // Angle Axis (Rodrigues) to Rotation Matrix
    rotationMatrixConversion=angleAxisConversion.toRotationMatrix();


    //Rotation Matrix to Quaternion

    Eigen::Quaterniond QuaternionConversion(rotationMatrixConversion);

    //Rotation Matrix to Euler Angle (Proper)
    Eigen::Vector3d euler_angles = rotationMatrixConversion.eulerAngles(2, 0, 2);

    //Eigen::Quaterniond
    Eigen::Quaterniond tmp = Eigen::AngleAxisd(euler_angles[0], Eigen::Vector3d::UnitZ())
     * Eigen::AngleAxisd(euler_angles[1], Eigen::Vector3d::UnitX())
     * Eigen::AngleAxisd(euler_angles[2], Eigen::Vector3d::UnitZ());


    Eigen::Quaternion<double> q = yawAngle * pitchAngle * rollAngle;

    
    //Quaternion to Rotation Matrix
    Eigen::Matrix3d rotationMatrix = q.matrix();
    std::cout << "3x3 Rotation Matrix" << std::endl;

    std::cout << rotationMatrix << std::endl;

    Eigen::Quaterniond quaternion_mat(rotationMatrix);
    std::cout << "Quaternion X: " << quaternion_mat.x() << std::endl;
    std::cout << "Quaternion Y: " << quaternion_mat.y() << std::endl;
    std::cout << "Quaternion Z: " << quaternion_mat.z() << std::endl;
    std::cout << "Quaternion W: " << quaternion_mat.w() << std::endl;

}

struct Quaternion
{
    double w, x, y, z;
};

Quaternion rollPitchYawToQuaternion(double roll, double pitch, double yaw) // roll (x), pitch (Y), yaw (z)
{
    // Abbreviations for the various angular functions

    double cr = cos(roll * 0.5);
    double sr = sin(roll * 0.5);
    double cp = cos(pitch * 0.5);
    double sp = sin(pitch * 0.5);
    double cy = cos(yaw * 0.5);
    double sy = sin(yaw * 0.5);

    Quaternion q;
    q.w = cr * cp * cy + sr * sp * sy;
    q.x = sr * cp * cy - cr * sp * sy;
    q.y = cr * sp * cy + sr * cp * sy;
    q.z = cr * cp * sy - sr * sp * cy;

    return q;
}
    
    
int main()
{

}
