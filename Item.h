#pragma once //Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation


//Item class


class Item {
private:
	std::string name; //A string used to hold the name of an item
	std::string description; //A string used to hold the description of an item
public:
	Item(std::string name, std::string desc); //Constructor for item class
	void Interact(); //A function to allow the player to interact with an item
	std::string GetName(); //A function to get the name of an item
	std::string GetDescription(); //A function to get the description of an item
	bool operator==(Item& other); // Overloaded equality operator for comparing items
};
#pragma once
