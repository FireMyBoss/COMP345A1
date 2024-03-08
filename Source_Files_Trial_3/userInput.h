#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>
#include <termios.h>
#include <cstring>
#include <cmath>

#pragma once

/**
 * @brief Waits for a keypress from the user within a specified time interval.
 *
 * This function disables canonical mode and echoing on the terminal, allowing
 * for immediate input reading without the need for pressing Enter. It then waits
 * for a keypress from the user within the specified time interval. If a key is
 * pressed within the timeout period, it returns the pressed key. If no key is
 * pressed within the timeout, it returns a space character (' '). After reading
 * the key or timing out, it restores the terminal's original settings.
 *
 * @param timeInNs Time to wait for a keypress, in nanoseconds.
 * @return The character corresponding to the key pressed, or a space character if no key is pressed within the timeout.
 */
char getKeyPressed(int timeInNs);

char* userInput(int timeInMs);


/**
 * Function to read user input from the command line.
 *
 * This function reads a line of text from the user and dynamically allocates memory
 * to store the input. It handles memory allocation and reallocation as needed.
 *
 * @return A dynamically allocated string containing the user's input, or NULL on failure.
 */
 
char* userInputXD();

int hashUserInput(const char* input);

int isNorthWest(char* input);

int isNorthEast(char* input);

int isSouthEast(char* input);

int isSouthWest(char* input);

int isNorth(char* input);

int isEast(char* input);

int isSouth(char* input);

int isWest(char* input);

int ifUserOpensChest(char* input);

int ifUserPauses(char* input);

int ifUserSelectsMenuOption(char* input);

int diagonalTest(int input, int timeInNs);

int userInputCase(char* input);



