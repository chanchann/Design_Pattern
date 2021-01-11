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



class Adapter :public Controller {
public:
    Adapter() = default;
	Adapter(std::unique_ptr<DxfParser> dxfParser, 
            std::unique_ptr<PathPlanner> pathPlanner):
            _dxfParser(std::move(dxfParser)), _pathPlanner(std::move(pathPlanner))
        {}
	void pathPlanning(){
        std::cout << "路径规划：" << std::endl;
		_dxfParser->parseFile();
		_pathPlanner->calculate();
	}
private:
    std::unique_ptr<DxfParser> _dxfParser = make_unique<DxfParser>();
    std::unique_ptr<PathPlanner> _pathPlanner = make_unique<PathPlanner>();
};

int main() {
	std::unique_ptr<Controller> controller = make_unique<Adapter>();
    controller->pathPlanning();
 
	return 0;
}