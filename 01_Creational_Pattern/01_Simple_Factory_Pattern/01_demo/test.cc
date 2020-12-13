/*
https://blog.csdn.net/sinat_21107433/article/details/102598181
*/

#include <iostream>
#include "SimpleFactory.h"
 
int main() {
	printf("简单工厂模式\n");
	
	//定义工厂类对象
	Factory fac;

	AbstractSportProduct *pBasketball = fac.getSportProduct("Basketball");

	if(pBasketball) {
		pBasketball->play();

		// new了一定要释放
		delete pBasketball;
		pBasketball = nullptr;
	}

	AbstractSportProduct *pFootball = fac.getSportProduct("Football");

	if(pFootball) {
		pFootball->play();

		// new了一定要释放
		delete pFootball;
		pFootball = nullptr;
	}


	AbstractSportProduct *pVolleyball = fac.getSportProduct("Volleyball");

	if(pVolleyball) {
		pVolleyball->play();

		// new了一定要释放
		delete pVolleyball;
		pVolleyball = nullptr;
	}
 
 
	// system("pause");
	return 0;
}