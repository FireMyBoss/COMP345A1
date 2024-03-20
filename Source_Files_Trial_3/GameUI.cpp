//
// Created by Nicholas Kamra on 3/12/24.
//

#include "GameUI.h"
#include "MapCreator.h"

#ifdef __APPLE__

namespace fs = std::__fs::filesystem;

#else

namespace fs = std::filesystem;

#endif

void save(){

}

std::unordered_set<char> acceptableCharacters = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o',
                                    'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4',
                                    '5', '6', '7', '8', '9', '0', 'A', 'B', 'C', 'D', 'E', 'F',
                                    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U',
                                    'V', 'W', 'X', 'Y', 'Z', '@', '#', '$', '%', '^', '&', ',', '.', '!', '*',
                                    '(', ')', '-', '_', '+', '=', ' '};

std::string normalizeCSVOutput(std::string CSVInput){

    std::string returnString = "";

    for(int i = 0; i < CSVInput.length(); i++){
        char currentChar = CSVInput[i];
        for(char acceptChar : ::acceptableCharacters){
            if(currentChar == acceptChar){
                returnString.push_back(currentChar);
                break;
            }
        }
    }
    return returnString;
}

void creationTestsUI(){

    bool play = true;

    while(play) {

        clearConsole();
        std::cout << "D&D Testing" << std::endl;
        std::cout << "-----------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Press '1' and 'Enter' for Dice creation" << std::endl;
        std::cout << "Press '2' and 'Enter' for Character creation" << std::endl;
        std::cout << "Press '3' and 'Enter' for Map creation" << std::endl;
        std::cout << "Press '4' and 'Enter' for Item creation" << std::endl;
        std::cout << "Press '5' and 'Enter' for unsaved game trial" << std::endl;
        std::cout << "Press '6' and 'Enter' to exit the program" << std::endl;

        int userSelection = 0;

        for (;;) {
            try {
                std::cin >> userSelection;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                    continue;
                }
                break;
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }

        switch (userSelection) {
            case 1: {

                Dice newDice;

                int rollVal = newDice.diceMenu();

                cout << rollVal << "\n";

                pause(5000);

                break;
            }
            case 2: {
                Character *newCharacter = new Character();
                newCharacter->createCharacterInterface();
                delete newCharacter;
                newCharacter = nullptr;
                break;
            }
            case 3: {
                generateInitialMapInfo();
                break;
            }
            case 4: {
                Backpack *backpack = new Backpack(4);
                backpack->printItem();

                pause(5000);
                break;
            }
            case 5:{
                gameLoopExampleForDemo();
            }
            case 6:{
                return;
            }
            default: {
                std::cout << "---Warning: Invalid option---" << std::endl;
                break;
            }
        }
    }
}

