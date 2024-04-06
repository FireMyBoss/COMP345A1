
#ifndef COMP_345_ASSIGNMENT_ONE_CHARACTER_H
#define COMP_345_ASSIGNMENT_ONE_CHARACTER_H
#include "GroupItemH.h"
#include <string>
#include "misc.h"
#include "Observable.h"


/* Playable character types are as follows: Barbarian, Cleric, Druid, Fighter, Monk, Paladin, Ranger, Rogue, Sorcerer,
 * Wizard, and Bard. Each character has characteristics, ability scores, and modifiers for each ability. For player
 * characteristics, we have the following: characterClass, name, level, hitPoints, armorClass, attackBonus, and
 * damageBonus. The calculations are:
 * characterClass: decided by user before instantiation of a Character object.
 * name: defined by the user during construction of a character; default construction sets it to "".
 * level: defined by the user during construction of a character; default construction sets it to 0.
 * hitPoint: set to the character's constitution modifier + the top roll of a class's hit die can have. The
 *     D20 rules is to sum constitution modifier by hit die roll.
 * armorClass: set to the character's dexterity modifier + 10; this is D20 specific rule.
 * attackBonus: set to the character class's strength modifier.
 * damageBonus: set to the character's strength modifier.
 * All ability scores were randomly generated between the values 3 and 18 using a RNG.
 * Ability modifiers were calculated by taking the respective ability score, subtracting 10, dividing by 2,
 * and then taking the floor of the result. The following equation represents the calculation:
 * floor((abilityScore - 10) / 2).
*/
class Character : public Observable {
public:

    // Player coordinates
    int x;
    int y;

    bool isEnemy;

    void updateCharacterCoords(int x, int y);

    // Constructors
    Character();
    explicit Character(int levelToSet, std::string & name);
    Character(int levelToSet, std::string & name, int type);
    Character(int levelToSet, std::string & name, bool isEnemy);

    int fighterType;
    std::string fighterTypeName;

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

    void setStrengthModifier(int strengthModifierUpdate);
    void setDexterityModifier(int dexterityModifierUpdate);
    void setConstitutionModifier(int constitutionModifierUpdate);
    void setIntelligenceModifier(int intelligenceModifierUpdate);
    void setWisdomModifier(int wisdomModifierUpdate);
    void setCharismaModifier(int charismaModifierUpdate);
    void setHitPoints(int hitPointsUpdate);
    void setArmorClass(int armorClassUpdate);
    void setAttackBonus(int attackBonusUpdate);
    void setDamageBonus(int damageBonusUpdate);

    // UI for menu
    void printCharacter(Character* character);
    Character* createNewCharacter(std::vector<Character*> & createdCharacterArray);
    void displayCreatedCharacterList(std::vector<Character*> & createdCharacterArray);
    void createCharacterInterface();

protected:

    void abstractPure() override {};

    // Inventory
    std::vector<Item *> characterInventory;

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
Character * buildCharacterFromSaveFile(std::vector<std::string> characterInformation);

#endif //COMP_345_ASSIGNMENT_ONE_CHARACTER_H
