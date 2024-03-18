#pragma once

#include <iostream>
#include <fstream>
#include <cmath>
#include <unistd.h>
#include <time.h>

int getOS();

long long getCurrentTime();

int writeToFile(const char* filename, const char* content);

void pause(unsigned int milliseconds);

void clearConsole();

int getNumOfDigitsInInt(int input, int radix);

int getNumberAtDigit(int input, int radix, int desiredIndex);

