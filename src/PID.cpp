#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  p_error = 0.0;
  i_error = 0.0;
  d_error = 0.0;
  PID::Kp = Kp;
  PID::Ki = Ki;
  PID::Kd = Kd;
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error; // diff_cte = cte - prev_cte
  p_error = cte;
  i_error += cte; // sum of all cte
  if (i_error >= 300*p_error) { // integrator saturation prevention
    i_error = 0;
  }
}

double PID::TotalError() {
  double control_value = - (Kp * p_error) - (Ki * i_error) - (Kd * d_error);
  return control_value;
}

