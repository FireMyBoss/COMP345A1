#include <cmath>
#include <iostream>
#include <fstream>

#include <time.h>
#include <unistd.h>

using namespace std;

/**
 * @brief Function to get the current time in nanoseconds.
 * 
 * This function retrieves the current time using CLOCK_REALTIME and calculates the current time in nanoseconds.
 * 
 * @return The current time in nanoseconds.
 */
long long getCurrentTime() {

    struct timespec current_time; // Create a struct to hold the current time information

    clock_gettime(CLOCK_REALTIME, &current_time); // Retrieve the current time using CLOCK_REALTIME and store it in the 'current_time' struct

		// Calculate the current time in nanoseconds by converting seconds to nanoseconds and adding the current nanosecond time.
    long long int time_in_ns = current_time.tv_sec * 1000000000LL + current_time.tv_nsec; 

    return(time_in_ns); // Return the current time in nanoseconds
    
}

/**
 * @brief Function to write content to a file.
 * 
 * This function writes the provided content to a file specified by the filename.
 * 
 * @param filename The name of the file to write to.
 * @param content The content to write to the file.
 * @return 0 if successful, -1 if content is null, -2 if file cannot be opened, -3 if an error occurs with the file stream, -4 if an error occurs while closing the file.
 */
int writeToFile(const char* filename, const char* content) {
		
		if(!content) { // If the input is null
		
			return -1;
		
		}
		
    std::ofstream outputFile(filename); // Open the file in output mode, and if it doesn't exist, create it

    if (!outputFile.is_open()) { // If the file can't be opened

        return -2;
    
    } else if (!outputFile.good()) { // If something went wrong with the file stream

        return -3;
        
    }

    outputFile << content; // Write the content to the file

    outputFile.close(); // Close the file
    
		if (!outputFile.good()) { // If something went wrong while closing the file
     
	    return -4;

		}
    
    return 0;
    
}

/**
 * @brief Function to pause execution for a specified number of milliseconds.
 * 
 * This function pauses execution for a specified number of milliseconds using usleep.
 * 
 * @param milliseconds The number of milliseconds to pause for.
 */
void pause(unsigned int milliseconds) {

    usleep(milliseconds * 1000); 
    
}

/**
 * @brief Function to clear the console screen.
 */
void clearConsole() {
  
  cout << "\033[H\033[2J\033[3J"; //Magic string that clears the console screen
  
}

/**
 * @brief Function to get the number of digits in an integer for a given radix.
 * 
 * This function calculates and returns the number of digits in an integer for a given radix.
 * 
 * @param input The integer input value.
 * @param radix The radix for which digits are counted.
 * @return The number of digits in the integer for the specified radix.
 */
int getNumOfDigitsInInt(int input, int radix) {

	if(input == 0) { //0 has one digit, since it's still a number
	
		return 1;
	
	}

	int retNumOfDigits = 0;
	
	while(input != 0) { //Keep diving by radix until the number gets rounded down/up to zero
	
		input = (int) floor(input/radix);
		retNumOfDigits++;
	
	}
	
	return retNumOfDigits;
	
}

/**
 * @brief Function to get a digit at a specific index from an integer for a given radix.
 *
 * This function retrieves and returns a digit at a specific index from an integer for a given radix.
 *
 * @param input The integer input value.
 * @param radix The radix for which digits are counted.
 * @param desiredIndex The index of the digit to retrieve (starting from 1).
 *
 * @return The digit at the desired index. Returns -1 for invalid index or input values.
 */
int getNumberAtDigit(int input, int radix, int desiredIndex) {
	
	//Ex: The 1st index of 9850 is 9, 2nd is 8, etc.
	
	if(input == 0) {
	
		return 0;
	
	} else if (input < 0) {
	
		input = -input;
	
	}
	
	int numDigits = getNumOfDigitsInInt(input, radix);
	
	int divisor = pow(radix, numDigits - desiredIndex); //Get the required divisor in order to make the input / divisor always less than the radix 
	
	if(desiredIndex < 0 || input < divisor) { //Checks to see if an invalid index is trying to be acessed, if the divisor is larger than the input, or if the input is 0
	
		return -1;
	
	}
	
	int retVal = (int) ((input/divisor) % radix); //input/divisor will always result in a number smaller than the radix. Take the mod with the radix to get the value of the number at the digit.
	
	return retVal;
	
}
