#include <iostream>
#include "AbstractFactory.h"

int main() {
    std::unique_ptr<AbstractFactory> fac;
    std::unique_ptr<AbstractBall> ball;
    std::unique_ptr<AbstractShirt> shirt;
    fac = make_unique<BasketballFactory>();

    ball = fac->createBall();
    
	shirt = fac->createShirt();


	// fac = new FootballFactory();
	// ball = fac->getBall();
	// shirt = fac->getShirt();
	// delete fac;
	// delete ball;
	// delete shirt;

	// system("pause");
	return 0;
}
