// Declaraci�n adelantada de la clase Item
class Item;

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>

class Enemy;

class Player {
public:
    Player(const std::string& name, int health, int lives);

    const std::string& getName() const;
    int getHealth() const;
    int getLives() const;

    void pickUpItem(const Item& item);
    void attack(const Enemy& enemy);

private:
    std::string name;
    int health;
    int lives;

};

#endif // PLAYER_H