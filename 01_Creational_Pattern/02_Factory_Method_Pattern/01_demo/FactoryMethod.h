#ifndef FACTORYMETHOD_H 
#define FACTORYMETHOD_H 
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

// 定义抽象工厂类AbstractFactory，方法为纯虚方法
//抽象工厂类
class AbstractFactory {
public:
    virtual ~AbstractFactory() {}
	virtual AbstractSportProduct *getSportProduct() = 0;
};

// 定义三个具体工厂类
//具体工厂类BasketballFactory
class BasketballFactory : public AbstractFactory {
public:
	BasketballFactory() {
		std::cout << "BasketballFactory construct" << std::endl;
	}
	AbstractSportProduct *getSportProduct() {
        std::cout << "basketball" << std::endl;
		return new Basketball();
	}
};
 
//具体工厂类FootballFactory
class FootballFactory : public AbstractFactory {
public:
	FootballFactory(){
		std::cout << "FootballFactory construct" << std::endl;
	}
	AbstractSportProduct *getSportProduct(){
        std::cout << "Football" << std::endl;
		return new Football();
	}
};
 
//具体工厂类VolleyballFactory
class VolleyballFactory :public AbstractFactory
{
public:
	VolleyballFactory(){
		std::cout << "VolleyballFactory construct" << std::endl;
	}
	AbstractSportProduct *getSportProduct(){
        std::cout << "VolleyballF" << std::endl;
		return new Volleyball();
	}
};








#endif	// FACTORYMETHOD_H