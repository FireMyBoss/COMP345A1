//
// Created by Nicholas Kamra on 3/8/24.
//

#include "misc.h"
#include <termios.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <unistd.h>
#include <fstream>

using namespace std;

long long getCurrentTime() {

    struct timespec current_time; // Create a struct to hold the current time information

    clock_gettime(CLOCK_REALTIME, &current_time); // Retrieve the current time using CLOCK_REALTIME and store it in the 'current_time' struct

    // Calculate the current time in nanoseconds by converting seconds to nanoseconds and adding the current nanosecond time.
    long long int time_in_ns = current_time.tv_sec * 1000000000LL + current_time.tv_nsec;

    return(time_in_ns); // Return the current time in nanoseconds

}

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

void openNewTerminalWindow(int width, int height) {
#ifdef _WIN32
    // For Windows (Not supported in this example)
        std::cerr << "Opening a terminal window of specific size is not supported on Windows." << std::endl;
#elif __linux__
    // For Linux
        std::string command = "x-terminal-emulator --geometry=" + std::to_string(width) + "x" + std::to_string(height);
        system(command.c_str());
#elif __APPLE__
    // For macOS (Not supported in this example)
        std::cerr << "Opening a terminal window of specific size is not supported on macOS." << std::endl;
#else
    // Unsupported platform
    std::cerr << "Unsupported platform." << std::endl;
#endif
}


void pause(unsigned int milliseconds) {

    usleep(milliseconds * 1000);
}

void clearConsole() {

    cout << "\033[H\033[2J\033[3J";

}

void clearInputBuffer() {

    while (cin.get() != '\n') {

    }

}