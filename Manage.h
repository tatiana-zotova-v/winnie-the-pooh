#include <iostream>
#ifndef MANAGE_H_
#define MANAGE_H_

class PID {
private:
	double Kp, Ki, Kd;
	double P, I, D;
	double dt;
public:
	PID(double kp, double ki, double kd, double Dt);
	double calc_pid(double setpoint, double input);
};

class Engine{
public:
	Engine(double m, double m_p);
	double get_m() const;
	double get_p() const;
	double get_mp() const;
	void set_power(double percent_power);
private:
	double massa;
	double max_power;
	double current_power;
};

#endif /* MANAGE_H_ */
