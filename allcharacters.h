#ifndef CHARACTER_CLASSES_H
#define CHARACTER_CLASSES_H

/**
 * @file
 * @brief Header file defining playable character classes.
 * 
 * This file declares various character classes, each representing a playable character type in a role-playing game.
 * All classes inherit from the Character class and must implement the setHitPoints and setAttackBonus methods.
 *
 * All playable character classes, which are children of the Character class. Each class must implement the
 * setHitPoints and setAttackBonus methods.
 */

#include "Character.h"
#include <string>


/**
 * @brief Barbarian class declaration.
 * 
 * Represents a Barbarian character class.
 */
 
class Barbarian : public Character {
	
	public:
	
    explicit Barbarian(int levelToSet, std::string &name); /**< Constructor for Barbarian class. */
    Barbarian(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Barbarian. */
    void setAttackBonus() override; /**< Sets attack bonus for Barbarian. */
    
};


/**
 * @brief Bard class declaration.
 * 
 * Represents a Bard character class.
 */
class Bard : public Character {
	
	public:
	
    explicit Bard(int levelToSet, std::string &name); /**< Constructor for Bard class. */
    Bard(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Bard. */
    void setAttackBonus() override; /**< Sets attack bonus for Bard. */
    
};

/**
 * @brief Cleric class declaration.
 * 
 * Represents a Cleric character class.
 */
class Cleric : public Character {
public:
    explicit Cleric(int levelToSet, std::string &name); /**< Constructor for Cleric class. */
    Cleric(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Cleric. */
    void setAttackBonus() override; /**< Sets attack bonus for Cleric. */
};

/**
 * @brief Druid class declaration.
 * 
 * Represents a Druid character class.
 */
class Druid : public Character {
public:
    explicit Druid(int levelToSet, std::string &name); /**< Constructor for Druid class. */
    Druid(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Druid. */
    void setAttackBonus() override; /**< Sets attack bonus for Druid. */
};

/**
 * @brief Fighter class declaration.
 * 
 * Represents a Fighter character class.
 */
class Fighter : public Character {
public:
    explicit Fighter(int levelToSet, std::string &name); /**< Constructor for Fighter class. */
    Fighter(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Fighter. */
    void setAttackBonus() override; /**< Sets attack bonus for Fighter. */
};

/**
 * @brief Monk class declaration.
 * 
 * Represents a Monk character class.
 */
class Monk : public Character {
public:
    explicit Monk(int levelToSet, std::string &name); /**< Constructor for Monk class. */
    Monk(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Monk. */
    void setAttackBonus() override; /**< Sets attack bonus for Monk. */
};

/**
 * @brief Paladin class declaration.
 * 
 * Represents a Paladin character class.
 */
class Paladin : public Character {
public:
    explicit Paladin(int levelToSet, std::string &name); /**< Constructor for Paladin class. */
    Paladin(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Paladin. */
    void setAttackBonus() override; /**< Sets attack bonus for Paladin. */
};

/**
 * @brief Ranger class declaration.
 * 
 * Represents a Ranger character class.
 */
class Ranger : public Character {
public:
    explicit Ranger(int levelToSet, std::string &name); /**< Constructor for Ranger class. */
    Ranger(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Ranger. */
    void setAttackBonus() override; /**< Sets attack bonus for Ranger. */
};

/**
 * @brief Rogue class declaration.
 * 
 * Represents a Rogue character class.
 */
class Rogue : public Character {
public:
    explicit Rogue(int levelToSet, std::string &name); /**< Constructor for Rogue class. */
    Rogue(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Rogue. */
    void setAttackBonus() override; /**< Sets attack bonus for Rogue. */
};

/**
 * @brief Sorcerer class declaration.
 * 
 * Represents a Sorcerer character class.
 */
class Sorcerer : public Character {
public:
    explicit Sorcerer(int levelToSet, std::string &name); /**< Constructor for Sorcerer class. */
    Sorcerer(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Sorcerer. */
    void setAttackBonus() override; /**< Sets attack bonus for Sorcerer. */
};

/**
 * @brief Wizard class declaration.
 * 
 * Represents a Wizard character class.
 */
class Wizard : public Character {
public:
    explicit Wizard(int levelToSet, std::string &name); /**< Constructor for Wizard class. */
    Wizard(int levelToSet, std::string &name, int fighterType);
    void setHitPoints() override; /**< Sets hit points for Wizard. */
    void setAttackBonus() override; /**< Sets attack bonus for Wizard. */
};

#endif // CHARACTER_CLASSES_H
