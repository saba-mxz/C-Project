#include <map>
#include <string>
#include <vector>
#include "room.h"
#include "item.h"
#include "character.h"

// Define private data members for the Area class.
class Area {
private:
    std::map<std::string, Room*> rooms;
    std::string name;
    std::string description;
    std::vector<Item> items;
    std::vector<Character> characters;

public:
    // Implement public member functions

    // Adds a room to the area using its name as the key.
    void AddRoom(const std::string& name, Room* room);

    // Returns a pointer to the room with the given name.
    Room* GetRoom(const std::string& name) const;

    // Connects two rooms using a specified direction, such as north.
    void ConnectRooms(const std::string& room1, const std::string& room2, const std::string& direction);

};


