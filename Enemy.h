#ifndef ENEMY_H
#define ENEMY_H

#include <iostream>
#include <string>

class Player;

class Enemy {
public:
    Enemy(const std::string& name, int health, int attackDamage, int experience);

    const std::string& getName() const;
    int getHealth() const;
    int getAttackDamage() const;
    int getExperience() const;

    void attack(Player& player) const;

private:
    std::string name;
    int health;
    int attackDamage;
    int experience;
};

#endif 