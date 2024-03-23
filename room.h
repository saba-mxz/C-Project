#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "item.h"

class Room {
private:
    std::string description;
    std::map<std::string, Room*> exits;
    std::vector<Item> items;

public:
    Room(const std::string& desc);
    Room(){}; // default constructor
    std::string GetDescription() const;

    const std::vector<Item>& GetItems() const;
    std::vector<Item>& GetItems();
    void AddItem(const Item& item);
    void SetDescription(const std::string& desc);
    void RemoveItem(const Item& item);
    void AddExit(const std::string& direction, Room* room);
    Room* GetExit(const std::string& direction) const;
    std::map<std::string, Room*> GetExits() const;

};

#endif // ROOM_H
