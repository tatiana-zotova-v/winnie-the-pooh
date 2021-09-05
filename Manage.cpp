#include "Manage.h"

PID::PID(double kp, double ki, double kd, double Dt)
: Kp(kp),
  Ki(ki),
  Kd(kd),
  dt(Dt)
{
	P = 0;
	I = 0;
	D = 0;
}

double PID::calc_pid(double setpoint, double input){
	double prev_err = P;
	double err = input - setpoint;
	P = err;
	I += err * dt;
	D = (err - prev_err) / dt;
	double out = Kp * P + Ki * I + Kd * D;
	if (out > 100){
		out = 100;
	} else if (out < -100){
		out = -100;
	}
	return out;
}

Engine::Engine(double m, double m_p)
: massa(m)
, max_power(m_p){
	current_power = 0;
}

double Engine::get_m() const {
	return massa;
}

double Engine::get_p() const {
	return current_power;
}

double Engine::get_mp() const {
	return max_power;
}

void Engine::set_power(double percent_power) {
	current_power = percent_power;
}
