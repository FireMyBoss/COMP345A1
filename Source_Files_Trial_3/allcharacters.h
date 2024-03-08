#ifndef CHARACTER_CLASSES_H
#define CHARACTER_CLASSES_H

#include "Character.h"
#include <string>

/* All playable character classes, which are children of the Character class. Each class must implement the
 * setHitPoints and setAttackBonus methods.
*/

class Barbarian : public Character {
public:
    explicit Barbarian(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Bard : public Character {
public:
    explicit Bard(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Cleric : public Character {
public:
    explicit Cleric(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Druid : public Character {
public:
    explicit Druid(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Fighter : public Character {
public:
    explicit Fighter(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Monk : public Character {
public:
    explicit Monk(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Paladin : public Character {
public:
    explicit Paladin(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Ranger : public Character {
public:
    explicit Ranger(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Rogue : public Character {
public:
    explicit Rogue(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Sorcerer : public Character {
public:
    explicit Sorcerer(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

class Wizard : public Character {
public:
    explicit Wizard(int levelToSet, std::string &name);
    void setHitPoints() override;
    void setAttackBonus() override;
};

#endif // CHARACTER_CLASSES_H
