#include <iostream>
#include <string>

std::string getEquipment(int equipmentType) {
    std::string equipment;

    switch (equipmentType) {
        case 0: // Helmet
            equipment = "Helmet";
            break;
        case 1: // Armor
            equipment = "Armor";
            break;
        case 2: // Shield
            equipment = "Shield"; 
            break;
        case 3: // Ring
            equipment = "Ring";
            break;
        case 4: // Belt
            equipment = "Belt";
            break;
        case 5: // Boots
            equipment = "Boots";
            break;
        case 6: // Weapon
            equipment = "Weapon";
            break;
        default:
            equipment = "Unknown";
            break;
    }

    return equipment;
}