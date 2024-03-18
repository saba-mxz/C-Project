#include <iostream>
#include <string>
#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    std::string name;
    std::string description;

public:
    Item(const std::string& name, const std::string& desc);
    std::string GetName() const;
    std::string GetDescription() const;
    void Interact() const;
};

#endif