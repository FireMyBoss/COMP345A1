//
// Created by Nicholas Kamra on 3/19/24.
//
#pragma once
#ifndef DANDDCODE_GAMELOGGEROBSERVER_H
#define DANDDCODE_GAMELOGGEROBSERVER_H

#include "Observer.h"
#include <fstream>
#include <iostream>
#include "Character.h"
#include "Dice.h"
#include "Map.h"
#include "Game.h"

// TODO: this has been updated ------------------
class GameLoggerObserver : public Observer {
public:
    GameLoggerObserver();
    void update(Observable * observable) override;
    void log(std::string stringToLog, Observable * typeOfObservable);
    std::vector<std::string> subscriberList;
    bool existsInSubscriberList(std::string type);
    void changeSubscription(std::string stringToChange);
};


#endif //DANDDCODE_GAMELOGGEROBSERVER_H