void gameLoopExampleForDemo(){
    bool play = true;


    Character * characterForCreation = new Character();
    std::vector<Character *> characterVec;
    characterForCreation->createNewCharacter(characterVec);

    Character * newCharacter = characterVec.at(0);
    Observer * newObserver = new CharacterObserver(newCharacter);
    newCharacter->attach(newObserver);

    Map* newMap;

    int height;
    int width;

    std::cout << "Create a map" << std::endl;
    std::cout << "------------" << std::endl;
    std::cout << "" << std::endl;

    std::cout << "Enter a map height: " << std::endl;
    for (;;) {
        try {
            std::cin >> height;
            if (cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter an integer.");
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }

    std::cout << "Enter a map width: " << std::endl;
    for (;;) {
        try {
            std::cin >> width;
            if (cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter an integer.");
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }

    newMap = new Map(height, width);
    Observer * mapObserver = new MapObserver(newMap);
    newMap->attach(mapObserver);

    newMap->loadCharactersIntoMap(characterVec);

    while(play){

        newMap->notify();
        newCharacter->notify();

        // return 'E' for end and 'S' to stop game and 'X' for error and 'C' continue
        char selection;

        selection = getUserInput(newCharacter, newMap);
        clearConsole();
        if(selection == 'S'){
            delete newMap;
            play = false;
        }else{
            play = true;
        }
    }

}

void gameLoopLoadingCampaign(std::vector<std::string> mapNamesInCampaign, std::vector<Map *> ptrVectorOfAllMaps, std::vector<Character *> ptrVectorOfAllCharacters){
// TODO: items in parameter vectors may have backwards items

    clearConsole();

    bool play = true;

    int currMapIndex = 0;

    Map * currMap = ptrVectorOfAllMaps.at(currMapIndex);
    Observer * mapObserver = new MapObserver(currMap);
    currMap->attach(mapObserver);
    Character * newCharacter = ptrVectorOfAllCharacters.at(0);
    Observer * characterObserver = new CharacterObserver(newCharacter);
    newCharacter->attach(characterObserver);

    currMap->loadCharactersIntoMap(ptrVectorOfAllCharacters);

    while(play){

        currMap->notify();
        newCharacter->notify();

        // return 'E' for end and 'S' to stop game and 'X' for error and 'C' continue
        char selection;

        selection = getUserInput(newCharacter, currMap);

       clearConsole();

        if(selection == 'S'){
            play = false;
        }else if(selection == 'E'){

                currMapIndex++;

                if(ptrVectorOfAllMaps.size() - 1 < currMapIndex){
                    currMapIndex--;
                    continue;
                }
                currMap = ptrVectorOfAllMaps.at(currMapIndex);
                mapObserver = new MapObserver(currMap);
                currMap->attach(mapObserver);
                currMap->loadCharactersIntoMap(ptrVectorOfAllCharacters);

        }else{
                continue;

        }
    }
}

std::vector<std::string> printFilesInDirectory(const std::string & path){

    std::vector<std::string> campaigns;

    fs::path currentPath = fs::current_path();
    currentPath /= path;


    if(fs::exists(currentPath) && fs::is_directory(currentPath)) {

        for (const auto &entry: fs::directory_iterator(currentPath)) {
            if(entry.path().filename() == ".DS_Store"){
                continue;
            }else{
                std::cout << entry.path().filename() << std::endl;
                campaigns.push_back(entry.path().filename());
            }
        }

    }else{
        std::cout << "Directory not found" << std::endl;
    }
    std::cout << "" << std::endl;
    return campaigns;
}

std::vector<std::string> getMapsInCampaignCSV(fs::path & campaignCSVFilePath){

    std::ifstream file(campaignCSVFilePath);
    std::vector<std::string> mapNamesInCampaign;

    if (!file.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return mapNamesInCampaign;
    }

    std::string line;
    std::cin.clear();
    std::cin.ignore();
    while (std::getline(file, line)) {

        mapNamesInCampaign.push_back(normalizeCSVOutput(line));

    }

    file.close();

    return mapNamesInCampaign;
}
// TODO: there is an error here -----------------------------
std::vector<std::vector<std::string> > getMapInformationInMapDirectory(fs::path & mapDirectoryPath){


    std::ifstream file(mapDirectoryPath);
    std::vector<std::vector<std::string> > mapDataVector;



    if (!file.is_open()) {
        std::cerr << "Error opening file" << std::endl;
        return mapDataVector;
    }

    std::string line;
    std::cin.clear();
    std::cin.ignore();

    while (std::getline(file, line)) {
        std::vector<std::string> newVec;
        // must delimit line and push_back each string into newVec for each line
        std::istringstream iss(line);
        std::string stringToPushBack;

        while (std::getline(iss, stringToPushBack, ',')) {
            newVec.push_back(normalizeCSVOutput(stringToPushBack));
        }

        mapDataVector.push_back(newVec);

    }

    file.close();

    return mapDataVector;
}

std::vector<std::vector<std::string> > getCharacterInformationInCharacterDirectory(fs::path & characterDirectoryPath){
    std::vector<std::string> allCharactersVector;
    std::vector<std::vector<std::string> > allCharactersVectorWithData;

    if(fs::exists(characterDirectoryPath) && fs::is_directory(characterDirectoryPath)) {

        for (const auto &entry: fs::directory_iterator(characterDirectoryPath)) {
            if(entry.path().filename() == ".DS_Store"){
                continue;
            }else{
                allCharactersVector.push_back(normalizeCSVOutput(entry.path().filename()));
            }
        }

    }else{
        std::cout << "Directory not found" << std::endl;
    }

    for(std::string characters : allCharactersVector){

        fs::path characterCSVPath = characterDirectoryPath;
        characterCSVPath /= characters;

        std::ifstream file(characterCSVPath);
        std::vector<std::string> characterDataInCSV;

        if (!file.is_open()) {
            std::cerr << "Error opening file!" << std::endl;
            return allCharactersVectorWithData;
        }

        std::string line;
        std::cin.clear();
        std::cin.ignore();
        while (std::getline(file, line)) {

            characterDataInCSV.push_back(normalizeCSVOutput(line));

        }

        file.close();
        allCharactersVectorWithData.push_back(characterDataInCSV);

    }

    return allCharactersVectorWithData;

}

bool campaignSelectionUserInput(std::vector<std::string> & campaigns, const std::string & campaignDirectoryToAppend, std::vector<std::string> & allMapNamesInCampaign, std::vector<Map *> & ptrVectorOfAllMaps, std::vector<Character *> & ptrVectorOfAllCharacters){

    fs::path currentPath = fs::current_path();
    currentPath /= campaignDirectoryToAppend;

    std::cout << "Enter campaign name (just include the name without quotations) to exit enter '/': ";

    std::string campaignSelection;

    // we loop until we get valid campaign or the user wants to exit this selection
    for(;;) {

        std::cin >> campaignSelection;

        if(campaignSelection == "/"){
            return false;
        }

        bool campaignExists = false;

        fs::path campaignDirectory;


        for (std::string campaign: campaigns) {
            if (campaign == campaignSelection) {
                currentPath /= campaignSelection;
                campaignDirectory = currentPath; // This is the directory path inside a campaign
                campaignExists = true;
            }
        }


        if (campaignExists) {
            if (fs::exists(currentPath) && fs::is_directory(currentPath)) {


                // Creation for vector of maps in campaign
                std::vector<std::string> mapNamesInCampaign;
                fs::path campaignCSVFilePath = campaignDirectory;
                campaignCSVFilePath /= "campaign.csv";
                mapNamesInCampaign = getMapsInCampaignCSV(campaignCSVFilePath);
                allMapNamesInCampaign = mapNamesInCampaign; // parameter changed

                // Creation for vector of all maps with map data
                std::vector<std::vector<std::vector<std::string> > > vectorOfAllMaps;
                fs::path mapDirectoryPath = campaignDirectory;
                mapDirectoryPath /= "Maps";

                std::vector<std::vector<std::vector<std::string> > > allMapsInCampaignDataVector;

                for (std::string campaign: mapNamesInCampaign) {

                    std::string currentCampaign = campaign;
                    fs::path currentMapDirectory = mapDirectoryPath;
                    currentMapDirectory /= currentCampaign;
                    std::vector<std::vector<std::string> > newMapDataVector = getMapInformationInMapDirectory(
                            currentMapDirectory);
                    allMapsInCampaignDataVector.push_back(newMapDataVector);
                }

                for (int i = 0; i < allMapsInCampaignDataVector.size(); i++) {
                    Map *newMap = new Map(allMapsInCampaignDataVector.at(i));
                    ptrVectorOfAllMaps.push_back(newMap);
                }

                // Creation for vector of all characters with character data
                std::vector<std::vector<std::string> > vectorOfAllCharacters;

                fs::path characterDirectoryPath = campaignDirectory;
                characterDirectoryPath /= "Characters";

                vectorOfAllCharacters = getCharacterInformationInCharacterDirectory(characterDirectoryPath);

                for (int i = 0; i < vectorOfAllCharacters.size(); i++) {
                    ptrVectorOfAllCharacters.push_back(
                            buildCharacterFromSaveFile(vectorOfAllCharacters.at(i))); // changing parameter
                }
                return true;

            } else {
                std::cout << "Error: Failure to load - campaign does not exist" << std::endl;
                continue;
            }
        } else {
            std::cout << "Error: Campaign does not exist" << std::endl;
            std::cout << "" << std::endl;
            continue;
        }
    }
}

void displayCampaignSelectionList(){

    clearConsole();

    const std::string campaignDirectory = "Campaigns";

    std::cout << "Available campaigns" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "" << std::endl;

    std::vector<std::string> campaigns;

    campaigns = printFilesInDirectory(campaignDirectory);

    std::cout << "Enter '1' to enter a campaign selection" << std::endl;
    std::cout << "Enter '2' to go back" << std::endl;

    char userSelection;

    for (;;) {
        try {
            std::cin >> userSelection;
            if (cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter an integer.");
            } else if (userSelection != '1' && userSelection != '2') {
                continue;
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }
    switch(userSelection){
        case '1':{
            std::vector<std::string> mapNamesInCampaign;
            std::vector<Map *> ptrVectorOfAllMaps;
            std::vector<Character *> vectorOfAllCharacters;
            bool goodInput = campaignSelectionUserInput(campaigns, campaignDirectory, mapNamesInCampaign, ptrVectorOfAllMaps, vectorOfAllCharacters);
            if(goodInput) {
                gameLoopLoadingCampaign(mapNamesInCampaign, ptrVectorOfAllMaps, vectorOfAllCharacters);
            }else{

            }
            break;
        }
        case '2':
        {
            return;
        }
        default:
            break;
    }
}

void displayLoadCampaignMenu(){

    for(;;) {
        std::cin.clear();
        std::cin.ignore();
        clearConsole();

        std::cout << "Load Campaign" << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Enter '1' to list all campaigns" << std::endl;
        std::cout << "Enter '2' to go back" << std::endl;
        std::cout << "" << std::endl;

        char userSelection;

        for (;;) {
            try {
                std::cin >> userSelection;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                } else if (userSelection != '1' && userSelection != '2') {
                    continue;
                }
                break;
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }
        switch(userSelection){
            case '1':{
                displayCampaignSelectionList();
                break;
            }
            case '2':
            {
                return;
            }
            default:
                break;
        }
    }
}

void displayCampaignMenu(){


    for(;;) {

        clearConsole();

        std::cout << "Campaign Menu" << std::endl;
        std::cout << "-------------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Enter '1' to load a campaign" << std::endl;
        std::cout << "Enter '2' to create a campaign" << std::endl;
        std::cout << "Enter '3' to go back" << std::endl;

        char userSelection;

        for (;;) {
            try {
                std::cin >> userSelection;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                } else if (userSelection != '1' && userSelection != '2' && userSelection != '3') {
                    continue;
                }
                break;
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }
        switch (userSelection) {
            case '1': {
                displayLoadCampaignMenu();
                break;
            }
            case '2': {
                createNewCampaign();
                break;
            }
            case '3': {
                return;
            }
            default: {
                break;
            }
        }
    }
}


void displayStartingMenu(){

    for(;;) {

        clearConsole();

        std::cout << "Dungeons and Dragons" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << "" << std::endl;
        std::cout << "Enter '1' to start game" << std::endl;
        std::cout << "Enter '2' to exit game" << std::endl;
        std::cout << "Enter '3' to enter creation testing" << std::endl;

        char userSelection;

        for (;;) {
            try {
                std::cin >> userSelection;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                    continue;
                } else if (userSelection != '1' && userSelection != '2' && userSelection != '3') {
                    continue;
                }
                break;
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }

        if (userSelection == '1') {

            //gameLoop();
            displayCampaignMenu();

        } else if(userSelection == '2') {
            return;
        }else{
            creationTestsUI();
        }
    }
}


void funcForCSV(){

    std::vector<std::vector<std::string>> vecForCSV;

    Map * newMap = new Map(60, 60);
    vecForCSV = mapToVectorForCSV(newMap);

    for(int i = 0; i < vecForCSV.size();i++){
        for(int j = 0; j < vecForCSV.at(i).size(); j++){
            std::cout << vecForCSV.at(i).at(j) << std::endl;
        }
    }

}

Map* generateInitialMapInfo() {

    int retVal = 0;
    int runMainLoop = 1;
    int runInnerLoop = 1;

    int sizeInput = 0;
    int inputWidth = 0;
    int inputLength = 0;

    Map* retMap;

    Observer * retObserver;

    char* generalMapOptionsInput;
    int generalMapOptionsMenuSelector = 0;
    const char* generalMapOptions[2] = {

            ">> Create a map\n Exit the map generation screen\n\nPress W to navigate up, S to navigate down, C to select option\n\n",
            "Create a map\n>> Exit the map generation screen\n\nPress W to navigate up, S to navigate down, C to select option\n\n"

    };

    char* printMapOptionInput;
    int  printMapOptionsMenuSelector = 0;
    const char* printMapOption[2] = {

            ">> Yes \n No\n\nPress W to navigate up, S to navigate down, C to select option / stop viewing map\n\n",
            "Yes \n>> No\n\nPress W to navigate up, S to navigate down, C to select option / stop viewing map\n\n"

    };

    char* stopViewingMap;


    do {

        cout << generalMapOptions[generalMapOptionsMenuSelector];
        generalMapOptionsInput = userInput(10);

        switch(userInputCase(generalMapOptionsInput)) {

            case 0: //W key (Up)

                generalMapOptionsMenuSelector--;
                generalMapOptionsMenuSelector = generalMapOptionsMenuSelector - 2*floor(generalMapOptionsMenuSelector/2.0);

                break;
            case 2: //S key (Down)

                generalMapOptionsMenuSelector++;
                generalMapOptionsMenuSelector = generalMapOptionsMenuSelector - 2*floor(generalMapOptionsMenuSelector/2.0);

                break;
            case 10: //C key (Select)

                switch(generalMapOptionsMenuSelector) {

                    case 0: //Random Map generation part

                        while(true) { //Get width of map

                            clearConsole();
                            cout << "Input the desired width of the map: ";

                            cin >> inputWidth;

                            if(inputWidth < 1) {

                                cout << "Error: The width of the map must be a positive number!\n";

                                pause(1000);
                                cin.clear(); // Clear the fail state
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                continue;

                            }

                            break;

                        }

                        while(true) { //Get length of map

                            clearConsole();
                            cout << "Input the desired length of the map: ";

                            cin >> inputLength;

                            if(inputLength < 1) {

                                cout << "Error: The length of the map must be a positive number!\n";

                                pause(1000);
                                cin.clear(); // Clear the fail state
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                continue;

                            }

                            break;

                        }

                        clearConsole();

                        retMap = new Map(inputWidth, inputLength); //Generate the map

                        retObserver = new MapObserver(retMap);
                        retMap->attach(retObserver);

                        //Offer to display the map
                        cout << "The map has been successfully generated! Would you like to see the map?\n";
                        pause(2000);

                        do {

                            cout << printMapOption[printMapOptionsMenuSelector];
                            printMapOptionInput = userInput(10);

                            switch(userInputCase(printMapOptionInput)) {

                                case 0: //W key (Up)

                                    printMapOptionsMenuSelector--;
                                    printMapOptionsMenuSelector = printMapOptionsMenuSelector - 2*floor(printMapOptionsMenuSelector/2.0);

                                    break;
                                case 2: //S key (Down)

                                    printMapOptionsMenuSelector++;
                                    printMapOptionsMenuSelector = printMapOptionsMenuSelector - 2*floor(printMapOptionsMenuSelector/2.0);

                                    break;
                                case 10: //C key (Select)

                                    switch(printMapOptionsMenuSelector) {

                                        case 0: //User wants to see the map

                                            clearConsole();

                                            retMap->notify();

                                            while(true) {

                                                stopViewingMap = userInput(10);

                                                if(stopViewingMap[0] == 'c') {

                                                    delete[] stopViewingMap;
                                                    break;

                                                }

                                                delete[] stopViewingMap;

                                            }

                                            runInnerLoop = 0;
                                            runMainLoop = 0;

                                            break;
                                        case 1: //User doesn't want to see the map

                                            runInnerLoop = 0;

                                            break;

                                    }

                            }

                            if(runInnerLoop != 0) {

                                delete[] printMapOptionInput;

                            }

                            clearConsole();

                        } while (runInnerLoop);

                        retVal = 1;
                        runMainLoop = 0;


                        break;
                    case 1: //Quit Game

                        retVal = 0;
                        runMainLoop = 0;

                        break;

                }

        }

        if(runMainLoop != 0) {

            delete[] generalMapOptionsInput;

        }

        clearConsole();

    } while(runMainLoop);

    delete[] generalMapOptionsInput;

    return retMap;

}

bool pauseMenuUIandExitGame(){

    clearConsole();

    std::cout << "Pause Menu" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter '1' to unpause" << std::endl;
    std::cout << "Enter '2' to exit game" << std::endl;

    char playerInputChar;

    for (;;){
        try {
            std::cin >> playerInputChar;
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter a character.");
                continue;
            }else if(playerInputChar != '1' && playerInputChar != '2'){
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }
    switch(playerInputChar){
        case '1':{
            return false;
        }
        case '2':{

            return true;
        }
        default:{
            break;
        }
    }
    return false;
}
char getUserInput(Character * player, Map * currMap){ // return 'E' for end and 'S' to stop game and 'X' for error and 'C' continue

    std::cout << "Please enter a direction to move ('w', 'a', 's', 'd') or pause ('p'):";
    std::cout << "" << std::endl;
    char playerInputChar;

    for (;;){
        try {
            std::cin >> playerInputChar;
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter a character.");
                continue;
            }else if(playerInputChar != 'w' && playerInputChar != 'a' && playerInputChar != 's'
                     && playerInputChar != 'd' && playerInputChar != 'p'){
                std::cin.clear();
                std::cin.ignore();
                continue;
            }
            break;
        } catch (...) {
            std::cin.clear();
            std::cin.ignore();
        }
    }

    State * stateToCheck;
    int movementX = 0;
    int movementY = 0;

    switch(playerInputChar){
        case 'w':{
            // must first check if out of bounds
            movementX = player->x;
            movementY = player->y - 1;
            try {
                stateToCheck = currMap->getStateOfCell(movementX, movementY);
            }catch(...){
                return 'X';
            }
            break;
        }
        case 'a':{
            // must first check if out of bounds
            movementX = player->x - 1;
            movementY = player->y;
            try {
                stateToCheck = currMap->getStateOfCell(movementX, movementY);
            }catch(...){
                return 'X';
            }
            break;
        }
        case 's':{
            // must first check if out of bounds
            movementX = player->x;
            movementY = player->y + 1;
            try {
                stateToCheck = currMap->getStateOfCell(movementX, movementY);
            }catch(...){
                return 'X';
            }
            break;
        }
        case 'd':{
            // must first check if out of bounds
            movementX = player->x + 1;
            movementY = player->y;
            try {
                stateToCheck = currMap->getStateOfCell(movementX, movementY);
            }catch(...){
                return 'X';
            }
            break;
        }
        case 'p':{
            stateToCheck = nullptr;
            bool exitGame;
            exitGame = pauseMenuUIandExitGame();
            if(exitGame){
                return 'S';
            }else{
                return 'C';
            }
        }
        default: {
            stateToCheck = nullptr;
            break;
        }
    }
    if(stateToCheck == nullptr){
        return 'X';
    }

    switch(stateToCheck->letter){
        case '.':{
            currMap->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            currMap->map.at(player->y).at(player->x)->characterInSpot = player;
            break;
        }
        case 'X':{
            std::cout << "--- A wall obstructs your way. ---" << std::endl;
            std::cout << "" << std::endl;
            break;
        }
        case 'D':{
            currMap->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            currMap->map.at(player->y).at(player->x)->characterInSpot = player;
            break;
        }
        case 'S':{
            currMap->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            currMap->map.at(player->y).at(player->x)->characterInSpot = player;
            break;
        }
        case 'E':{

            return 'E';
        }
        case 'C':{
            std::cout << "--- A chest is before you... open it? ('y' or 'n'):" << std::endl;
            std::cout << "" << std::endl;
            char openChestDecision;

            for (;;){
                try {
                    std::cin >> openChestDecision;
                    if(cin.fail()) {
                        std::cin.clear();
                        std::cin.ignore();
                        throw std::runtime_error("Invalid input. Please enter a character.");
                        continue;
                    }else if(openChestDecision != 'n' && openChestDecision != 'y'){
                        std::cin.clear();
                        std::cin.ignore();
                        continue;
                    }
                    break;
                } catch (...) {
                    std::cin.clear();
                    std::cin.ignore();
                }
            }

            if(openChestDecision == 'y'){
                std::cout << "--- Chest Contents ---" << std::endl;
                std::cout << "" << std::endl;
                TreasureChest * newChest;
                newChest = (TreasureChest *)currMap->map.at(movementY).at(movementX)->state;
                std::vector<Item> itemVector;
                itemVector = newChest->getContents();
                // TODO: this will handle if the player wants to obtain the items within the chest
                if(itemVector.empty()){
                    std::cout << "The chest is empty" << std::endl;
                    pause(2000);
                }else{
                    for(int i = 0; i < itemVector.size(); i++){
                        std::cout << "inside chest" << std::endl;
                        std::cout << "" << std::endl;
                    }
                }
                break;
            }else{
                break;
            }
        }
        default:{
            break;
        }
    }

    stateToCheck = nullptr;
    return 'C';
}

//shai's func
void createNewCampaign(){
    bool MadeCharacter = false, MadeMaps = false;
    int input;
    std::cin.clear();
    std::cin.ignore();
    while(!MadeMaps || !MadeCharacter){
        clearConsole();
        std::cout << "\n\nWould you like to:";
        if(!MadeCharacter){
            std::cout << "\n1. Create a character";
        }
        if(!MadeMaps){
            std::cout << "\n2. Create new Maps";
        }
        std::cout << "\n\nPlease input one of the numbers above: ";
        for (;;) {
            try {
                std::cin >> input;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                    continue;
                } else if (input != 1 && input != 2) {
                    continue;
                } else{
                    break;
                }
                
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }
        if(input == 1){
            MadeCharacter = true;
            //
        } else { //input == 2
            MadeMaps = true;
            vector<Map*> listOfMaps;
            bool keepMakingMaps = true, firstTime = true;
            while(keepMakingMaps){
                std::cout << "\nPlease input the size of the width for the map: ";
                int width, height;
                for (;;) {
                    try {
                        std::cin >> width;
                        if (cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore();
                            throw std::runtime_error("Invalid input. Please enter an integer: ");
                            continue;
                        } else if (width < 10) {
                            cout << "Input is too small. Try again: ";
                            continue;
                        } else{
                            break;
                        }
                        
                    } catch (...) {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                std::cout << width;
                std::cout << "\nPlease input the size of the height for the map: ";
                for (;;) {
                    try {
                        std::cin >> height;
                        if (cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore();
                            throw std::runtime_error("Invalid input. Please enter an integer: ");
                            continue;
                        } else if (height < 10) {
                            cout << "Input is too small. Try again: ";
                            continue;
                        } else{
                            break;
                        }
                        
                    } catch (...) {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                std::cout << height;
                if(firstTime){
                    MapCreator create(width,height);
                    firstTime = false;
                    width = 0; height = 0;
                } else {
                    std::cout << "here";
                    vector<int> prevEnd; 
                    std::cout << listOfMaps.back()->endY;
                    prevEnd.push_back(listOfMaps.back()->endY);
                    prevEnd.push_back(listOfMaps.back()->endX);
                    MapCreator create(width,height, prevEnd);
                    width = 0; height = 0;
                }
                std::cout << "Would you like to create another map? Type 1 for yes and 2 for no: ";
                int anotherMapInput;
                for (;;) {
                    try {
                        std::cin >> anotherMapInput;
                        if (cin.fail()) {
                            std::cin.clear();
                            std::cin.ignore();
                            throw std::runtime_error("Invalid input. Please enter an integer.");
                            continue;
                        } else if (anotherMapInput != 1 && anotherMapInput != 2) {
                            continue;
                        } else{
                            break;
                        }
                    } catch (...) {
                        std::cin.clear();
                        std::cin.ignore();
                    }
                }
                if(anotherMapInput == 2){
                    keepMakingMaps = false;
                    break;
                }
            }
        
        }

    }
}