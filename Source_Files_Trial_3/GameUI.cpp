//
// Created by Nicholas Kamra on 3/12/24.
//

#include "GameUI.h"
#include "MapCreator.h"



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
                clearConsole;

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

                Map* testMap = new Map();
                testMap -> generateInitialMapInfo();
                delete[] testMap;
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
    CharacterObserver * characterObserver = new CharacterObserver();
    MapObserver * mapObserver = new MapObserver();


    Character * characterForCreation = new Character();
    std::vector<Character *> characterVec;
    characterForCreation->createNewCharacter(characterVec);

    Character * newCharacter = characterVec.at(0);

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

    newMap->loadCharactersIntoMap(characterVec);

    while(play){

        std::cout << mapObserver->to_string(newMap) << std::endl;
        std::cout << characterObserver->to_string(newCharacter) << std::endl;

        bool exitGame;

        exitGame = newMap->getUserInput(newCharacter);
        clearConsole();
        if(exitGame){
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
    CharacterObserver * characterObserver = new CharacterObserver();
    MapObserver * mapObserver = new MapObserver();

    Map * newMap = ptrVectorOfAllMaps.at(0);
    Character * newCharacter = ptrVectorOfAllCharacters.at(0);

    newMap->loadCharactersIntoMap(ptrVectorOfAllCharacters);

    while(play){

        std::cout << mapObserver->to_string(newMap) << std::endl;
        std::cout << characterObserver->to_string(newCharacter) << std::endl;

        bool exitGame;

        exitGame = newMap->getUserInput(newCharacter);

        clearConsole();

        if(exitGame){
            delete newMap;
            play = false;
        }else{
            play = true;
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

void campaignSelectionUserInput(std::vector<std::string> & campaigns, const std::string & campaignDirectoryToAppend, std::vector<std::string> & allMapNamesInCampaign, std::vector<Map *> & ptrVectorOfAllMaps, std::vector<Character *> & ptrVectorOfAllCharacters){

    fs::path currentPath = fs::current_path();
    currentPath /= campaignDirectoryToAppend;

    std::cout << "Enter campaign name (just include the name without quotations): ";

    std::string campaignSelection;

    std::cin >> campaignSelection;

    bool campaignExists = false;

    fs::path campaignDirectory;

    for(std::string campaign : campaigns){
        if(campaign == campaignSelection){
            currentPath /= campaignSelection;
            campaignDirectory = currentPath; // This is the directory path inside a campaign
            campaignExists = true;
        }
    }

    if(campaignExists){
        if(fs::exists(currentPath) && fs::is_directory(currentPath)) {


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

            for(std::string campaign : mapNamesInCampaign){

                std::string currentCampaign = campaign;
                fs::path currentMapDirectory = mapDirectoryPath;
                currentMapDirectory /= currentCampaign;
                std::vector<std::vector<std::string> > newMapDataVector = getMapInformationInMapDirectory(currentMapDirectory);
                allMapsInCampaignDataVector.push_back(newMapDataVector);

            }

            for(int i = 0; i < allMapsInCampaignDataVector.size(); i++){
                Map * newMap = new Map(allMapsInCampaignDataVector.at(i));
                ptrVectorOfAllMaps.push_back(newMap);
            }

            // Creation for vector of all characters with character data
            std::vector<std::vector<std::string> > vectorOfAllCharacters;

            fs::path characterDirectoryPath = campaignDirectory;
            characterDirectoryPath /= "Characters";

            vectorOfAllCharacters = getCharacterInformationInCharacterDirectory(characterDirectoryPath);

            for(int i = 0; i < vectorOfAllCharacters.size(); i++){
                ptrVectorOfAllCharacters.push_back(buildCharacterFromSaveFile(vectorOfAllCharacters.at(i))); // changing parameter
            }

        }else{
            std::cout << "Error: Failure to load - campaign does not exist" << std::endl;
            return;
        }
    }else{
        std::cout << "Error: Campaign does not exist" << std::endl;
        std::cout << "" << std::endl;
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
            campaignSelectionUserInput(campaigns, campaignDirectory, mapNamesInCampaign, ptrVectorOfAllMaps, vectorOfAllCharacters);
            // TODO: the below function doesn't exit the game
            gameLoopLoadingCampaign(mapNamesInCampaign, ptrVectorOfAllMaps, vectorOfAllCharacters);
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

    MapObserver * mapObserver = new MapObserver();
    Map * newMap = new Map(60, 60);
    vecForCSV = mapToVectorForCSV(newMap);

    for(int i = 0; i < vecForCSV.size();i++){
        for(int j = 0; j < vecForCSV.at(i).size(); j++){
            std::cout << vecForCSV.at(i).at(j) << std::endl;
        }
    }

}

//shai's func
void createNewCampaign(){
    bool MadeCharacter = false, MadeMaps = false;
    int input;
    while(!MadeMaps && !MadeCharacter){
        std::cout << "\n\nWould you like to:";
        if(!MadeCharacter){
            MadeCharacter = true;
            std::cout << "\n1. Create a character";
        }
        if(!MadeMaps){
            MadeMaps = true;
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
                } else if (input != '1' && input != '2') {
                    continue;
                }
                break;
            } catch (...) {
                std::cin.clear();
                std::cin.ignore();
            }
        }
        if(input == 1){

        } else {
            bool keepMakingMaps = true;
            while(keepMakingMaps){
                std::cout << "Please input";
                MapCreator create();
            }
        }
        
    }

}