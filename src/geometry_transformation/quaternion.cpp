#include <Eigen/Dense>
#include <iostream>

// very good refrence:
// https://danceswithcode.net/engineeringnotes/quaternions/quaternions.html

Eigen::Matrix3d eulerAnglesToRotationMatrix(double roll, double pitch,
                                            double yaw) {
  Eigen::AngleAxisd rollAngle(roll, Eigen::Vector3d::UnitX());
  Eigen::AngleAxisd pitchAngle(pitch, Eigen::Vector3d::UnitY());
  Eigen::AngleAxisd yawAngle(yaw, Eigen::Vector3d::UnitZ());
  Eigen::Quaternion<double> q = yawAngle * pitchAngle * rollAngle;
  Eigen::Matrix3d rotationMatrix = q.matrix();
  return rotationMatrix;
}

void quaternionFromRollPitchYaw() {

  //////////////// rotation matrix to quaternion   ////////////////

  double roll, pitch, yaw;

  roll = M_PI / 4;
  pitch = M_PI / 3;
  yaw = M_PI / 6;

  Eigen::Matrix3d rotationMatrix =
      eulerAnglesToRotationMatrix(roll, pitch, yaw);

  Eigen::Quaterniond quaternionFromRotationMatrix(rotationMatrix);

  std::cout << "Quaternion X: " << quaternionFromRotationMatrix.x()
            << std::endl;
  std::cout << "Quaternion Y: " << quaternionFromRotationMatrix.y()
            << std::endl;
  std::cout << "Quaternion Z: " << quaternionFromRotationMatrix.z()
            << std::endl;
  std::cout << "Quaternion W: " << quaternionFromRotationMatrix.w()
            << std::endl;

  //  // Rotation Matrix to Euler Angle (Proper)
  //  Eigen::Vector3d euler_angles = rotationMatrix.eulerAngles(2, 0, 2);

  //  // Eigen::Quaterniond
  //  Eigen::Quaterniond tmp =
  //      Eigen::AngleAxisd(euler_angles[0], Eigen::Vector3d::UnitZ()) *
  //      Eigen::AngleAxisd(euler_angles[1], Eigen::Vector3d::UnitX()) *
  //      Eigen::AngleAxisd(euler_angles[2], Eigen::Vector3d::UnitZ());

  //  Eigen::Quaternion<double> q = yawAngle * pitchAngle * rollAngle;

  //////////////// Quaternion to Rotation Matrix ////////////////
  Eigen::Matrix3d rotationMatrixFromQuaternion =
      quaternionFromRotationMatrix.matrix();
  std::cout << "3x3 Rotation Matrix\n"
            << rotationMatrixFromQuaternion << std::endl;
}

struct Quaternion {
  double w, x, y, z;
};

struct Point {
  double x, y, z;
};

Quaternion quaternionMultiplication(Quaternion r, Quaternion s) {
  //(t0, t1, t2, t3) = (r0, r1, r2, r3) ✕ (s0, s1, s2, s3)

  Quaternion t;

  // t0 = (r0s0 − r1s1 − r2s2 − r3s3)
  t.w = r.w * s.w - r.x * s.x - r.y * s.y - r.z * s.z;

  // t1 = (r0s1 + r1s0 − r2s3 + r3s2)
  t.x = r.w * s.x + r.y * s.x - r.y * s.z + r.z * s.y;

  // t2 = (r0s2 + r1s3 + r2s0 − r3s1)
  t.y = r.w * s.y + r.x * s.z + r.y * s.w - r.z * s.x;

  // t3 = (r0s3 − r1s2 + r2s1 + r3s0)
  t.z = r.w * s.z - r.x * s.y + r.y * s.x + r.z * s.w;

  return t;
}

Quaternion quaternionInversion(Quaternion q) {
  // The inverse of a quaternion is obtained by negating the imaginary
  // components:

  q.x = -q.x;
  q.y = -q.y;
  q.z = -q.z;
  return q;
}

Point QuaternionRotation(Quaternion q, Point p) {
  // Step 1:Convert the point to be rotated into a quaternion
  // p = (p0, p1, p2, p3) = ( 0, x, y, z )
  Quaternion tmp;
  tmp.w = 0;
  tmp.x = p.x;
  tmp.y = p.y;
  tmp.z = p.z;

  // Step 2: Perform active rotation: when the point is rotated with respect to
  // the coordinate system p' = q−1 pq
  Quaternion p_prime = quaternionMultiplication(
      quaternionMultiplication(quaternionInversion(q), tmp), q);

  // Perform passive rotation: when the coordinate system is rotated with
  // respect to the point. The two rotations are opposite from each other. p' =
  // qpq−1

  //  p_prime = quaternionMultiplication(quaternionMultiplication(q, tmp),
  //                                     quaternionInversion(q));

  // Step 3: Extract the rotated coordinates from p':
  Point rotate_d_p;
  rotate_d_p.x = p_prime.x;
  rotate_d_p.y = p_prime.y;
  rotate_d_p.z = p_prime.z;

  return rotate_d_p;
}

Quaternion rollPitchYawToQuaternion(double roll, double pitch,
                                    double yaw) // roll (x), pitch (Y), yaw (z)
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

void convertAxisAngleToQuaternion() {}

void ConvertQuaterniontoAxisAngle() {}

void rotatingAPointUsingQuaternions() { Quaternion q1, q2; }

int main() {

  double roll, pitch, yaw;

  roll = M_PI / 4;
  pitch = M_PI / 3;
  yaw = M_PI / 6;

  Eigen::Matrix3d rotationMatrix =
      eulerAnglesToRotationMatrix(roll, pitch, yaw);

  Eigen::Quaterniond quaternionFromRotationMatrix(rotationMatrix);

  Eigen::Matrix3d R_b_c, R_s_b;

  R_b_c << 0, 0, -1, 0, 1, 0, 1, 0, 0;

  std::cout << "R_b_c\n" << R_b_c << std::endl;

  R_s_b << 0, -1, 0, 1, 0, 0, 0, 0, 1;

  std::cout << "R_s_b\n" << R_s_b << std::endl;

  Eigen::Matrix3d R_s_c = R_s_b * R_b_c;

  std::cout << "R_s_c\n" << R_s_c << std::endl;

  Eigen::Vector3d p_b;
  p_b << -1, 0, 0;

  Eigen::Vector3d p_s = R_s_b * p_b;

  std::cout << p_s << std::endl;
}
