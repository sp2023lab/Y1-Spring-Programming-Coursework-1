#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include "Room.h" //Includes the header file for "Room.h"


//Room class


Room::Room(std::string desc) : description(desc) {}; //Constructor for room class, intitializes member variable description with value passed as desc 
void Room::PrintConnections() { //Function PrintConnections assigned to Room
	std::cout << "\nRoom: " << description << " & ";
	for (auto& exit : exits) { //Parses through the available exits
		std::cout << "Exit: " << exit.first << ", Connected Room: " << exit.second->GetDescription() << "\n" << std::endl;
		//Outputs the direction and description of connected room
	}
}
void Room::AddItem(Item& item) { //Function AddItem assigned to Room with parameter Item and uses item to add an item to a room
	items.emplace_back(item); //Adds the item back to the room
};
void Room::RemoveItem(Item& item) { //Function RemoveItems assigned to Room with parameters Item and uses item to remove an item to a room
	for (unsigned int i = 0; i < items.size(); i++) { //Parses through all of the items in the room
		if (this->items[i] == item) { //Checks if this is the item to remove from the room
			items.erase(items.begin() + i); //Removes the item from the room
		}
	}
};
std::string Room::GetDescription() { //Function to return the description of a room
	return description; //Returns description
}
std::vector<Item> Room::GetItems() { //Function to return 
	return items; //Returns items
}
std::map<std::string, Room*>& Room::GetExits() { //Function to get the exits from the room
	return exits; //Returns the available exits
}
Room* Room::GetExit(std::string direction) { //
	auto it = exits.find(direction); //Search for the exit in the exits map based on the given direction
	std::cout << "\n" << direction; //Outputs the direction being searched for
	if (it != exits.end()) { //Checks if the exit was found
		return it->second; //Returns a pointer to the connected room
	}
	else {
		std::cout << "\nExit not found for direction " << direction << std::endl; //Outputs the exit wasn't found
		return nullptr; //Returns a null pointer
	}
}
void Room::connectExit(std::string direction, Room* room) {
	//A function to connect the room to the exit with 2 parameters: direction (which is a string) and Room (which is a pointer) and uses room to connect it to the exit with the direction
	exits[direction] = room; //Connects the exit with the direction to the room
}
