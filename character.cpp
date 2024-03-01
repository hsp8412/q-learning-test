#include <string>
#include "character.hpp"
#include <random>
using namespace std;

Character::Character(int max_health, int attack_strength)
{
    this->health = max_health;
    this->max_health = max_health;
    this->attack_strength = attack_strength;
};

int Character::get_health()
{
    return this->health;
}

void Character::take_damage(int damage)
{
    if (health - damage > 0)
    {
        this->health -= damage;
    }
    else
    {
        this->health = 0;
    }
}

void Character::take_healing(int healing)
{
    if (this->health + healing < this->max_health)
    {
        this->health += healing;
    }
    else
    {
        this->health = this->max_health;
    }
}

int Character::get_attack_strength()
{
    return this->attack_strength;
}

void Character::focused()
{
    this->attack_strength *= 2;
}

Action Character::getAction()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(0, 5);

    int random_value = distr(gen);
    return static_cast<Action>(random_value);
}

Player::Player(int max_health, int attack_strength) : Character(max_health, attack_strength){};

Enemy::Enemy(int max_health, int attack_strength) : Character(max_health, attack_strength){};
