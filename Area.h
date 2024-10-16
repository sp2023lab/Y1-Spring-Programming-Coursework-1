#pragma once //Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include "Room.h" //Includes the header file for "Room.h"


//Area class


class Area {
private:
	std::map <std::string, Room*> rooms; //Map used to store rooms using room names as keys and Room pointers as values
	Room* startingRoom; //Pointer to the starting room of the Area
public:
	void AddRoom(std::string name, Room* room); //Function to add a room to an area
	Room* GetRoom(std::string name); //Gets the name of the room in the area
	void ConnectRooms(std::string room1Name, std::string room2Name, std::string direction); //Function to connect 2 rooms in an area
	void LoadMapFromFile(std::string filename); //Function to get the text file (which is the map)
	Room* GetStartingRoom(); //Gets the starting room in the area
};
