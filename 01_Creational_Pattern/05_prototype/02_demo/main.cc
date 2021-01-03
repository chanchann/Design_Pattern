/*
这个例子还存在一些问题
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include "../../../lib/common.h"

//work model类
class WorkModel {
public:
    WorkModel() = default;
    explicit WorkModel(const std::string& modelName) : _modelName(modelName) {}
	void setWorkModelName(const std::string& modelName){
		_modelName = modelName;
	}
    const std::string& getWorkModelName() const { return _modelName; }
private:
    std::string _modelName;
};

//抽象原型类PrototypeWork
class PrototypeWork {
public:
	PrototypeWork() = default;
    virtual ~PrototypeWork() = default;
	virtual std::unique_ptr<PrototypeWork> clone() = 0;
};
 
//具体原型类ConcreteWork
class ConcreteWork :public PrototypeWork {
public:
	ConcreteWork() = default;
	ConcreteWork(const std::string& name, int idNum, const std::string& modelName) :
                _name(name), _idNum(idNum),
                _workModel(std::make_shared<WorkModel>(modelName))  
            {}

    std::unique_ptr<PrototypeWork> clone() override {
        return make_unique<ConcreteWork>(*this);
        // return make_unique<ConcreteWork>(_name, _idNum, _workModel->getWorkModelName());
    }

 	void setName(std::string name) {
		_name = name;
	}
	void setIdNum(int idNum){
		_idNum = idNum;
	}
    void setModel(std::shared_ptr<WorkModel> workModel){
		_workModel = workModel;
	}
	void printWorkInfo() {
        std::cout << "name : " << _name << std::endl;
        std::cout << "idNum : " << _idNum << std::endl;
        std::cout << "modelName : " << _workModel->getWorkModelName() << std::endl;
	}
private:
	std::string _name;
	int _idNum;
    std::shared_ptr<WorkModel> _workModel; // aggregation
};

void shallowCopy() {
    std::shared_ptr<ConcreteWork> singleWork = std::make_shared<ConcreteWork>("Single", 1001, "Single_Model");
    std::cout << "Single的作业：" << std::endl;
	singleWork->printWorkInfo();
	
    std::cout << "jungle直接抄作业……" << std::endl;
    std::shared_ptr<ConcreteWork> jungleWork = singleWork;
    std::cout << "Jungle的作业: " << std::endl;
    jungleWork->printWorkInfo();
 
	// 抄完改名字和学号，否则会被老师查出来
    std::cout << "jungle抄完改名字和学号，否则会被老师查出来…… " << std::endl;
	jungleWork->setName("jungle");
	jungleWork->setIdNum(1002);
    std::shared_ptr<WorkModel> jungleModel = std::make_shared<WorkModel>("Jungle_Model");
	jungleWork->setModel(jungleModel);
	
	//检查下是否改对了
    std::cout << "Single的作业: " << std::endl;
	singleWork->printWorkInfo();
    std::cout << "Jungle的作业: " << std::endl;
	jungleWork->printWorkInfo();
    // 浅拷贝导致Single的作业也被改变了
    // 因为指向的是同一片地址

}

void deepCopy() {
    std::unique_ptr<ConcreteWork> singleWork = make_unique<ConcreteWork>("Single", 1001, "Single_Model");
    std::cout << "Single的作业：" << std::endl;
	singleWork->printWorkInfo();

    std::cout << "jungle直接抄作业……" << std::endl;
    std::unique_ptr<PrototypeWork> jungle_clone = singleWork->clone();
    std::cout << "Jungle的作业：" << std::endl;
    // downcast 成继承类指针
    auto jungleWork = std::unique_ptr<ConcreteWork>(static_cast<ConcreteWork *>(jungle_clone.release()));;
    jungleWork->printWorkInfo();
 
	//抄完改名字和学号，否则会被老师查出来
    std::cout << "jungle抄完改名字和学号，否则会被老师查出来…… " << std::endl;
	jungleWork->setName("jungle");
	jungleWork->setIdNum(1002);
    std::shared_ptr<WorkModel> jungleModel = std::make_shared<WorkModel>("Jungle_Model");
	jungleWork->setModel(jungleModel);
	
	//检查下是否改对了
    std::cout << "Single的作业: " << std::endl;
	singleWork->printWorkInfo();
    std::cout << "Jungle的作业: " << std::endl;
	jungleWork->printWorkInfo();

}
int main() {
    shallowCopy();
    deepCopy();
}