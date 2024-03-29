//
// Created by Nicholas Kamra on 3/12/24.
//

#include "GameUI.h"
#include "MapCreator.h"
#
#include "Dice.h"

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
            
            	Map newMap;
              newMap.mapMenuDisplay();
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
        Observer * gameLoggerObserver = new GameLoggerObserver();
        selection = getUserInput(newCharacter, newMap, gameLoggerObserver);
        clearConsole();
        if(selection == 'S'){
            delete newMap;
            play = false;
        }else{
            play = true;
        }
    }

}
// TODO: this has been updated ------------------------
void gameLoopLoadingCampaign(std::vector<std::string> mapNamesInCampaign, std::vector<Map *> ptrVectorOfAllMaps, std::vector<Character *> ptrVectorOfAllCharacters){

    Game * currGame = new Game();
    Observer * gameLoggerObserver = new GameLoggerObserver();
    GameLoggerObserver * gameLoggerObserverDowncasted = dynamic_cast<GameLoggerObserver *>(gameLoggerObserver);

    gameLoggerObserverDowncasted->log("New game started.", currGame); // gameLogger Update

    clearConsole();

    bool play = true;

    int currMapIndex = 0;

    for(Map * map : ptrVectorOfAllMaps){
        Map * newMap = map;
        Observer * mapObserver = new MapObserver(newMap);
        newMap->attach(mapObserver);
        newMap->attach(gameLoggerObserver);
    }

    for(Character * character : ptrVectorOfAllCharacters){
        Character * newCharacter = character;
        Observer * characterObserver = new CharacterObserver(newCharacter);
        newCharacter->attach(characterObserver);
        newCharacter->attach(gameLoggerObserver);
    }

    Map * currMap = ptrVectorOfAllMaps.at(0);
    gameLoggerObserverDowncasted->log("New map is loading.", currMap); // gameLogger Update
    Character * currCharacter = ptrVectorOfAllCharacters.at(0);

    currMap->loadCharactersIntoMap(ptrVectorOfAllCharacters);
    gameLoggerObserverDowncasted->log("Characters loaded into map.", currMap); // gameLogger Update

    gameLoggerObserverDowncasted->log("It is " + currCharacter->getName() + " turn.", currCharacter); // gameLogger Update
    currMap->notify();

    while(play){

        // return 'E' for end and 'S' to stop game and 'X' for error and 'C' continue
        gameLoggerObserverDowncasted->log("It is " + currCharacter->getName() + " turn.", currCharacter); // gameLogger Update
        char selection;

        selection = getUserInput(currCharacter, currMap, gameLoggerObserver);

        clearConsole();

        currMap->notify();
        currCharacter->notify();

        gameLoggerObserverDowncasted->log("End of " + currCharacter->getName() + " turn.", currCharacter); // gameLogger Update

        if(selection == 'S'){
            std::ofstream gameLogFile("GameLog.txt");
            gameLogFile << "";
            play = false;
        }else if(selection == 'E'){

                currMapIndex++;

                if(ptrVectorOfAllMaps.size() - 1 < currMapIndex){
                    currMapIndex--;
                    continue;
                }
                currMap = ptrVectorOfAllMaps.at(currMapIndex);
                gameLoggerObserverDowncasted->log("New map is loading.", currMap); // gameLogger Update
                currMap->loadCharactersIntoMap(ptrVectorOfAllCharacters);
                gameLoggerObserverDowncasted->log("Characters loaded into map.", currMap); // gameLogger Update

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
        std::cout << "Enter '4' to enter NPC testing" << std::endl;

        char userSelection;

        for (;;) {
            try {
                std::cin >> userSelection;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter an integer.");
                    continue;
                } else if (userSelection != '1' && userSelection != '2' && userSelection != '3' && userSelection != '4') {
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
        		clearConsole();
            return;
        }else if (userSelection == '3'){
            creationTestsUI();
        } else if (userSelection == '4') {
        	
        	std::string userInput;
        	
        	clearConsole();
        	cout << "You are entering the NPC testing zone. Would you like to proceed?\nOption ('y' for yes, any key for no): \n\n";
        	
        	cin >> userInput;
        	
        	if(userInput == "y") {
        	
		      	EmojiMap newMap = EmojiMap(80,80);
		
						int npcY = 0;
						int npcX = 20;
						int npcState = 6;
						
						newMap.setNumberAtCell(npcState, npcY, npcX);
						
						int** NPCList = new int*[1];
						NPCList[0] = new int[3];
						
						NPCList[0][0] = npcY;
						NPCList[0][1] = npcX;
						NPCList[0][2] = npcState;
						
						
						newMap.runGame(NPCList, 1, 0);
						
						delete[] NPCList[0];
						
						delete[] NPCList;
        	
        	}
        	
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
void pauseMenuUnsubscribe(GameLoggerObserver * gameLoggerObserver){

    for(;;) {
        clearConsole();

        std::cout << "GameLogger Settings" << std::endl;
        std::cout << "-------------------" << std::endl;
        std::cout << std::endl;
        std::cout << "Press '1' to toggle the 'Game' log: ";
        bool gameExist = gameLoggerObserver->existsInSubscriberList("Game");
        if(gameExist){
            std::cout << "ON" << std::endl;
        }else{
            std::cout << "OFF" << std::endl;
        }
        std::cout << "Press '2' to toggle the 'Character' log: ";
        bool characterExist = gameLoggerObserver->existsInSubscriberList("Character");
        if(characterExist){
            std::cout << "ON" << std::endl;
        }else{
            std::cout << "OFF" << std::endl;
        }
        std::cout << "Press '3' to toggle the 'Map' log: ";
        bool mapExist = gameLoggerObserver->existsInSubscriberList("Map");
        if(mapExist){
            std::cout << "ON" << std::endl;
        }else{
            std::cout << "OFF" << std::endl;
        }
        std::cout << "Press '4' to toggle the 'Dice' log: ";
        bool diceExist = gameLoggerObserver->existsInSubscriberList("Dice");
        if(diceExist){
            std::cout << "ON" << std::endl;
        }else{
            std::cout << "OFF" << std::endl;
        }
        std::cout << "Press '5' to exit" << std::endl;

        char playerInputChar;

        for (;;) {
            try {
                std::cin >> playerInputChar;
                if (cin.fail()) {
                    std::cin.clear();
                    std::cin.ignore();
                    throw std::runtime_error("Invalid input. Please enter a character.");
                    continue;
                } else if (playerInputChar != '1' && playerInputChar != '2' && playerInputChar != '3'
                           && playerInputChar != '4' && playerInputChar != '5') {
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

        switch (playerInputChar) {
            case '1': {
                gameLoggerObserver->changeSubscription("Game");
                break;
            }
            case '2': {
                gameLoggerObserver->changeSubscription("Character");
                break;
            }
            case '3': {
                gameLoggerObserver->changeSubscription("Map");
                break;
            }
            case '4': {
                gameLoggerObserver->changeSubscription("Dice");
                break;
            }
            case '5': {
                return;
            }
            default: {
                break;
            }
        }
    }
}
bool pauseMenuUIandExitGame(GameLoggerObserver * gameLoggerObserver){

    clearConsole();

    std::cout << "Pause Menu" << std::endl;
    std::cout << "----------" << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter '1' to unpause" << std::endl;
    std::cout << "Enter '2' to exit game" << std::endl;
    std::cout << "Enter '3' to change log information" << std::endl;

    char playerInputChar;

    for (;;){
        try {
            std::cin >> playerInputChar;
            if(cin.fail()) {
                std::cin.clear();
                std::cin.ignore();
                throw std::runtime_error("Invalid input. Please enter a character.");
                continue;
            }else if(playerInputChar != '1' && playerInputChar != '2' && playerInputChar != '3'){
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
        case '3':{
            pauseMenuUnsubscribe(gameLoggerObserver);
            return false;
        }
        default:{
            break;
        }
    }
    return false;
}
char getUserInput(Character * player, Map * currMap, Observer * gameLoggerObserver){ // return 'E' for end and 'S' to stop game and 'X' for error and 'C' continue

    GameLoggerObserver * gameLoggerObserverCasted = (GameLoggerObserver *)gameLoggerObserver;

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

                // TODO: testing this here -------------------------------
                std::string toLog = player->getName() + " has moved up.";
                gameLoggerObserverCasted->log(toLog, player);
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

                // TODO: testing this here -------------------------------
                std::string toLog = player->getName() + " has moved left.";
                gameLoggerObserverCasted->log(toLog, player);
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

                // TODO: testing this here -------------------------------
                std::string toLog = player->getName() + " has moved down.";
                gameLoggerObserverCasted->log(toLog, player);
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

                // TODO: testing this here -------------------------------
                std::string toLog = player->getName() + " has moved right.";
                gameLoggerObserverCasted->log(toLog, player);
            }catch(...){
                return 'X';
            }
            break;
        }
        case 'p':{
            stateToCheck = nullptr;
            bool exitGame;
            exitGame = pauseMenuUIandExitGame(gameLoggerObserverCasted);
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
            // TODO: testing this here -------------------------------
            std::string toLog = player->getName() + " has bumped into a wall.";
            gameLoggerObserverCasted->log(toLog, player);
            break;
        }
        case 'D':{
            currMap->map.at(player->y).at(player->x)->characterInSpot = nullptr;
            player->x = movementX;
            player->y = movementY;
            currMap->map.at(player->y).at(player->x)->characterInSpot = player;
            // TODO: testing this here -------------------------------
            std::string toLog = player->getName() + " has opened a door.";
            gameLoggerObserverCasted->log(toLog, player);
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
                // TODO: testing this here -------------------------------
                std::string toLog = player->getName() + " has opened a chest.";
                gameLoggerObserverCasted->log(toLog, player);
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
            std::vector<Character*> listOfCharacters; // this is the list that contains the character
            Character *newCharacter = new Character();
            newCharacter->createNewCharacter(listOfCharacters);
        } else { //input == 2
            MadeMaps = true;
            vector<Map*> listOfMaps;
            bool keepMakingMaps = true, firstTime = true;
            int width, height;
            while(keepMakingMaps){
                std::cout << "\nPlease input the size of the width for the map: ";
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
                cout << endl; 
                if(firstTime){
                    MapCreator create(width,height);
                    listOfMaps.push_back(create.returnMap());
                    firstTime = false;
                    width = 0; height = 0;
                } else {
                    vector<int> prevEnd; 
                    std::cout << listOfMaps.back()->endY;
                    prevEnd.push_back(listOfMaps.back()->endY);
                    prevEnd.push_back(listOfMaps.back()->endX);
                    MapCreator create(width,height, prevEnd);
                    listOfMaps.push_back(create.returnMap());
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
