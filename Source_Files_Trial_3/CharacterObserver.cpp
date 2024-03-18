//
// Created by Nicholas Kamra on 3/8/24.
//

#include "CharacterObserver.h"

std::string CharacterObserver::to_string(Character * character){
    std::string returnString = "";

    returnString += "---Character Info---";
    returnString += "\n";
    returnString += "Name: ";
    returnString += character->getName();
    returnString += "\n";
    returnString += "Class: ";
    returnString += character->getCharacterClass();
    returnString += "\n";
    returnString += "Level: ";
    returnString += std::to_string(character->getLevel());
    returnString += "\n";
    returnString += "Hit Points: ";
    returnString += std::to_string(character->getHitPoints());
    returnString += "\n";
    returnString += "Armor Class: ";
    returnString += std::to_string(character->getArmorClass());
    returnString += "\n";
    returnString += "Attack Bonus: ";
    returnString += std::to_string(character->getAttackBonus());
    returnString += "\n";
    returnString += "Damage Bonus: ";
    returnString += std::to_string(character->getDamageBonus());
    returnString += "\n";
    return returnString;
}