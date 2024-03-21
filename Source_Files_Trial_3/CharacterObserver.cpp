#include "CharacterObserver.h"
CharacterObserver::CharacterObserver(Character* character){
    this->character = character;
}

void CharacterObserver::update(Observable * observable){
    std::cout << CharacterObserver::to_string();
}

std::string CharacterObserver::to_string(){
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
