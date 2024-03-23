#ifndef NPC_H
#define NPC_H

#include <iostream>
#include <string>

class NPC {
private:
    std::string name;
    std::string dialogue;
    int health;
    bool aggressive; // Flag to indicate if the NPC is aggressive

public:
    NPC(const std::string& name, const std::string& dialogue, int health = 100, bool aggressive = false);
    std::string GetName() const;
    std::string GetDialogue() const;
    void Talk() const;
    void TakeDamage(int damage);
    int GetHealth() const;
    bool IsAggressive() const; // Method to check if the NPC is aggressive
};

#endif // NPC_H
