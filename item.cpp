#include "item.h"

Item::Item(const std::string& name, const std::string& description)
        : name(name), description(description) {}

std::string Item::GetName() const {
    return name;
}

std::string Item::GetDescription() const {
    return description;
}

void Item::Interact() const{
    std::cout << "You interacted with " << name << "." << std::endl;
    std::cout << "Description: " << description << std::endl;
}


