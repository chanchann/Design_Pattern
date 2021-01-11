#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include "../../../lib/common.h"

class Controller {
public:
	Controller() = default;
    virtual ~Controller() = default;
	virtual void pathPlanning() = 0;
};

// adaptee1
class DxfParser {
public:
	DxfParser() = default;
    virtual ~DxfParser() = default;
	void parseFile() {
        std::cout << "解析文件提取数据" << std::endl;
	}
};
 
// adaptee2
class PathPlanner {
public:
	PathPlanner() = default;
    ~PathPlanner() = default;
	void calculate() {
        std::cout << "计算加工路径" << std::endl;
	}
};



class Adapter :public Controller, public DxfParser, public PathPlanner {
public:
    Adapter() = default;

	void pathPlanning(){
        std::cout << "路径规划：" << std::endl;
		parseFile();
		calculate();
	}
};

int main() {
	std::unique_ptr<Controller> controller = make_unique<Adapter>();
    controller->pathPlanning();
 
	return 0;
}