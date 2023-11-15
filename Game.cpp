#include "Game.h"

Room* Game::createRoom(const std::string& name, const std::string& description) {
    rooms.emplace_back(name, description);
    return &rooms.back();
}

Room* Game::changeRoom(Room* currentRoom) {
    size_t index = 0;
    for (size_t i = 0; i < rooms.size(); ++i) {
        if (&rooms[i] == currentRoom) {
            index = i;
            break;
        }
    }

    index = (index + 1) % rooms.size();
    return &rooms[index];
}