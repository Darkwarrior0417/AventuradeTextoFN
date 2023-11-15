
#include "Room.h"
#include "Item.h"  
#include "Enemy.h" 

Room::Room(const std::string& name, const std::string& description)
    : name(name), description(description) {}

const std::string& Room::getName() const {
    return name;
}

const std::string& Room::getDescription() const {
    return description;
}

void Room::addItem(const Item& item) {
    items.push_back(item);
}

void Room::removeItem(const std::string& itemName) {
    items.erase(std::remove_if(items.begin(), items.end(),
        [&](const Item& item) { return item.getName() == itemName; }),
        items.end());
}

const std::vector<Item>& Room::getItems() const {
    return items;
}

void Room::addEnemy(const Enemy& enemy) {
    enemies.push_back(enemy);
}

const std::vector<Enemy>& Room::getEnemies() const {
    return enemies;
}

void Room::describeRoomState() const {
    std::cout << "Estas en: " << name << "\n";
    std::cout << "Descripcion: " << description << "\n";

    if (!items.empty()) {
        std::cout << "Puedes ver los siguientes �tems en este lugar:\n";
        for (const auto& item : items) {
            std::cout << "- " << item.getName() << ": " << item.getDescription() << "\n";
        }
    }

    if (!enemies.empty()) {
        std::cout << "Cuidado! Hay enemigos en este lugar:\n";
        for (const auto& enemy : enemies) {
            std::cout << "- " << enemy.getName() << " (Salud: " << enemy.getHealth() << ")\n";
        }
    }

    std::cout << "-----------------------------\n";
}

bool Room::isFinalRoom() const {
    // Choose either "Tilted" or "Black Hole" based on your game logic
    return name == "Black Hole";
}