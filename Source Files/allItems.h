#ifndef allItems_H
#define allItems_H

#include <iostream>
#include <string>

class Equipment {
protected:
    std::string enchantmentType;

public:
    virtual void displayInfo();
};

class Helmet : public Equipment {
public:
    void displayInfo() override;
};

class Armor : public Equipment {
public:
    void displayInfo() override;
};

class Shield : public Equipment {
public:
    void displayInfo() override;
};

class Ring : public Equipment {
public:
    void displayInfo() override;
};

class Belt : public Equipment {
public:
    void displayInfo() override;
};

class Boots : public Equipment {
public:
    void displayInfo() override;
};

class Weapon : public Equipment {
public:
    void displayInfo() override;
};

#endif // allItems_H
