#include <Eigen/Dense>
#include <iostream>

Eigen::Matrix3d eulerAnglesToRotationMatrix(double roll, double pitch,
                                            double yaw) {
  Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitX());
  Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitY());
  Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitZ());
  Eigen::Quaternion<double> q = yawAngle * pitchAngle * rollAngle;
  Eigen::Matrix3d rotationMatrix = q.matrix();
  return rotationMatrix;
}

int main()
{


    double roll, pitch, yaw;

    roll = M_PI / 4;
    pitch = M_PI / 3;
    yaw = M_PI / 6;

    Eigen::Matrix3d rotationMatrix =
        eulerAnglesToRotationMatrix(roll, pitch, yaw);


    // Rotation Matrix to Euler Angle (Proper)
    Eigen::Vector3d euler_angles = rotationMatrix.eulerAngles(2, 0, 2);

}
