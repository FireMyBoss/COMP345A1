#include <iostream>
#include <string>
#include "allItems.h"

class Equipment {
protected:
    std::string enchantmentType;

public:
    virtual void displayInfo() = 0;
};

class Helmet : public Equipment {
public:
    void displayInfo() override {
        std::cout << "Helmet: " << enchantmentType << std::endl;
    }
};

class Armor : public Equipment {
public:
    void displayInfo() override {
        std::cout << "Armor: " << enchantmentType << std::endl;
    }
};

class Shield : public Equipment {
public:
    void displayInfo() override {
        std::cout << "Shield: " << enchantmentType << std::endl;
    }
};

class Ring : public Equipment {
public:
    void displayInfo() override {
        std::cout << "Ring: " << enchantmentType << std::endl;
    }
};

class Belt : public Equipment {
public:
    void displayInfo() override {
        std::cout << "Belt: " << enchantmentType << std::endl;
    }
};

class Boots : public Equipment {
public:
    void displayInfo() override {
        std::cout << "Boots: " << enchantmentType << std::endl;
    }
};

class Weapon : public Equipment {
public:
    void displayInfo() override {
        std::cout << "Weapon: " << enchantmentType << std::endl;
    }
};

int main() {
    // Example usage:
    Helmet helmet;
    helmet.displayInfo();

    Armor armor;
    armor.displayInfo();

    Shield shield;
    shield.displayInfo();

    Ring ring;
    ring.displayInfo();

    Belt belt;
    belt.displayInfo();

    Boots boots;
    boots.displayInfo();

    Weapon weapon;
    weapon.displayInfo();

    return 0;
}
