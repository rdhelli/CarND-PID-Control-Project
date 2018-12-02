#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  
}

void PID::UpdateError(double cte) {
  d_error = cte - p_error; // diff_cte = cte - prev_cte
  p_error = cte;
  i_error += cte; // sum of all cte
}

double PID::TotalError() {
  
}

