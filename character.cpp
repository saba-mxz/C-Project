#include "character.h"


Character::Character(const std::string& name, int health)
        : name(name), health(health) {}

std::string Character::GetName() const {
    return name;
}

void Character::TakeDamage(int damage) {
    std::cout << "Taking Damage" << std::endl;
    health -= damage;
    if (health < 0) {
        health = 0;
    }
}

Player::Player(const std::string& name, int health)
        : Character(name, health), location(nullptr) {}

void Player::PickUpItem(const Item& item) {
    inventory.push_back(item);
    std::cout << "You picked up: " << item.GetName() << std::endl;
}

void Player::DisplayInventory() const {
    std::cout << "Inventory:" << std::endl;
    for (const Item& item : inventory) {
        std::cout << "- " << item.GetName() << std::endl;
    }
}

void Player::SetLocation(Room* room) {
    location = room;
}

Room* Player::GetLocation() const {
    return location;
}

