#include <iostream>
#include "FactoryMethod.h"
 
int main() {
	printf("工厂方法模式\n");
	
    AbstractFactory *pBasketballFac = new BasketballFactory();
    AbstractSportProduct *pBasketball = pBasketballFac->getSportProduct();

    pBasketball->play();

    delete pBasketballFac;
    pBasketballFac = nullptr;
    delete pBasketball;
    pBasketball = nullptr;

    // 其他略
	return 0;
}