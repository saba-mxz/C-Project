#include <iostream>
#include <vector>
#include "character.h"
#include "area.h"
int main() {
    // Create an instance of the Area class
    Area gameWorld;
    // Load the game map from a text file
    gameWorld.LoadMapFromFile("game_map.txt");

    // Get the starting room from the loaded map
    Room* startRoom = gameWorld.GetRoom("start");

    if (!startRoom) {
        std::cerr << "Error: Unable to find the starting room." << std::endl;
        return 1;
    }

    // Create a Player
    Player player("Alice", 100);

    // Set the player's starting location
    player.SetLocation(startRoom);

    // Game loop (basic interaction)
    while (true) {
        std::cout << "Current Location: " << player.GetLocation()->GetDescription() << std::endl;
        std::cout << "Items in the room:" << std::endl;

        // Display items in the room
        for (const Item& item : player.GetLocation()->GetItems()) {
            std::cout << "- " << item.GetName() << ": " <<
                      item.GetDescription() << std::endl;
        }

        // Display NPCs in the room
        for (const auto& entry : gameWorld.GetNPCs()) {
            std::cout << "- " << entry.first << std::endl;
        }

        std::cout << "Options: ";
        std::cout << "1. Look around | ";
        std::cout << "2. Interact with an item | ";
        std::cout << "3. Talk to an NPC | "; // New option to talk to NPCs
        std::cout << "4. Move to another room | ";
        std::cout << "5. Attack an NPC | "; // New option to attack NPCs
        std::cout << "6. Quit" << std::endl;

        int choice;
        std::cin >> choice;

        if (choice == 1) {
            // Player looks around (no action required)
            std::cout << "You look around the room." << std::endl;
        } else if (choice == 2) {
            // Player interacts with an item in the room
            // Code for interacting with items...
        } else if (choice == 3) {
            // Player talks to an NPC in the room
            std::cout << "Enter the name of the NPC you want to talk to:";
            std::string npcName;
            std::cin >> npcName;
            NPC* npc = gameWorld.GetNPC(npcName);
            if (npc) {
                npc->Talk();
            } else {
                std::cout << "No NPC with that name found." << std::endl;
            }
        } else if (choice == 4) {
            // Player moves to another room
            // Code for moving to another room...
        } else if (choice == 5) {
            // Attack an NPC
            std::cout << "Enter the name of the NPC you want to attack:";
            std::string npcName;
            std::cin >> npcName;
            NPC* npc = gameWorld.GetNPC(npcName);
            if (npc) {
                // Check if the NPC is aggressive
                if (npc->IsAggressive()) {
                    // Calculate damage and subtract from NPC's health
                    int damage = 20; // For example, you can calculate damage based on player's attributes
                    npc->TakeDamage(damage);
                    // Check if the NPC is defeated
                    if (npc->GetHealth() <= 0) {
                        std::cout << "You defeated " << npc->GetName() << "!" << std::endl;
                        // Remove the defeated NPC from the room
                        gameWorld.RemoveNPC(npcName);
                    } else {
                        std::cout << "You attacked " << npc->GetName() << "!" << std::endl;
                    }
                } else {
                    std::cout << npc->GetName() << " is not aggressive." << std::endl;
                }
            } else {
                std::cout << "No NPC with that name found." << std::endl;
            }
        } else if (choice == 6) {
            // Quit the game
            break;
        }
    }

    return 0;
}

