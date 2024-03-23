#include "area.h"
#include "room.h"
#include "item.h"
#include <fstream>
#include <sstream>

Area::Area() {}

void Area::AddRoom(const std::string& name, const Room& room) {
    rooms[name] = room;
}

void Area::AddNPC(const std::string& name, const NPC& npc) {
    npcs[name] = npc;
}

Room* Area::GetRoom(const std::string& name) {
    auto it = rooms.find(name);
    if (it != rooms.end()) {
        return &(it->second);
    }
    return nullptr;
}

NPC* Area::GetNPC(const std::string& name) {
    auto it = npcs.find(name);
    if (it != npcs.end()) {
        return &(it->second);
    }
    return nullptr;
}

void Area::Connect(const std::string& room1, const std::string& room2) {
    Room* r1 = GetRoom(room1);
    Room* r2 = GetRoom(room2);
    if (r1 && r2) {
        r1->AddExit(room2);
        r2->AddExit(room1);
    } else {
        std::cerr << "One or both rooms not found!" << std::endl;
    }
}


void Area::LoadMapFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    std::string currentRoomName; // Track the current room being processed
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string key;
        if (std::getline(iss, key, ':')) {
            if (key == "room") {
                std::string roomName;
                if (std::getline(iss, roomName)) {
                    Room room("You are in " + roomName);
                    rooms[roomName] = room;
                    currentRoomName = roomName; // Update current room
                }
            } else if (key == "description") {
                std::string description;
                if (std::getline(iss, description)) {
                    rooms[currentRoomName].SetDescription(description); // Set room description
                }
            } else if (key == "items") {
                std::string items;
                if (std::getline(iss, items)) {
                    std::istringstream itemStream(items);
                    std::string item;
                    while (std::getline(itemStream, item, ',')) {
                        Item newItem(item, "You see a " + item + ".");
                        rooms[currentRoomName].AddItem(newItem); // Add item to the current room
                    }
                }
            } else if (key == "exits") {
                std::string exits;
                if (std::getline(iss, exits)) {
                    std::istringstream exitStream(exits);
                    std::string exit;
                    while (std::getline(exitStream, exit, ',')) {
                        std::string direction;
                        std::string roomName;
                        if (std::getline(exitStream, direction, '=')) {
                            if (std::getline(exitStream, roomName, '=')) {
                                if (rooms.find(roomName) != rooms.end()) {
                                    Connect(currentRoomName, roomName); // Connect current room to the specified room
                                }
                                std::map<std::string, NPC> &Area::GetNPCs() {
                                    return npcs;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

