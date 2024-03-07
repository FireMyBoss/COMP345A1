//
// Created by Nicholas Kamra on 2/7/24.
//

#ifndef COMP_345_ASSIGNMENT_ONE_CHARACTER_H
#define COMP_345_ASSIGNMENT_ONE_CHARACTER_H
#include "GroupItemH.h"
#include <string>

class Character {
public:
    int y;
    int x;
    
    // Constructors
    Character();
    explicit Character(int levelToSet, std::string & name);


    // Getters
    std::string getCharacterClass() const;
    std::string getName() const;
    int getLevel() const;
    int getHitPoints() const;
    int getArmorClass() const;
    int getAttackBonus() const;
    int getDamageBonus() const;
    Helmet* getHelmet();
    Boots* getBoots();
    Armor* getArmor();
    Shield* getShield();
    Weapon* getWeapon();
    Ring* getRing();
    Belt* getBelt();
    int getStrengthScore() const;
    int getDexterityScore() const;
    int getConstitutionScore() const;
    int getIntelligenceScore() const;
    int getWisdomScore() const;
    int getCharismaScore() const;
    int getStrengthModifier() const;
    int getDexterityModifier() const;
    int getConstitutionModifier() const;
    int getIntelligenceModifier() const;
    int getWisdomModifier() const;
    int getCharismaModifier() const;

    // Setters
    void setCharacterClass(std::string newClassName);
    void setName(std::string & name);
    void setLevel(int level);
    virtual void setHitPoints();
    void setArmorClass();
    virtual void setAttackBonus();
    void setDamageBonus();
    void setHelmet(Helmet* helmetToSet);
    void setBoots(Boots* bootsToSet);
    void setArmor(Armor* armorToSet);
    void setShield(Shield* shieldToSet);
    void setWeapon(Weapon* weaponToSet);
    void setRing(Ring* ringToSet);
    void setBelt(Belt* beltToSet);
    void setStrengthScore(int strengthScoreForUpdate);
    void setDexterityScore(int dexterityScoreForUpdate);
    void setConstitutionScore(int constitutionScoreForUpdate);
    void setIntelligenceScore(int intelligenceScoreForUpdate);
    void setWisdomScore(int wisdomScoreForUpdate);
    void setCharismaScore(int charismaScoreForUpdate);
    void setStrengthModifier();
    void setDexterityModifier();
    void setConstitutionModifier();
    void setIntelligenceModifier();
    void setWisdomModifier();
    void setCharismaModifier();

protected:

    // Characteristics
    std::string characterClass;
    std::string name;
    int level;
    int hitPoints;
    int armorClass;
    int attackBonus;
    int damageBonus;

    // Armor
    Helmet* helmet;
    Boots* boots;
    Armor* armor;
    Shield* shield;
    Weapon* weapon;
    Ring* ring;
    Belt* belt;

    // Ability Scores
    int strengthScore;
    int dexterityScore;
    int constitutionScore;
    int intelligenceScore;
    int wisdomScore;
    int charismaScore;

    // Modifiers
    int strengthModifier;
    int dexterityModifier;
    int constitutionModifier;
    int intelligenceModifier;
    int wisdomModifier;
    int charismaModifier;
    int calculateModifier(int abilityScore);

};


#endif //COMP_345_ASSIGNMENT_ONE_CHARACTER_H
