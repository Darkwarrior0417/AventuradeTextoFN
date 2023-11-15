#ifndef GAME_H
#define GAME_H

#include <vector>
#include "Room.h"

class Game {
public:
    Room* createRoom(const std::string& name, const std::string& description);
    Room* changeRoom(Room* currentRoom);

private:
    std::vector<Room> rooms;
};

#endif // GAME_H