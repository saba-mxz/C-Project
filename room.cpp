#include "room.h"

#pragma clang diagnostic push
#pragma clang diagnostic ignored "-Wc++11-extensions"
std::string Room::GetDescription() const {
    return description;
}
Room::Room(const std::string& description)
        : description(description) {}

const std::vector<Item>& Room::GetItems() const {
    return items;
}

std::vector<Item>& Room::GetItems() {
    return items;
}

void Room::AddItem(const Item& item)
{
    items.push_back(item);
    std::cout << "Item Added" << std::endl;
}

void Room::RemoveItem(const Item& item)
{
    std::cout << "Item Removed" << std::endl;
}

void Room::AddExit(const std::string& direction, Room* room) {
    exits[direction] = room;
}

Room* Room::GetExit(const std::string& direction) const {
    auto it = exits.find(direction);
    if (it != exits.end()) {
        return it->second;
    } else {
        return nullptr;
    }

}
#pragma clang diagnostic pop