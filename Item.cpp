#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include "Item.h" //Includes the header file for "Item.h"


//Item class


Item::Item(std::string name, std::string desc) : name(name), description(desc) {}
/*
Constructor for Character class, intitializes member variables name and description with values passed as name and description
*/
void Item::Interact() { //A function to interact with the item
	std::cout << "Name: " << name << "\nDescription: " << description << std::endl; //Outputs a message of the name and description of the item
}
std::string Item::GetName() { //A function to get the name of the item
	return this->name; //Returns the name of the item
}
std::string Item::GetDescription() { //A function to get the description of the item
	return this->description; //Returns the description of the item
}
/*
Overloaded equality operator to compare two Item objects.
Returns true if the names of the items are equal; otherwise, returns false.
*/
bool Item::operator==(Item& other) { // Overloaded equality operator to compare two Item objects
	if (this->name == other.name) { //
		return true; //Returns true
	}
	else {
		return false; //Returns false
	}
}
