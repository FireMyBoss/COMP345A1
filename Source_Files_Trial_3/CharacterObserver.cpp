//
// Created by Nicholas Kamra on 3/8/24.
//

#include "CharacterObserver.h"

std::string CharacterObserver::to_string(Character * character){
    std::string returnString = "";

    returnString += "---Character Characteristics---";
    returnString += "Name: ";
    returnString += character->getName();
    returnString += "\n";
    returnString += "Class: ";
    returnString += character->getCharacterClass();
    returnString += "\n";
    returnString += "Level: ";
    returnString += character->getLevel();
    returnString += "\n";
    returnString += "Hit Points: ";
    returnString += character->getHitPoints();
    returnString += "\n";
    returnString += "Armor Class: ";
    returnString += character->getArmorClass();
    returnString += "\n";
    returnString += "Attack Bonus: ";
    returnString += character->getAttackBonus();
    returnString += "\n";
    returnString += "Damage Bonus: ";
    returnString += character->getDamageBonus();
    returnString += "\n";
    return returnString;
}