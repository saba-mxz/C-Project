#include "area.h"

// Adds a room to the area using its name as the key.
void Area::AddRoom(const std::string& name, Room* room) {
    rooms[name] = room;
}

// Returns a pointer to the room with the given name.
Room* Area::GetRoom(const std::string& name) const {
    auto it = rooms.find(name);
    if (it != rooms.end()) {
        return it->second;
    } else {
        return nullptr;
    }
}

// Connects two rooms using a specified direction, such as north.
void Area::ConnectRooms(const std::string& room1, const std::string& room2, const std::string& direction) {
    if (rooms.find(room1) != rooms.end() && rooms.find(room2) != rooms.end()) {
        rooms[room1]->AddExit(direction, rooms[room2]);
        rooms[room2]->AddExit(direction, rooms[room1]);
    }
}

