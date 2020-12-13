#include <memory>
#include "make_unique.h"

class Door {
public:
    virtual ~Door() = default;
};

class Window {
public:
    virtual ~Window() = default;
};

class House {
public:
    virtual void SetDoor(const Door&) {}
    virtual void SetWindow(const Window&) {}
    virtual ~House() = default;
};


class BaseFactor {
public:
    virtual std::unique_ptr<Door> MakeDoor() const { 
        return make_unique<Door>(); 
    }

    virtual std::unique_ptr<Window> MakeWindow() const {
        return make_unique<Window>();
    }

    virtual std::unique_ptr<House> MakeHouse() const {
        return make_unique<House>();
    }

    std::unique_ptr<House> CreateHouse() {
        std::unique_ptr<Door> door = MakeDoor();
        std::unique_ptr<Window> window = MakeWindow();
        std::unique_ptr<House> house = MakeHouse();
        house->SetDoor(*door);
        house->SetWindow(*window);
        return house;
    }

    virtual ~BaseFactor() = default;
};


class WoodHouse : public House {};
class WoodDoor : public Door {};
class WoodWindow : public Window {};

class Factor : public BaseFactor {
public:
    std::unique_ptr<House> MakeHouse() const override {
        return make_unique<WoodHouse>();
    }

    std::unique_ptr<Door> MakeDoor() const override {
        return make_unique<WoodDoor>();
    }

    std::unique_ptr<Window> MakeWindow() const override {
        return make_unique<WoodWindow>();
    }
};

int main() {
    Factor fac;
    std::unique_ptr<House> house = fac.CreateHouse();
}