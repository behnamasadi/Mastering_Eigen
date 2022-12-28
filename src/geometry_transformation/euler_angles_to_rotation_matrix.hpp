#include <iostream>
#include <Eigen/Dense>

Eigen::Matrix3d eulerAnglesToRotationMatrix(double roll, double pitch,double yaw)
{
    Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitX());
    Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitY());
    Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitZ());
    Eigen::Quaternion<double> q = yawAngle * pitchAngle * rollAngle;
    Eigen::Matrix3d rotationMatrix = q.matrix();
    return rotationMatrix;
}




