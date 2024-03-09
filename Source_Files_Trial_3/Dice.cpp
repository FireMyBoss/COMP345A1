//
// Created by Nicholas Kamra on 3/6/24.
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>

#include <stdio.h>
#include <unistd.h>
#include <termios.h>

//#include "Dice.h"
#include "misc.h"
//#include "userInput.h"

using namespace std;

/**
 * @class Dice
 * @brief Class to represent a dice and perform dice rolling operations.
 */
class Dice {

	public:
	
		int numOfDice; //Number of Dice to roll
		int numOfSidesDie; //Number of sides on dice
		int modifyValue; //What should the final value of the dice output be modified by
		char* diceValue; //String that holds dice info
		
		/**
     * @brief Default constructor for Dice class.
     */
		Dice() {
		
			numOfDice = 0;
			numOfSidesDie = 0;
			modifyValue = 0;
			diceValue = nullptr;
		
		}
		
		/**
     * @brief Parameterized constructor for Dice class.
     * @param numOfDice Number of dice to set
     * @param numOfSidesDie Number of sides on each die to set
     * @param modifyValue Value to modify the final output by
     */
		Dice(int numOfDice, int numOfSidesDie, int modifyValue) {
			
			this -> numOfDice = numOfDice;
			this -> numOfSidesDie = numOfSidesDie;
			this -> modifyValue = modifyValue;
			this -> diceValue = constructDiceValue(); //Special method that constructs the dice string value
			
		}
		
		/**
     * @brief Destructor for Dice class.
     */
		~Dice() {
		
		  if (diceValue != nullptr) {
		  
		      delete[] diceValue;
		      diceValue = nullptr;
		      
		  }
		  
		}
		
		/**
     * @brief Get the number of dice.
     * @return The number of dice.
     */
		int getNumOfDice() {
		
			return numOfDice;
		
		}
		
		 /**
     * @brief Set the number of dice.
     * @param numOfDice The number of dice to set.
     */
		void setNumOfDice(int numOfDice) {
		
			this -> numOfDice = numOfDice;
			this -> diceValue = constructDiceValue();
		
		}
		
		/**
     * @brief Get the number of sides on each die.
     * @return The number of sides on each die.
     */
		int getNumOfSidesDie() {
		
			return numOfSidesDie;
		
		}
		
		/**
     * @brief Set the number of sides on each die.
     * @param numOfSidesDie The number of sides on each die to set.
     */
		void setNumOfSidesDie(int numOfSidesDie) {
			
			this -> numOfSidesDie = numOfSidesDie;
			this -> diceValue = constructDiceValue();
		
		}
		
		/**
     * @brief Get the modification value for the final output.
     * @return The modification value.
     */
		int getModifyValue() {
		
			return modifyValue;
		
		}
		
		 /**
     * @brief Set the modification value for the final output.
     * @param modifyValue The modification value to set.
     */
		void setModifyValue(int modifyValue) {
		
			this -> modifyValue = modifyValue;
			this -> diceValue = constructDiceValue();
		
		}
		
		/**
     * @brief Get the string representation of the dice information.
     * @return The string representing the dice information.
     */
		char* getDiceValue() {
		
			return diceValue;
		
		}
		
		/**
     * @brief Set the dice value based on a given string input.
     * @param diceValue The string input representing the new dice value.
     */
		void setDiceValue(char* diceValue) {
			
			if(deconstructDiceValue(diceValue) == 1) { //Make sure that the inputted dice string is properly formatted
			
				delete[] this -> diceValue;
				this -> diceValue = constructDiceValue();
			
			}

		}
		
		/**
     * @brief Roll the dice and return the result based on current settings.
     * @return The result of rolling the dice with modifications applied.
     */
		int roll() {
			
			int retVal = 0;
			
			for(int i = 0; i < numOfDice; i++) {
			
				retVal += (getCurrentTime() % numOfSidesDie) + 1;
			
			}
		
			return retVal + modifyValue;
		
		}
		
		/**
     * @brief Roll the dice based on a given input string and return the result.
     * @param inputDiceString The input string representing the new dice value to roll with.
     * @return The result of rolling the modified dice based on input string.
     */
		int roll(char* inputDiceString) {
		
			if(deconstructDiceValue(inputDiceString) == 0) { //Ensures that the inputted dice string is valid, otherwise it returns nothing at all
			
				return 0;
			
			}
			
			return roll();
		
		}
		
