#ifndef SIMPLEFACTORY_H 
#define SIMPLEFACTORY_H 

#include <iostream>
#include <string>

// first step
// 定义抽象产品类AbstractProduct，抽象方法不提供实现
class AbstractSportProduct {
public:
	AbstractSportProduct() { }
	virtual ~AbstractSportProduct() { }  // 必须得有virtual析构
	//抽象方法：
	virtual void play() = 0;
};

// second step 
// 定义三个具体产品类

//具体产品类Basketball
class Basketball : public AbstractSportProduct {
public:
	//具体实现方法
	void play() {
		std::cout << "Jungle play Basketball" << std::endl;
	}
};
 
//具体产品类Football
class Football : public AbstractSportProduct {
public:
	//具体实现方法
	void play(){
		std::cout << "Jungle play Football" << std::endl;
	}
};
 
//具体产品类Volleyball
class Volleyball : public AbstractSportProduct {
public:
	//具体实现方法
	void play(){
		std::cout << "Jungle play Volleyball" << std::endl;
	}
};

// 3rd : 定义工厂类和工厂方法
class Factory {
public:
	AbstractSportProduct *getSportProduct(std::string productName) {
		AbstractSportProduct *pro = NULL;
		if (productName == "Basketball"){
			pro = new Basketball();
		}
		else if (productName == "Football"){
			pro = new Football();
		}
		else if (productName == "Volleyball"){
			pro = new Volleyball();
		}
		return pro;
	}
};

#endif	// SIMPLEFACTORY_H
