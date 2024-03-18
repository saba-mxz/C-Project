
#include <iostream>
#include <string>
#include <vector>
#include "item.h"
#include "room.h"

class Character {
private:
    std::string name;
    int health;
    std::vector<Item> inventory;

public:
    Character(const std:: string& name, int health);
    std::string GetName() const;
    virtual void TakeDamage(int damage);
};

class Player : public Character {
private:
    Room* location;
    std::vector<Item> inventory;


public:
    Player(const std::string& name, int health);
    void PickUpItem(const Item& item);
    void DisplayInventory() const;
    void SetLocation(Room* room);
    Room* GetLocation() const;


};
