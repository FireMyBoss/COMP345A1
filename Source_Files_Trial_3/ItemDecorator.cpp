#include <string>
#include <vector>
#include <iostream>
#include "allcharacters.h"
#include "item_decorator.h"

using namespace std;



ItemDecorator::ItemDecorator() : character(nullptr), givenItems(new std::vector<string>()), givenBonuses(new std::vector<string>()) {}

ItemDecorator::ItemDecorator(Character *character) : character(character), givenItems(new std::vector<string>()), givenBonuses(new std::vector<string>()) {}

ItemDecorator::~ItemDecorator() {
    delete character;
    delete givenItems;
    delete givenBonuses;
}

string ItemDecorator::getCharacterClass() {
    return character->getCharacterClass();
}

void ItemDecorator::setItems(string item) {
    auto it = std::find(givenItems->begin(), givenItems->end(), item);
    if (it == givenItems->end()) {
        givenItems->push_back(item);
    }
}

void ItemDecorator::setBonuses(string bonus) {
    givenBonuses->push_back(bonus);
}

void ItemDecorator::displayItems() {
    std::cout << "Items: ";
    for (const auto& item : *givenItems) {
        std::cout << item << " ";
    }
    std::cout << std::endl;
}

void ItemDecorator::remove(const std::string& itemToRemove) {
    for (auto it = givenItems->begin(); it != givenItems->end(); ++it) {
        if (*it == itemToRemove) {
            givenItems->erase(it);
            return;
        }
    }
}

withHelmet::withHelmet(Character *character) : ItemDecorator(character) {
    setItems("helmet");
    string listOfEnchantmentshelmet[3] = {"Intelligence", "Wisdom", "Armor class"};
    string bonus = listOfEnchantmentshelmet[getCurrentTime() % 3];
    setBonuses(bonus);
}

void withHelmet::remove() {
    ItemDecorator::remove("helmet");
    auto it = std::find(givenBonuses->begin(), givenBonuses->end(), this-> bonus);
    if (it != givenBonuses->end()) {
        givenBonuses->erase(it);
    }
}

withArmor::withArmor(Character *character) : ItemDecorator(character) {
    setItems("armor");
    string listOfEnchantmentsArmor[1] = {"Armor class"};
    string bonus = listOfEnchantmentsArmor[0];
    setBonuses(bonus);
}

void withArmor::remove() {
    ItemDecorator::remove("armor");
    auto it = std::find(givenBonuses->begin(), givenBonuses->end(), this-> bonus);
    if (it != givenBonuses->end()) {
        givenBonuses->erase(it);
    }
}

withBelt::withBelt(Character *character) : ItemDecorator(character) {
    setItems("belt");
    string listOfEnchantmentsBelt[2] = {"Constitution", "Strength"};
    string bonus = listOfEnchantmentsBelt[getCurrentTime() % 2];
    setBonuses(bonus);
}

void withBelt::remove() {
    ItemDecorator::remove("belt");
    auto it = std::find(givenBonuses->begin(), givenBonuses->end(), this-> bonus);
    if (it != givenBonuses->end()) {
        givenBonuses->erase(it);
    }
}

withBoots::withBoots(Character *character) : ItemDecorator(character) {
    setItems("boots");
    string listOfEnchantmentsBoots[2] = {"Armor class", "Dexterity"};
    string bonus = listOfEnchantmentsBoots[getCurrentTime() % 2];
    setBonuses(bonus);
}

void withBoots::remove() {
    ItemDecorator::remove("boots");
    auto it = std::find(givenBonuses->begin(), givenBonuses->end(), this-> bonus);
    if (it != givenBonuses->end()) {
        givenBonuses->erase(it);
    }
}

withRing::withRing(Character *character) : ItemDecorator(character) {
    setItems("ring");
    string listOfEnchantmentsRing[5] = {"Armor class", "Strength", "Constitution", "Wisdom", "Charisma"};
    string bonus = listOfEnchantmentsRing[getCurrentTime() % 5];
    setBonuses(bonus);
}

void withRing::remove() {
    ItemDecorator::remove("ring");
    auto it = std::find(givenBonuses->begin(), givenBonuses->end(), this-> bonus);
    if (it != givenBonuses->end()) {
        givenBonuses->erase(it);
    }
}

withSheild::withSheild(Character *character) : ItemDecorator(character) {
    setItems("sheild");
    string listOfEnchantmentsSheild[1] = {"Armor class"};
    string bonus = listOfEnchantmentsSheild[0];
    setBonuses(bonus);
}

void withSheild::remove() {
    ItemDecorator::remove("sheild");
    auto it = std::find(givenBonuses->begin(), givenBonuses->end(), this-> bonus);
    if (it != givenBonuses->end()) {
        givenBonuses->erase(it);
    }
}

withWeapon::withWeapon(Character *character) : ItemDecorator(character) {
    setItems("weapon");
    string listOfEnchantmentsWeapon[2] = {"Attack bonus", "Damage bonus"};
    string bonus = listOfEnchantmentsWeapon[getCurrentTime() % 2];
    setBonuses(bonus);
}

void withWeapon::remove() {
    ItemDecorator::remove("weapon");
    auto it = std::find(givenBonuses->begin(), givenBonuses->end(), this-> bonus);
    if (it != givenBonuses->end()) {
        givenBonuses->erase(it);
    }
}
