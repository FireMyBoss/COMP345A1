#pragma once

#include <string>
#include <stdio.h>
#include "State.h"
#include "Character.h"


using namespace std;

class Cell{

	public:

		State* state; /**< Pointer to the state of the cell. */
		Character* characterInSpot; /**< Pointer to the character occupying the cell. */
		bool isPath; /**< Flag indicating whether the cell is part of a path. */

		/**
		 * @brief Default constructor for the Cell class.
		 * 
		 * Constructs a Cell object with an empty state and initializes other attributes.
		 */
		   
		Cell() { // empty state, white space
		  	
			this->state = new EmptySpot();
			this->isPath = false; 
			characterInSpot = nullptr;
		  	
		}
			
			
		/**
		 * @brief Checks if a cell is empty.
		 * 
		 * This function checks if the provided cell is empty.
		 * 
		 * @param currentCell A pointer to the cell to be checked.
		 * @return true if the cell is empty, false otherwise.
		 */
			
		bool isEmptyCell(Cell* currentCell);

};


