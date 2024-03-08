#pragma once

long long getCurrentTime();

int writeToFile(const char* filename, const char* content);

void openNewTerminalWindow(int width, int height);

void pause(unsigned int milliseconds);

void clearConsole();

void clearInputBuffer();
