#include "State.h"
#include<cstdlib>

void State::setColour(string color){
    this -> colour = color;
    if(color == "white"){
        letter = '.';
    } else if (color == "black"){
        letter = 'X';
    } else if (color == "orange"){
        letter = 'C';
    } else if (color == "brown"){
        letter = 'D';
    } else if (color == "blue"){
        letter = 'S';
    } else if (color == "red"){
        letter = 'E';
    }
};
 

void State::setLetter(char let){
    this -> letter = let;
    if(let == '.'){
        colour = "white";
    } else if (let == 'X'){
        colour = "black";
    } else if (let == 'C'){
        colour = "orange";
    } else if (let == 'D'){
        colour = "brown";
    } else if (let == 'S'){
        colour = "blue";
    } else if (let == 'E'){
        colour = "red";
    }
};