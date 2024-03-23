//
// Created by Nicholas Kamra on 3/8/24.
//

#ifndef CHARACTER_CPP_CHARACTEROBSERVER_H
#define CHARACTER_CPP_CHARACTEROBSERVER_H

#include "Character.h"
#include "allcharacters.h"
#include "Observer.h"

class CharacterObserver : public Observer {
public:
    Character * character;
    explicit CharacterObserver(Character * character);
    std::string to_string();
    void update(Observable * observable) override;

};


#endif //CHARACTER_CPP_CHARACTEROBSERVER_H
