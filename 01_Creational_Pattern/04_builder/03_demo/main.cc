#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include "../../../lib/common.h"

class House final {
public:
	House() = default;
    ~House() = default;
	void setFloor(std::string floor) {
		_floor = floor;
	}
	void setWall(std::string wall) {
		_wall = wall;
	}
	void setRoof(std::string roof) {
		_roof = roof;
	}
	//打印House信息
	void printfHouseInfo() {
        std::cout << "Floor:\t" << _floor << std::endl;
        std::cout << "Wall:\t" << _wall << std::endl;
        std::cout << "Roof:\t" << _roof << std::endl;
	}
private:
	std::string _floor;
	std::string _wall;
	std::string _roof;
};

class Builder {
public:
    Builder() = default;
    virtual ~Builder() = default;
    virtual void reset() = 0; 
    virtual void buildFloor() = 0;
    virtual void buildWall() = 0;
    virtual void buildRoof() = 0;
    virtual std::unique_ptr<House> getHouse() = 0;
};


class HouseBuiler1 : public Builder {
public:
    HouseBuiler1() { this->reset(); }
    ~HouseBuiler1() = default;
    // reset（重置）方法可清除正在生成的对象。
    void reset() override {
        _house = make_unique<House>();
    }
    void buildFloor() override {
        _house->setFloor("Plan A floor");
    }
    void buildWall() override {
        _house->setWall("Plan A	wall");
    }   
    void buildRoof() override {
        _house->setRoof("Plan A roof");
    }
	std::unique_ptr<House> getHouse() {
		return std::move(_house);
	}
private:
    std::unique_ptr<House> _house;
};

class HouseBuiler2 : public Builder {
public:
    HouseBuiler2() { this->reset(); }
    ~HouseBuiler2() = default;

    // reset（重置）方法可清除正在生成的对象。
    void reset() override {
        _house = make_unique<House>();
    }
    void buildFloor() override {
        _house->setFloor("Plan B floor");
    }
    void buildWall() override {
        _house->setWall("Plan B	wall");
    }   
    void buildRoof() override {
        _house->setRoof("Plan B roof");
    }
	std::unique_ptr<House> getHouse() {
		return std::move(_house);
	}
private:
    std::unique_ptr<House> _house;
};

class Director final {
public:
	void setBuilder(std::unique_ptr<Builder> &builder) {
		_builder = std::move(builder);
	}
	std::unique_ptr<House> buildHouse() {
		if(_builder == nullptr) 
			throw std::runtime_error("No builder");
		_builder->buildFloor();
		_builder->buildWall();
		_builder->buildRoof();
		return _builder->getHouse();
	} 
    std::unique_ptr<House> buildHouseB() {
		if(_builder == nullptr) 
			throw std::runtime_error("No builder");
		_builder->buildFloor();
		_builder->buildWall();
		_builder->buildRoof();
		return _builder->getHouse();
	}

private:
	std::unique_ptr<Builder> _builder = nullptr;
};

int main() {
	// 抽象建造者
    std::unique_ptr<Builder> builder;
	// 指挥者
    std::unique_ptr<Director> director = make_unique<Director>();
    // 指定A方案建造
    builder = make_unique<HouseBuiler1>();
    director->setBuilder(builder);
    std::unique_ptr<House> houseA = director->buildHouse();
	houseA->printfHouseInfo();

    builder = make_unique<HouseBuiler2>();
    director->setBuilder(builder);
    std::unique_ptr<House> houseB = director->buildHouse();
    houseB->printfHouseInfo();
}