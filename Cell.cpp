/**
 * @file cell.cpp
 * @brief Implementation file for the Cell class.
 */

#include "Cell.h"

/**
 * @brief Checks if a cell is empty.
 * 
 * This function checks if the provided cell is empty by examining its state.
 * 
 * @param currentCell A pointer to the cell to be checked.
 * @return true if the cell is empty (contains '.'), false otherwise.
 */

bool Cell::isEmptyCell(Cell * currentCell){

	if(currentCell->state->letter == '.'){
		
		return true;
    
	}
    
	return false;
	
}
