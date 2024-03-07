//
// Created by Nicholas Kamra on 3/7/24.
//
#include "Cell.h"

bool Cell::isEmptyCell(Cell * currentCell){
    if(currentCell->state->letter == '.'){
        return true;
    }
    return false;
}