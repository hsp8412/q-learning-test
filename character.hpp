#ifndef CHARACTER_H
#define CHARACTER_H

enum class Action
{
    ATTACK,
    MAGIC,
    FOCUS,
    SHIELD,
    BLOCK,
    HEAL,
};

class Character
{
public:
    Character(int max_health, int attack_strength);
    // get and set health
    int get_health();
    void take_damage(int demage);
    void take_healing(int healing);

    // get and set attack strength
    int get_attack_strength();
    void focused();

    // get action for the turn
    Action getAction();

private:
    int health;
    int max_health;
    int attack_strength;
};

class Player : public Character
{
public:
    Player(int max_health, int attack_strength);
};

class Enemy : public Character
{
public:
    Enemy(int max_health, int attack_strength);
};

#endif