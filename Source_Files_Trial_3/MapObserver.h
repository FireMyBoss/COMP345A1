//
// Created by Nicholas Kamra on 3/18/24.
//
#pragma once
#ifndef DANDDCODE_MAPOBSERVER_H
#define DANDDCODE_MAPOBSERVER_H

#include "Observer.h"
#include <string>
#include <iostream>
#include "Map.h"

class MapObserver : public Observer {
public:
    explicit MapObserver(Map * map);
    Map * map;
    void update(Observable * observable) override;
    std::string to_string();
};


#endif //DANDDCODE_MAPOBSERVER_H
