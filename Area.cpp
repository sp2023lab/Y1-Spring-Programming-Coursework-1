#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include "Room.h" //Includes the header file for "Room.h"
#include "Area.h" //Includes the header file for "Area.h"


//Area class


void Area::AddRoom(std::string name, Room* room) { //A function which adds the rooms to the game
    rooms[name] = room; //Adds the room to the game
}
Room* Area::GetRoom(std::string name) { //A function to get the rooms
    auto it = rooms.find(name); //Finds the room in 'rooms' map using its name as the key
    return (it != rooms.end()) ? it->second : nullptr; //Returns a pointer to the found room if it exists or it returns a null pointer
}
void Area::ConnectRooms(std::string room1Name, std::string room2Name, std::string direction) {
    Room* room1 = GetRoom(room1Name); //Gets room1 assigned to Room 
    Room* room2 = GetRoom(room2Name); //Gets room2 assigned to Room
    if (room1 && room2) { //Checks if room1 and room2 exists
        room1->connectExit(direction, room2); //Connects the exit for room1
        room2->connectExit(direction, room1); //Connects the exit for room2 
    }
    else {
        std::cerr << "No connection available" << std::endl; //Outputs no connection available
    }
}
void Area::LoadMapFromFile(std::string filename) { //A function to load the game files
    std::ifstream file(filename); //Opens the file for reading
    if (!file.is_open()) { //Checks if the file is open
        std::cerr << "Error opening file: " << filename << std::endl; //Outputs a message saying theres an error opening the file
        return; //Returns nothing
    }
    std::string line; //line is a string variable
    Room* startingRoom = nullptr;  // Initialize startingRoom outside the loop
    std::map<std::string, Room*> rooms;  // Temporary map to store rooms
    while (std::getline(file, line)) { //Read each line from the file
        std::istringstream iss(line); //Create a string stream to parse the line
        std::string roomName, description, command, connectedRoomName, direction; //Variables to store room name, description and connections
        // Extract room information
        std::getline(iss, roomName, '|');
        if (rooms.count(roomName) == 0) { //Check if room has already been created
            std::getline(iss, description, '|');
            //Create a new room and add it to the map
            Room* newRoom = new Room(description);
            rooms[roomName] = newRoom;
            if (startingRoom == nullptr) { //Set starting room if not set
                startingRoom = newRoom;
            }
        }
        // Extract connections
        while (iss >> command) {
            if (command == "Connect") {
                iss >> connectedRoomName >> direction; //Read connected room name and direction
                rooms[roomName]->connectExit(direction, rooms[connectedRoomName]); //Connect room with connected room
            }
        }
    }
    file.close(); //Closes the file
    // Assign the overall starting room outside the loop
    this->startingRoom = startingRoom;
    this->rooms = rooms;
}
Room* Area::GetStartingRoom() { //A function to get the starting room
    return startingRoom; //Returns the startingRoom
}
