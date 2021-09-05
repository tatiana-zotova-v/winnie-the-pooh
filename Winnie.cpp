#include <iostream>
#include <cmath>
#include "Bears.h"

int main(){
	int cnt = 5000;
	double time = 0., dt = 0.01, bite_time = 10;
	bool is_eating = false;

	class SmartFlyingBear Pooh(10, new Engine(0.1, 500), new PID(60.0, 5.6363, 28.0, dt));

	float hollow_tree = 10;
//	std::cin << hollow_tree;

	Pooh.set_h(hollow_tree);

	bool jet;
	while (cnt){
		jet = Pooh.move(dt, Pooh.get_pwr());
		if (!jet){
			std::cout << "Do you want to take jetpack?" << std::endl
					  << "1 - yes" << std::endl
					  << "0 - no" << std::endl;
			int i = 0;
			std::cin >> i;
			if (i == 0){
				std::cout << "Now I can't get to the honey :(" << std::endl;
			} else if (i == 1){
				Pooh.take_jetpack();
			} else {
				std::cerr << "beda" << std::endl; //исправиьт на вброс исключения
			}
		}

		if (fabs(Pooh.geth() - hollow_tree) <= 1){
			if(!is_eating){
				is_eating = true;
				Pooh.eat(0.1);;
			} else {
				bite_time -= dt;
				if (bite_time <= 0) {
					is_eating = false;
					bite_time = 10;
				}
			}
		}
		cnt--;
		time += dt;
	}

	return 0;
}
