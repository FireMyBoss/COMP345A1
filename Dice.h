#pragma once

#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include <stdio.h>
#include <unistd.h>
#include "misc.h"
#include "userInput.h"
#include "Observable.h"

using namespace std;

class Dice : public Observable {

	public:
		
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
		
		int diceMenu();
		
	private:

        void abstractPure() override {};

		int numOfDice;
		int numOfSidesDie;
		int modifyValue;
		char* diceValue;
		
		char* constructDiceValue();
		int deconstructDiceValue(char* diceVal);

};

