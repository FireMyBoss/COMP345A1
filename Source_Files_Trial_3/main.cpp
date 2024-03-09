#include <iostream>
#include <termios.h>

#include <cstring>
#include "Character.h"
#include "allcharacters.h"
#include "Map.h"
#include "Dice.cpp"
#include <cmath>
#include <vector>
#include <fstream>

#include "userInput.h"
#include "misc.h"

void mainMenuUI(){

    bool play = true;

    while(play) {
				
				clearConsole();
        std::cout << "---Welcome to D&D Testing---" << std::endl;
        std::cout << "Press '1' and 'Enter' for Dice creation" << std::endl;
        std::cout << "Press '2' and 'Enter' for Character creation" << std::endl;
        std::cout << "Press '3' and 'Enter' for Map creation" << std::endl;
        std::cout << "Press '4' and 'Enter' for Item creation" << std::endl;
        std::cout << "Press '5' and 'Enter' to exit the program" << std::endl;

        int userSelection = 0;

        for (;;) {
            try {
                std::cin >> userSelection;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                    continue;
                }
                break;
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }

        switch (userSelection) {
            case 1: {
                
                Dice newDice;
                
                int rollVal = newDice.diceMenu();

                cout << rollVal << "\n";
                
                pause(5000);
                clearConsole;
                
                break;
            }
            case 2: {
                Character *newCharacter = new Character();
                newCharacter->createCharacterInterface();
                delete newCharacter;
                newCharacter = nullptr;
                break;
            }
            case 3: {
            
                Map* testMap = new Map();
  							testMap -> generateInitialMapInfo();
  							delete[] testMap;
                break;
            }
            case 4: {
                Backpack *backpack = new Backpack(4);
                backpack->printItem();
                
                pause(5000);
                break;
            }
            case 5:{
                return;
            }
            default: {
                std::cout << "---Warning: Invalid option---" << std::endl;
                break;
            }
        }
    }
}

// Driver code

int main() {

    mainMenuUI();

}
