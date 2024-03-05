#include "GroupItemH.h"
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    // Create an instance of the Equipment class
    Equipment *mine = new Equipment(false, 3);

    // Print out the type of equipment, bonus and enchantment
    cout << "Type: " << mine->getEquipmentType() << endl;
    cout << "Bonus: " << mine->getBonus() << endl;
    cout << "Enchantment: " << mine->getEnchantment() << endl;

    // Don't forget to delete the dynamically allocated object to avoid memory leaks
    delete mine;

    return 0;
}