		int diceMenu() {
		
			int mainMenuOption = 0;
			std:string diceInput;
			char* diceInputCharP;
			
			int retVal = 0;
			
			int runMainLoop = 1;
			int runInnerLoop = 1;
			
			while(runMainLoop) {
				
				clearConsole();
				cout << "Dice Demonstration\n1) Roll a dice\n2)Exit Menu\n\nEnter Option: ";
				cin >> mainMenuOption;
				
				switch(mainMenuOption) {
				
					case 1:
						
						while(runInnerLoop) {
						
							clearConsole();
							cin.clear(); // Clear the fail state
		     			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		     			cout << "Enter the desired dice string: ";
		     			
		     			cin >> diceInput;
		     			diceInputCharP = new char[diceInput.length() + 1];
		     			strcpy(diceInputCharP, diceInput.c_str());
		     			
		     			if(deconstructDiceValue(diceInputCharP) == 0) {
		     				
		     				cout << "Error: inputted string was not a valid dice string\n";
								
								pause(1000);
								delete[] diceInputCharP;
								cin.clear(); // Clear the fail state
				   			cin.ignore(numeric_limits<streamsize>::max(), '\n');
				   			continue; 
		     				
		     			} else {
		     			
		     				cout << "Success! Rolling the dice now!\n";
		     				retVal = roll(diceInputCharP);
		     				delete[] diceInputCharP;
		     				pause(1000);
		     				
		     				runInnerLoop = 0;
		     				runMainLoop = 0;
		     			
		     			}
       			
       			}
					
					break;
					case 2:
						
						clearConsole();
						runMainLoop = 0;
					
					break;
					default:
					
						cout << "Error: User input was not a valid menu option\n";
										
						pause(1000);
						cin.clear(); // Clear the fail state
       			cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

				}
				
			}
			
			return retVal;
			
		}
		
	private:
		
		/**
		* @brief Construct a string representation of the current dice settings.
		* @return A dynamically allocated char array representing the current dice settings as a string.
		*/
		char* constructDiceValue() {
	
			int digitsNumOfDice = getNumOfDigitsInInt(numOfDice,10); //Get the number of digits that represents the number of dice 
			int digitsNumOfSidesDie = getNumOfDigitsInInt(numOfSidesDie, 10); //Get the number of digits that represents the number of sides per die
			int digitsModifyValue = getNumOfDigitsInInt(modifyValue, 10); //Get the number of digits that represent the modification value when finished rolling
			
			char* diceValue = new char[digitsNumOfDice + 1 + digitsNumOfSidesDie + 1 + digitsModifyValue + 1]; //The first +1 is for the d, the second is for the + or - sign, the third is for the null terminator
			
			int currentIndexDiceVal = 0; //Determines what index to place the dice characters at int the return string
			
			for(int i = 0; i < digitsNumOfDice; i++) { //Handle all Number of Dice digits for the return string
			
				int tempDigit = getNumberAtDigit(numOfDice, 10, i + 1); //Gets the (ith + 1) (so 1st to digitsNumOfDice + 1th) digit of numOfDice
				diceValue[currentIndexDiceVal] = (char) (tempDigit + 48); //48 is the ASCII code for the character '0'
				
				currentIndexDiceVal++;
			
			}
			
			diceValue[currentIndexDiceVal] = 'd'; //Sets the 'd' delimiter between number of dice and sides per die
			currentIndexDiceVal++;
			
			for(int i = 0; i < digitsNumOfSidesDie; i++) { //Handle all Number of Sides per die digits for the return string
			
				int tempDigit = getNumberAtDigit(numOfSidesDie, 10, i + 1); //Gets the (ith + 1) (so 1st to digitsNumOfDice + 1th) digit of numOfSidesDie
				diceValue[currentIndexDiceVal] = (char) (tempDigit + 48); //48 is the ASCII code for the character '0'
				
				currentIndexDiceVal++;
			
			}
			
			diceValue[currentIndexDiceVal] = modifyValue > 0 ? '+' : '-'; //Sets the parity character (+ or -) of modifyValue 
			currentIndexDiceVal++;
			
			for(int i = 0; i < digitsModifyValue; i++) { //Handle all of the modified amount after roll per die digits for the return string
			
				int tempDigit = getNumberAtDigit(modifyValue, 10, i + 1); //Gets the (ith + 1) (so 1st to digitsNumOfDice + 1th) digit of modifyValue
				diceValue[currentIndexDiceVal] = (char) (tempDigit + 48); //48 is the ASCII code for the character '0'
				
				currentIndexDiceVal++;
			
			}
			
			diceValue[currentIndexDiceVal] = '\0'; //Finish string with null terminator
			
		return diceValue;
	
	}
	
