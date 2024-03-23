#include "npc.h"

NPC::NPC(const std::string& name, const std::string& dialogue, int health, bool aggressive)
        : name(name), dialogue(dialogue), health(health), aggressive(aggressive) {}

std::string NPC::GetName() const {
    return name;
}

std::string NPC::GetDialogue() const {
    return dialogue;
}

void NPC::Talk() const {
    std::cout << name << ": " << dialogue << std::endl;
}

void NPC::TakeDamage(int damage) {
    health -= damage;
    if (health <= 0) {
        std::cout << name << " has been defeated!" << std::endl;
    }
}

int NPC::GetHealth() const {
    return health;
}

bool NPC::IsAggressive() const {
    return aggressive;
}
