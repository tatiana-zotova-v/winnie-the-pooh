#include <iostream>
#include "Manage.h"

extern double g;

class Bear {
public:
	Bear(double massa);
	double getM() const;
	double geth() const;
	virtual void eat(double honey_pot);
	virtual void take_jetpack();
	virtual bool move(double dt, double jetpack_pow);
protected:
	double m;
	double h;
};

class SmartFlyingBear : public Bear {
public:
	SmartFlyingBear(double massa, Engine* engine, PID* pid);
	void eat(double honey_pot) override;
	void set_h(double H);
	void take_jetpack() override;
	bool move(double dt, double jetpack_pow) override;
	double get_pwr();
private:
	PID* controller;
	Engine *jetpack;
	double task_h;
	double v;
	double a;
	bool jp;
};
