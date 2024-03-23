
//Create an area class to represent the game world. An area contains rooms and manages connections between them.
//The class will help to organise the game world more effectively.
//Create a class called Area. The class should have the following members:
//A map to hold room objects where the string key is the room's name.

//A method called AddRoom that takes a room object and a string name as parameters. The method should add the room to the map using the name as the key.

//A method called GetRoom that takes a string name as a parameter and returns a pointer to the room with the given name. If the room does not exist, the method should return nullptr.

//A method called Connect that takes two string parameters, room1 and room2. The method should connect the two rooms by adding an exit from room1 to room2 and an exit from room2 to room1. The exits should be added using the AddExit method from the Room class.
#ifndef AREA_H
#define AREA_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "room.h"
#include "npc.h" // Include NPC class

class Area {
private:
    std::map<std::string, Room> rooms;
    std::map<std::string, NPC> npcs; // Map to hold NPCs

public:
    Area();
    void AddRoom(const std::string& name, const Room& room);
    void AddNPC(const std::string& name, const NPC& npc); // Method to add NPC
    Room* GetRoom(const std::string& name);
    NPC* GetNPC(const std::string& name); // Method to get NPC
    void Connect(const std::string& room1, const std::string& room2);
    void LoadMapFromFile(const std::string& filename);
    std::map<std::string, NPC>& GetNPCs(); // Getter for NPCs map
};

#endif // AREA_H
