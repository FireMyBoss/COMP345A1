//
// Created by Nicholas Kamra on 3/12/24.
//

#ifndef COMP345A1_MAIN_GAMEUI_H
#define COMP345A1_MAIN_GAMEUI_H

#include <iostream>
#include <termios.h>
#include <cstring>
#include "Character.h"
#include "allcharacters.h"
#include "Map.h"
#include "Dice.cpp"
#include <cmath>
#include <vector>
#include <fstream>
#include "userInput.h"
#include "misc.h"
#include "CharacterObserver.h"
#include <filesystem>
#include <string>
#include <sstream>
#include <unordered_set>
/*
Character information in CSV file is saved as below:
name
character class
level
hit Points
armor class
attack bonus
damage bonus
helmet
boots
armor
shield
weapon
ring
belt
strength score
dexterity score
consitution score
intelligence score
wisdom score
charisma score
strength modifier
dexterity modifier
constitution modifier
intelligence modifier
wisdom modifier
charisma modifier
 */

namespace fs = std::__fs::filesystem; // !!!!!!!!!! For windows/linux do namespace fs = std::filesystem;

void creationTestsUI();
void gameLoopLoadingCampaign(std::vector<std::string> mapNamesInCampaign, std::vector<Map *> ptrVectorOfAllMaps, std::vector<Character *> vectorOfAllCharacters);
std::vector<std::string> printFilesInDirectory(const std::string & path);
void displayCampaignSelectionList();
void displayLoadCampaignMenu();
void displayCampaignMenu();
void displayStartingMenu();
void funcForCSV();
void campaignSelectionUserInput(std::vector<std::string> & campaigns, const std::string & campaignDirectoryToAppend, std::vector<std::string> & mapNamesInCampaign, std::vector<Map *> & ptrVectorOfAllMaps, std::vector<Character *> & vectorOfAllCharacters);
void gameLoopExampleForDemo();
std::vector<std::string> getMapsInCampaignCSV(fs::path & campaignCSVFilePath);
std::vector<std::vector<std::string> > getMapInformationInMapDirectory(fs::path & mapDirectoryPath);
std::vector<std::vector<std::string> > getCharacterInformationInCharacterDirectory(fs::path & characterDirectoryPath);
std::string normalizeCSVOutput(std::string CSVInput);

//for shai's MapCreator
void createNewCampaign();


#endif //COMP345A1_MAIN_GAMEUI_H
