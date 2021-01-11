#include <iostream>
#include <memory>
#include "../../../lib/common.h"
class Game {
public:
	Game() = default;
	virtual void play() = 0;
};

class GameA:public Game {
public:
	GameA() = default;
	void play() override {
        std::cout << " Play game A " << std::endl;
	}
};
 
class GameB :public Game {
public:
	GameB() = default;
	void play() override {
        std::cout << " Play game B " << std::endl;
	}
};

// Abstraction
class Phone {
public:
	Phone() = default;
	//安装游戏
	virtual void setupGame(std::unique_ptr<Game> game) = 0;
	virtual void play() = 0;
protected:
    std::unique_ptr<Game> _game;
};

class PhoneA:public Phone {
public:
	PhoneA() = default;
	//安装游戏
	virtual void setupGame(std::unique_ptr<Game> game) override {
        _game = std::move(game);
	}
	void play() override {
		_game->play();
	}
};
 
//扩充抽象类PhoneB
class PhoneB :public Phone{
public:
	PhoneB() = default;
	//安装游戏
	virtual void setupGame(std::unique_ptr<Game> game) override{
		_game = std::move(game);
	}
	void play() override {
		_game->play();
	}
};

int main() {
    std::unique_ptr<Phone> phoneA = make_unique<PhoneA>();
	// 买了PhoneA品牌的手机，想玩游戏A
	phoneA->setupGame(make_unique<GameA>());
	phoneA->play();
	printf("++++++++++++++++++++++++++++++++++\n");
 
	// 想在这个手机上玩游戏B
	phoneA->setupGame(make_unique<GameB>());
	phoneA->play();
 

	return 0;
}