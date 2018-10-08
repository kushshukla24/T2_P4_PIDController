#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double iKp, double iKi, double iKd) {
	Kp = iKp;
	Ki = iKi;
	Kd = iKd;
	last_cte = 0;
	sum_cte = 0;
}

void PID::UpdateError(double cte) {
	sum_cte += cte;
	p_error = -Kp * cte;
	i_error = -Ki * sum_cte;
	d_error = -Kd * (cte- last_cte);
	last_cte = cte;
}

double PID::TotalError() {
	double totalError = p_error + i_error + d_error;
	return totalError;
}
