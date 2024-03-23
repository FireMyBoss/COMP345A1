#include "GroupItemH.h"
#include <string>
#include "misc.h"
#include "Character.h"
#include "Dice.h"
#include <cstdlib>

void setFighterType(Character *Fighter, int type){  // 0 = Bully, 1 = Nimble, 2 = Tank
    Fighter -> fighterType = type;
    Dice d(3, 6, 0);
    vector<int> attributes;
    for(int i = 0; i < 6; i++){ //for six attributes
        attributes.push_back(d.roll());
    }
    sort(attributes.begin(), attributes.end()); 
    switch (type)
    {
    case 0: //bully
        Fighter->fighterTypeName = "Bully";
        Fighter->setStrengthScore(attributes[5]);
        Fighter->setConstitutionScore(attributes[4]);
        Fighter->setDexterityScore(attributes[3]);
        break;
    case 1: //Nimble
        Fighter->fighterTypeName = "Nimble";
        Fighter->setDexterityScore(attributes[5]);
        Fighter->setConstitutionScore(attributes[4]);
        Fighter->setStrengthScore(attributes[3]);
        break;
    case 2: //Tank
        Fighter->fighterTypeName = "Tank";
        Fighter->setConstitutionScore(attributes[5]);
        Fighter->setDexterityScore(attributes[4]);
        Fighter->setStrengthScore(attributes[3]);
        break;
    default:
        break;
    }
    Fighter->setIntelligenceScore(attributes[2]);
    Fighter->setCharismaScore(attributes[1]);
    Fighter->setWisdomScore(attributes[0]);
}

void setFighterType(Character *Fighter){ //makes a random Fighter, calls ^
    setFighterType(Fighter, getCurrentTime()/100000 %3);
} 

