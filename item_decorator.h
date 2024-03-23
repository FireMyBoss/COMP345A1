#ifndef ITEM_DECORATOR_H
#define ITEM_DECORATOR_H

#include <string>
#include <vector>
#include "allcharacters.h"

class ItemDecorator : public Character {
protected:
    Character *character;
    std::vector<std::string> *givenItems;
    std::vector<std::string> *givenBonuses;
public:
    ItemDecorator();
    ItemDecorator(Character *character);
    virtual ~ItemDecorator();
    virtual std::string getCharacterClass();
    virtual void setItems(std::string item);
    virtual void setBonuses(std::string bonus);
    void displayItems();
    virtual void remove(const std::string& itemToRemove);
};

class withHelmet : public ItemDecorator {
public:
    string listOfEnchantmentshelmet[3];
    string bonus;
    withHelmet(Character *character);
    virtual void remove();
};

class withArmor : public ItemDecorator {
public:
    string listOfEnchantmentshelmet[1];
    string bonus;
    withArmor(Character *character);
    virtual void remove();
};

class withBelt : public ItemDecorator {
public:
    string listOfEnchantmentshelmet[2];
    string bonus;
    withBelt(Character *character);
    virtual void remove();
};

class withBoots : public ItemDecorator {
public:
    string listOfEnchantmentshelmet[2];
    string bonus;
    withBoots(Character *character);
    virtual void remove();
};

class withRing : public ItemDecorator {
public:
    string listOfEnchantmentshelmet[5];
    string bonus;
    withRing(Character *character);
    virtual void remove();
};

class withSheild : public ItemDecorator {
public:
    string listOfEnchantmentshelmet[1];
    string bonus;
    withSheild(Character *character);
    virtual void remove();
};

class withWeapon : public ItemDecorator {
public:
    string listOfEnchantmentshelmet[2];
    string bonus;
    withWeapon(Character *character);
    virtual void remove();
};

#endif // ITEM_DECORATOR_H