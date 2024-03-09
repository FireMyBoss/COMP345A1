#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>

#include "misc.h"
#include "userInput.h"

using namespace std;

class Dice {

	public:
	
		int numOfDice;
		int numOfSidesDie;
		int modifyValue;
		char* diceValue;
		
		Dice();
		Dice(int numOfDice, int numOfSidesDie, int modifyValue);
		~Dice();
		
		int getNumOfDice();
		void setNumOfDice(int numOfDice);
		int getNumOfSidesDie();
		void setNumOfSidesDie(int numOfSidesDie);
		int getModifyValue();
		void setModifyValue(int modifyValue);
		char* getDiceValue();
		void setDiceValue(char* diceValue);
		int roll();
		int roll(char* inputDiceString);
		void diceMenu();
		
	private:
		
		char* constructDiceValue();
		int deconstructDiceValue(const char* diceVal);

};

