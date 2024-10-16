#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include "Item.h" //Includes the header file for "Item.h"
#include "Room.h" //Includes the header file for "Room.h"
#include "Character.h" //Includes the header file for "Character.h"


//Character class


//New features are hitpoints and experience
Character::Character(std::string& name, int health, int hitpoints, int experience) : name(name), health(health), hitpoints(hitpoints), experience(experience) {}
/*
Constructor for Character class, intitializes member variables name, health, hitpoints and experience with values passed as name, health, hitpoints and experience
*/
void Character::PrintStats() { //A function to output the player stats
	std::cout << "\nYou have a health of " << health << " and a shield health of " << hitpoints << " and a level of " << experience / 20 + 1 << " with an XP of " << experience << ".\n" << std::endl;
	//Outputs the players stats
}
void Character::TakeDamage(int damage) { //New feeature: A function to idecrease health on player
	health = health - damage; //Minuses the players health
	if (health > 0) { //Checks if player health is greater than 0
		std::cout << "\nYou have taken " << damage << " damage. Your health is: " << health << std::endl;
		//Outputs a message saying the damage to the player done and current health
	}
	else {
		health = 0; //Sets health to 0
		std::cout << "\nYou died! Better luck next time." << std::endl; //Outputs a message to the player saying that they have died
		std::exit(0); //Exits the game
	}
}
void Character::RegainHealth(int regeneration) { //New feeature: A function to increase health on player
	health = health + regeneration; //Adds the players health
	if (health <= 100) { //Checks if health is less than 100
		std::cout << "\nYou have recovered " << regeneration << " health. Your health is: " << health << std::endl;
		//Outputs a message saying the health recovered and current health
	}
	else {
		health = 100; //Sets health to 100
		std::cout << "\nYou are at max health of 100." << std::endl; //Outputs a message to the player saying that they are at max health
	}
}
void Character::Shield_System(int shield_points) { //New feature: A function to increase/decrease health on player shield
	hitpoints = hitpoints + shield_points; //Changes the hitpoint count for the player
	if (hitpoints < 0) { //Checks if hitpoints is less than 100
		hitpoints = 0; //hitpoints is set to 0
		std::cout << "\nYou have 0 health left on your shield." << std::endl; //Outputs a message saying there is min. 0 hitpoints on the shield
	}
	else if (hitpoints > 100) { //Checks if hitpoints is less than 100
		hitpoints = 100; //hitpoints is set to 100
		std::cout << "\nYou are at max hitpoints of 100 on your shield." << std::endl; //Outputs a message saying there is max. 100 hitpoints on the shield
	}
	else {
		std::cout << "\nYou have: " << hitpoints << " hitpoints on your shield." << std::endl; //Outputs a message of the number of hitpoints on the player shield
	}
}
void Character::ExperiencePoints(int experience_points) { //New feature: 
	experience = experience + experience_points;
	std::cout << "\n" << experience_points << " points added!" << std::endl;
	std::cout << "You are at Level: " << 1 + experience / 20 << " with a total XP of: " << experience << std::endl;
}
void Character::AddToInventory(Item& newItem) { //New feature: Max amount of item to add in player inventory through function
	if (inventory.size() < 2) { //Checks if the size of the inventory is less than 2
		inventory.emplace_back(newItem); //Adds the new item
		std::cout << "\nAmount of items in inventory: " << inventory.size() << "\n" << std::endl;
		//Outputs the amount of items in inventory
	}
	else {
		std::cout << "\nAmount of items in inventory: " << inventory.size() << "\n" << std::endl;
		//Outputs the amount of items in inventory
		std::cout << "\nYou have reached the maximum amount of items (which is 2) in your inventory and cannot add anymore items.\n" << std::endl;
		//Outputs a message saying max. items are 2
	}
}
void Character::RemoveFromInventory(Item& item) { //New feature: A function to remove items from the player inventory
	for (unsigned int i = 0; i < inventory.size(); i++) { //Parses through the inventory
		if (this->inventory[i] == item) { //Checks if this is the item to remove from the players inventory
			inventory.erase(inventory.begin() + i); //Removes the item from the player inventory
		}
	}
}
std::string& Character::GetName() { //A function to get the name of the player
	return name; //Returns the name of the player
}
std::vector<Item>& Character::GetInventory() { //A function to get the players inventory
	return inventory; //Returns the players inventory
}

//New features: Hitpoints and experience
Player::Player(std::string name, int health, int hitpoints, int experience) : Character(name, health, hitpoints, experience) {}
/*
Constructor for Player class, which is derived from the Character class. The base class with the attributes name, health, hitpoints and experience are initialized
*/
Room* Player::GetLocation() { //A function to get the location of the player
	return location; //Returns the location
}
void Player::SetLocation(Room* newLocation) { //A function to set the new location
	location = newLocation; //Sets newLocation to the current location
}
