#pragma once //Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <vector> //Allows for working with dynamic arrays (vectors)
#include "Item.h" //Includes the header file for "Item.h"


//Character class and Player class

/*
//New features are hitpoints and experience
*/

class Character {
private:
	std::string name; //String used to name the character
	int health; //Integer to give the health
	int hitpoints; //Integer to give the hitpoints on the shield
	int experience; //Integer to give the XP (experience) points
	std::vector<Item> inventory; //A vector which contains the character inventory of items
public:
	Character(std::string& name, int health, int hitpoints, int experience); //Constructor for character class
	void PrintStats(); //A function to output the chracter stats (health, shield hitpoints, level, and XP) 
	void TakeDamage(int damage); //A function to decrease character health
	void RegainHealth(int regeneration); //A function to increase character health
	void Shield_System(int hitpoints); //A funtion to increase or decrease the characters shield hitpoints
	void ExperiencePoints(int experience); //A function to add experience points to the character
	void AddToInventory(Item& newItem); //A function to add items to the characters inventory
	void RemoveFromInventory(Item& item); //A function to remove items to the characters inventory
	std::string& GetName(); //A function to get the character name
	std::vector<Item>& GetInventory(); //A function to get the characters inventory.
};
class Player : public Character {
private:
	Room* location; //Pointer used to point to a room of where the player is located
public:
	Player(std::string name, int health, int hitpoints, int experience); //Constructor for Player class
	Room* GetLocation(); //A function used to get the players location
	void SetLocation(Room* newLocation); //A function used to set the new location for the player
};
