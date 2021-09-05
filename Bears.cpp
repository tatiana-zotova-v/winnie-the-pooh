#include "Bears.h"

double g = 9.8;

Bear::Bear(double massa)
: m(massa)
, h(0){}

double Bear::getM() const {
	return m;
}

double Bear::geth() const {
	return h;
}

void Bear::eat(double honey_pot) {
	std::cout << "Honey is too high, I can't reach it..." << std::endl;
}

void Bear::take_jetpack(){
	std::cout << "I don't have any jetpacks, I'm just a usual bear..." << std::endl;
}

bool Bear::move(double dt, double jetpack_pow){
	std::cout << "This is very high for me. I'm not a SmartFlyingBear." << std::endl;
}

SmartFlyingBear::SmartFlyingBear(double massa, Engine* engine, PID* pid)
: Bear(massa)
, controller(pid)
, jetpack(engine)
, task_h(0)
, v(0)
, a(0)
, jp(false){}

void SmartFlyingBear::eat(double honey_pot){
	m += honey_pot + honey_pot / 10; //толстеет а что
	std::cout << "Omnomnom..." << std::endl;
}

void SmartFlyingBear::set_h(double H){
	task_h = H;
}

bool SmartFlyingBear::move(double dt, double jetpack_pwr){
	if (jp == false) {
		std::cout << "Do you think I should climb that high myself?... "
					 "It's too much! And for what, if i can fly?.." << std::endl;
	} else {
		if (controller != nullptr && jetpack != nullptr){
			jetpack->set_power(-(controller->calc_pid(h, task_h) * jetpack->get_mp() * 0.01));
			v += a * dt;
			h += v * dt;
			///////////////// отладочный момент ///////////////////
//			std::cout << h << std::endl;
			//////////////////////////////////////////////////////
			a = (m * g - jetpack_pwr) / m;

			if (h < 0){
				h = 0.;
				v = 0.;
				a = 0.;
			}
		} else {
			std::cerr << "beda"; //исправить на вброс исключения
		}
	}
	return jp;
}

void SmartFlyingBear::take_jetpack(){
	if(jp == false){
		m += jetpack->get_m();
		jp = true;
		std::cout << "Ohh, the jetpack is too heavy.. "
					 "but by the way it's better than crawling by myself" << std::endl;
	} else {
		std::cout << "No, two jetpacks is too much. "
					 "I'd like to eat some honey better than that" << std::endl;
	}
}

double SmartFlyingBear::get_pwr(){
	return jetpack->get_p();
}
