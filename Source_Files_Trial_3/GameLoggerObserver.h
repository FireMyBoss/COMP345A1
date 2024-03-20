//
// Created by Nicholas Kamra on 3/19/24.
//
#pragma once
#ifndef DANDDCODE_GAMELOGGEROBSERVER_H
#define DANDDCODE_GAMELOGGEROBSERVER_H

#include "Observer.h"

class GameLoggerObserver : public Observer {
public:
    void update(Observable * observable) override;
};


#endif //DANDDCODE_GAMELOGGEROBSERVER_H