	/**
	* @brief Deconstruct a given string into individual components and update current settings accordingly.
	* @param diceVal The input string representing a new set of dice settings to deconstruct and apply.
	* @return 0 if successful, 1 if unsuccessful in deconstruction process.
	*/
	int deconstructDiceValue(char* diceVal) {
			
			//Initialize amount of digits for each section (# Dice, # Sides per Dice, Modification value) of the string
			int digitsNumOfDice = 0;
			int digitsNumOfSidesDie = 0;
			int digitsModifyValue = 0;
			
			//Initialize integer values for each section (# Dice, # Sides per Dice, Modification value) of the string
			int numOfDice = 0;
			int numOfSidesDie = 0;
			int modifyValue = 0;
			
			int negateModifyValue = 0; //Flag to check if modifyValue should be positive or negative
			
			int currentIndexDiceVal= 0; //Determines what index to keep track of the dice characters in the inputted dice string
			
			while(diceVal[currentIndexDiceVal] != '\0' && diceVal[currentIndexDiceVal] >= '0' && diceVal[currentIndexDiceVal] <= '9') { //Check if number of dice exist
				
				digitsNumOfDice++;
				currentIndexDiceVal++;
				
			}
			
			if(digitsNumOfDice == 0) { //If there are no digits in the numOfDie number, return 0
			
				return 0;
			
			}
			
			for(int i = digitsNumOfDice; i > 0; i--) { //Calcuate the number of dice (Number at digit * 10^(Number of Digits - Specific Digit - 1))
				
				//Ex: The substring, "1234" becomes: 1*10^3 + 2*10^2 + 3*10^1 + 4*10^0
				numOfDice += (diceVal[currentIndexDiceVal - i] - 48) * pow(10, i - 1); //48 is the ASCII code for the character '0'
			
			}
			
			
			if (diceVal[currentIndexDiceVal] != 'd') { //Check to see if the d character is present
					
				return 0; // Return from the function if 'd' character is not present
			
			} else {
				
				currentIndexDiceVal++; // Increment currentIndexDiceVal if 'd' character is present
			
			}
			
			
   		while(diceVal[currentIndexDiceVal] != '\0' && diceVal[currentIndexDiceVal] >= '0' && diceVal[currentIndexDiceVal] <= '9') { //Check if number of sides per die exist
				
				digitsNumOfSidesDie++;
				currentIndexDiceVal++;
				
			}
			
			if(digitsNumOfSidesDie == 0) { //If there are no digits in the number of sides in the dice, return 0
			
				return 0;
			
			}
			
			for(int i = digitsNumOfSidesDie; i > 0; i--) { //Calcuate the number of sides per die (Number at digit * 10^(Number of Digits - Specific Digit - 1))
				
				//Ex: The substring, "1234" becomes: 1*10^3 + 2*10^2 + 3*10^1 + 4*10^0
				numOfSidesDie += (diceVal[currentIndexDiceVal - i] - 48) * pow(10, i - 1); //48 is the ASCII code for the character '0'
			
			}
			
			
			if (diceVal[currentIndexDiceVal] == '+') { //Check to see if the '+' character is present
			
				currentIndexDiceVal++; // Increment currentIndexDiceVal if '+' character is present
			
			} else if(diceVal[currentIndexDiceVal] == '-') { //Check to see if the '-' character is present
				
				currentIndexDiceVal++; // Increment currentIndexDiceVal if '+' character is present
				negateModifyValue = 1; // Set the boolean flag to make modifyValue negative
			
			} else {
				
				return 0; // Return from the function if '+' or '-' character is not present
	
			}
			
			
			while(diceVal[currentIndexDiceVal] != '\0' && diceVal[currentIndexDiceVal] >= '0' && diceVal[currentIndexDiceVal] <= '9') { //Check if the modification number exists for the dice
				
				digitsModifyValue++;
				currentIndexDiceVal++;
				
			}
			
			
			for(int i = digitsModifyValue; i > 0; i--) { //Calcuate the number of sides per die (Number at digit * 10^(Number of Digits - Specific Digit - 1))
				//Ex: The substring, "1234" becomes: 1*10^3 + 2*10^2 + 3*10^1 + 4*10^0
				modifyValue += (diceVal[currentIndexDiceVal - i] - 48) * pow(10, i - 1); //48 is the ASCII code for the character '0'
			
			}
			
			if(negateModifyValue) { //Checks to see if modifyValue should be made negative or not (based on if + or - was present in the string)
			
				modifyValue = -1*modifyValue;
			
			}
			
			//Set the calculated values of each substring section to the dice
			this -> numOfDice = numOfDice;
			this -> numOfSidesDie = numOfSidesDie;
			this -> modifyValue = modifyValue;
			
			return 1;
   		
		}

};


