#include "Enemy.h"
#include "Player.h"




Enemy::Enemy(const std::string& name, int health, int attackDamage, int experience)
    : name(name), health(health), attackDamage(attackDamage), experience(experience) {}




const std::string& Enemy::getName() const {
    return name;
}



int Enemy::getHealth() const {
    return health;
}



int Enemy::getAttackDamage() const {
    return attackDamage;
}


int Enemy::getExperience() const {
    return experience;
}


void Enemy::attack(Player& player) const {

}