#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>
#include "Item.h"
#include "Enemy.h"

class Room {
public:
    Room(const std::string& name, const std::string& description);

    const std::string& getName() const;
    const std::string& getDescription() const;

    void addItem(const Item& item);
    void removeItem(const std::string& itemName);
    const std::vector<Item>& getItems() const;

    void addEnemy(const Enemy& enemy);
    const std::vector<Enemy>& getEnemies() const;

    void describeRoomState() const;
    bool isFinalRoom() const;  // This is where you put the isFinalRoom function

private:
    std::string name;
    std::string description;
    std::vector<Item> items;
    std::vector<Enemy> enemies;
};

#endif // ROOM_H