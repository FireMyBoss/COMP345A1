//
// Created by Nicholas Kamra on 3/8/24.
//

#include "userInput.h"

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
char getKeyPressed(int timeInNs) {

    char key = ' '; // Default return value if no key is pressed

    struct termios oldt, newt;
    fd_set fds;
    struct timeval tv;

    // Get current terminal attributes
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;

    // Disable canonical mode and echoing
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Initialize file descriptor set
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);

    // Set timeout
    tv.tv_sec = 0;
    tv.tv_usec = timeInNs * 1000;

    // Wait for input with timeout
    if (select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0) {

        key = getchar(); // Read the character

    }

    // Reset terminal settings
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    return key;
}

char* userInput(int timeInMs) {

    char* retArr = new char[3]();

    for (int i = 0; i < 2; i++) {

        retArr[i] = getKeyPressed(timeInMs);

    }

    retArr[2] = '\0';

    return retArr;

}


/**
 * Function to read user input from the command line.
 *
 * This function reads a line of text from the user and dynamically allocates memory
 * to store the input. It handles memory allocation and reallocation as needed.
 *
 * @return A dynamically allocated string containing the user's input, or NULL on failure.
 */

char* userInputXD() {

    char* pInput = NULL; // Initialize the input (what will be typed in the command line) to NULL
    int charIndex;
    int i = 0;

    while ((charIndex = getchar()) != '\n' && charIndex != EOF) {

        char* pTemp = (char*) realloc(pInput, (i + 3) * sizeof(char)); // Increase the size by 2 to account for the new character and the null terminator

        if (pTemp == NULL) {

            free(pInput); // Free the old memory before returning
            return NULL;

        }

        pInput = pTemp;
        pInput[i] = (char)charIndex; // Assign the character
        i++;
    }

    if (i == 0) {

        if (charIndex == EOF) { // Handle Error Case

            return NULL;

        } else {

            pInput = (char*) malloc(2 * sizeof(char));
            pInput[0] = ' ';
            pInput[1] = '\0'; // Returns empty string ' '

            return pInput;
        }
    }

    pInput[i] = '\0'; // Null-terminate the string
    return pInput;

}

int hashUserInput(const char* input) {

    int retHashVal = 0;
    size_t length = strlen(input); // Get the length of the input string

    if (length >= 2) { // Ensure that the input string has at least two characters

        for (int i = 0; i < 2; i++) { // Calculate the hash value of the first two characters

            retHashVal += (int)input[i];

        }

    }

    return retHashVal;

}


int isNorthWest(char* input) { //User input a and w keys together

    int hashVal = hashUserInput(input);

    return hashVal == 216; //a in ASCII: 97, w in ASCII: 119

}


int isNorthEast(char* input) { //User inputs 'd' and 'w' keys together

    int hashVal = hashUserInput(input);

    return hashVal == 219; //w in ASCII: 119, d in ASCII: 100

}



int isSouthEast(char* input) { //User inputs 'd' and 's' keys together

    int hashVal = hashUserInput(input);

    return hashVal == 215; //d in ASCII: 100, s in ASCII: 115

}


int isSouthWest(char* input) { //User inputs 'a' and 's' keys together

    int hashVal = hashUserInput(input);

    return hashVal == 212; //s in ASCII: 115, a in ASCII: 97

}


int isNorth(char* input) { //User inputs 'w' key

    int hashVal = hashUserInput(input);

    return hashVal == 238 || hashVal == 151; //w in ASCII: 119, space in ASCII: 32. 238 case: ww, 151 case: w space OR space w

}


int isEast(char* input) { //User inputs 'd' key

    int hashVal = hashUserInput(input);

    return hashVal == 200 || hashVal == 132; //d in ASCII: 100, space in ASCII: 32. 200 case: dd, 132 case: d space OR space d

}


int isSouth(char* input) { //User inputs 's' key

    int hashVal = hashUserInput(input);

    return hashVal == 230 || hashVal == 147; //s in ASCII: 115, space in ASCII: 32. 230 case: ss, 147 case: s space OR space s

}


int isWest(char* input) { //User inputs 'a' key

    int hashVal = hashUserInput(input);

    return hashVal == 194 || hashVal == 129; //a in ASCII: 97, space in ASCII: 32. 194 case: aa, 129 case: a space OR space a

}

int ifUserOpensChest(char* input) { //User inputs 'o' key

    int hashVal = hashUserInput(input);

    return hashVal == 222 || hashVal == 143; //o in ASCII: 111, space in ASCII: 32. 222 case: oo, 143 case: o space OR space o

}

int ifUserPauses(char* input) { // User inputs 'p' key

    int hashVal = hashUserInput(input);

    return hashVal == 224 || hashVal == 144; //o in ASCII: 112, space in ASCII: 32. 224 case: oo, 144 case: o space OR space o

}


int ifUserSelectsMenuOption(char* input) { // User inputs 'c' key

    int hashVal = hashUserInput(input);

    return hashVal == 198 || hashVal == 131; //c in ASCII: 99, space in ASCII: 32. 198 case: oo, 131 case: o space OR space o

}

int ifUserAttacks(char* input) { //User inputs 'k' key

    int hashVal = hashUserInput(input);

    return hashVal == 214 || hashVal == 139; //o in ASCII: 107, space in ASCII: 32. 214 case: oo, 139 case: k space OR space k

}


int diagonalTest(int input, int timeInNs) {

    char* test;

    switch(input) {

        case 0: //North

            for(int i = 0; i < 3; i++) {

                test = userInput(timeInNs);

                if(isNorth(test)) {

                    delete[] test;
                    return 1;

                }

                delete[] test;

            }

            break;
        case 1: //East

            for(int i = 0; i < 3; i++) {

                test = userInput(timeInNs);

                if(isEast(test)) {

                    delete[] test;
                    return 1;

                }

                delete[] test;

            }

            break;
        case 2: //South

            for(int i = 0; i < 3; i++) {

                test = userInput(timeInNs);

                if(isSouth(test)) {

                    delete[] test;
                    return 1;

                }

                delete[] test;

            }

            break;
        case 3: //West

            for(int i = 0; i < 3; i++) {

                test = userInput(timeInNs);

                if(isWest(test)) {

                    delete[] test;
                    return 1;

                }

                delete[] test;

            }

            break;

    }

    return 0;

}


int userInputCase(char* input) {

    int hashVal = hashUserInput(input); //Compute the hash value of the input

    switch (hashVal) { //Switch case statement determines which direction to return, based upon the previously defined hash values of each key input

        case 238: case 151: // isNorth

            return 0;

        case 200: case 132: // isEast

            return 1;

        case 230: case 147: // isSouth

            return 2;

        case 194: case 129: // isWest

            return 3;
				
        case 216: // isNorthWest

            return 4;

        case 219: // isNorthEast

            return 5;

        case 215: // isSouthEast

            return 6;

        case 212: // isSouthWest

            return 7;

        case 222: case 143: // ifUserOpensChest

            return 8;

        case 224: case 144: // ifUserPauses

            return 9;

        case 198: case 131: // ifUserSelectsMenuOption

            return 10;
            
        case 214: case 139: // ifUserAttacks

            return 11;

        default:

            return -1; // Return -1 if no match found

    }

}
