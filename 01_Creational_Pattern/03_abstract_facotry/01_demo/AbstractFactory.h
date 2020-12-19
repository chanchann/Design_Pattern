#ifndef ABSTRACTFACTORY_H 
#define ABSTRACTFACTORY_H 
/**
 * TODO Test未完
 */
#include <iostream>
#include <string>
#include <memory>
#include "make_unique.h"

//抽象产品类AbstractBall
class AbstractBall {
public:
    AbstractBall() {
        std::cout << "Create AbstractBall " << std::endl;
    }
	virtual ~AbstractBall() = default;
	//抽象方法：
	virtual void play() const = 0;
};

//具体产品类Basketball
class Basketball : public AbstractBall {
public:
	//具体实现方法
	void play() const override {
		std::cout << "Jungle play Basketball" << std::endl;
	}
};

//具体产品类Football
class Football : public AbstractBall {
public:
	//具体实现方法
	void play() const override {
		std::cout << "Jungle play Football" << std::endl;
	}
};

//抽象产品类AbstractShirt
class AbstractShirt {
public:
	virtual ~AbstractShirt() = default;
	//抽象方法：
	virtual void wearShirt() const = 0;

    // The Abstract Factory makes sure that all products it creates are of the
    // same variant and thus, compatible.
    virtual void playBall(const AbstractBall& collaborator) const = 0;
};

//具体产品类BasketballShirt
class BasketballShirt : public AbstractShirt {
public:
	//具体实现方法
	void wearShirt() const override {
		std::cout << "Jungle wear Basketball Shirt" << std::endl;
	}
    void playBall(const AbstractBall& collaborator) const override {
        collaborator.play();
    }
};

//具体产品类FootballShirt
class FootballShirt :public AbstractShirt {
public:
    void wearShirt() const override {
		std::cout << "Jungle wear Football Shirt" << std::endl;
	}
    void playBall(const AbstractBall& collaborator) const override {
        collaborator.play();
    }
};

//抽象工厂类
class AbstractFactory {
public:
    virtual std::unique_ptr<AbstractBall> createBall() const = 0;
    virtual std::unique_ptr<AbstractShirt> createShirt() const = 0;
};

//具体工厂类BasketballFactory
class BasketballFactory :public AbstractFactory {
public:
    std::unique_ptr<AbstractBall> createBall() const override {
        return make_unique<Basketball>();
    }
    std::unique_ptr<AbstractShirt> createShirt() const override {
        return make_unique<BasketballShirt>();
    }
};

//具体工厂类BasketballFactory
class FootballFactory :public AbstractFactory {
public:
    std::unique_ptr<AbstractBall> createBall() const override {
        return make_unique<Football>();
    }
    std::unique_ptr<AbstractShirt> createShirt() const override {
        return make_unique<FootballShirt>();
    }
};




#endif	// ABSTRACTFACTORY_H