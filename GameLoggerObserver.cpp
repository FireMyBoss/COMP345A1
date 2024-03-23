//
// Created by Nicholas Kamra on 3/19/24.
//

#include "GameLoggerObserver.h"

GameLoggerObserver::GameLoggerObserver() {
    subscriberList = {"Character", "Map", "Dice", "Game"};
}

// TODO: this has been updated ----------------------- the parameter needs to include a string that will be logged
void GameLoggerObserver::update(Observable * observable){
    std::ofstream gameLogFile("GameLog.txt", std::ios::app);
    std::string stringToLog = "";
    if(gameLogFile.is_open()){
        gameLogFile << stringToLog; // TODO: stringToLog should be a parameter
    }else
        return;
}
void GameLoggerObserver::log(std::string stringToLog, Observable * typeOfObservable){
    if(Character * curr = dynamic_cast<Character *>(typeOfObservable)){
        if(!existsInSubscriberList("Character"))
            return;
    }else if(Map * curr = dynamic_cast<Map *>(typeOfObservable)){
        if(!existsInSubscriberList("Map"))
            return;
    }else if(Dice * curr = dynamic_cast<Dice *>(typeOfObservable)){
        if(!existsInSubscriberList("Dice"))
            return;
    }else if(Game * curr = dynamic_cast<Game *>(typeOfObservable)){
        if(!existsInSubscriberList("Game"))
            return;
    }

    std::ofstream gameLogFile("GameLog.txt", std::ios::app);
    if(gameLogFile.is_open()){
        gameLogFile << stringToLog << "\n"; // TODO: stringToLog should be a parameter
    }else
        return;
}
bool GameLoggerObserver::existsInSubscriberList(std::string type){
    for(std::string subscriber : subscriberList){
        if(subscriber == type){
            return true;
        }
    }
    return false;
}
void GameLoggerObserver::changeSubscription(std::string stringToChange){
    if(existsInSubscriberList(stringToChange)){
        for(int i = 0; i < subscriberList.size(); i++){
            if(subscriberList.at(i) == stringToChange){
                subscriberList.erase(subscriberList.begin() + i);
            }
        }
    }else{
        subscriberList.push_back(stringToChange);
    }
}