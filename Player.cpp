#include "Enemy.h"
#include "Player.h"
#include "Item.h"  // Aseg�rate de incluir el archivo de encabezado de Item

Player::Player(const std::string& playerName, int initialHealth, int initialLives)
    : name(playerName), health(initialHealth), lives(initialLives) {
}

const std::string& Player::getName() const {
    return name;
}

int Player::getHealth() const {
    return health;
}

int Player::getLives() const {
    return lives;
}

void Player::pickUpItem(const Item& item) {

    std::cout << "Has recogido el item: " << item.getName() << "!" << std::endl;
}

void Player::attack(const Enemy& enemy) {

    std::cout << "Atacaste al enemigo: " << enemy.getName() << "!" << std::endl;
}