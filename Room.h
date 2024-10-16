#pragma once //Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include "Item.h" //Includes the header file for "Item.h"


//Room class


class Room {
private:
	std::string description; //A string to hold the description of the room
	std::map<std::string, Room*> exits; //Map used to store exits using room name as keys and Room pointers as values
	std::vector<Item> items; //A vector which contains the room inventory of items 
public:
	void PrintConnections(); //A function to print the connections for a room
	Room(std::string desc); //A constructor for the Room class
	void AddItem(Item& item); //A functiont to add items to a room
	void RemoveItem(Item& item); //A function to remove items from a room
	std::string GetDescription(); //A function to get the description of a room
	std::vector<Item> GetItems(); //A function to get the items from a room
	std::map<std::string, Room*>& GetExits(); //A function to get the exits for a room
	Room* GetExit(std::string direction); //A function to get an exit from a room with the direction
	void connectExit(std::string direction, Room* room); //A function to connect the exits from the current room to the new room
};
#pragma once
