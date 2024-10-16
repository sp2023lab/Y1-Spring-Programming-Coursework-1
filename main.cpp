#pragma once //Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <map> //Include header file for map container
#include <vector> //Allows for working with dynamic arrays (vectors)
#include <fstream> //Allows for file input and output operatons
#include <sstream> //Allows for string stream operations
#include <random> // Provides facilities for generating random numbers
#include <chrono> // Provides utilities for measuring time
#include <thread> // Provides utilities for managing threads and sleeping


//Include the files for the game


#include "Item.h" //Includes the header file for "Item.h"
#include "Area.h" //Includes the header file for "Area.h"
#include "Character.h" //Includes the header file for "Character.h"
#include "Room.h" //Includes the header file for "Room.h"
#include "Mobs.h" //Includes the header file for "Mobs.h"
#include "Quests.h" //Includes the header file for "Quests.h"


//Interaction (game below)


int main() {
	std::this_thread::sleep_for(std::chrono::seconds(2));
	Area gameWorld;	// Create an instance of the Area class
	gameWorld.LoadMapFromFile("game_map.txt"); 	// Load the game map from a text file
	std::cout << "\nEnter your name: "; // Prompt the user to enter their name
	std::string player_name;
	std::cin >> player_name; // Read the player's name from input
	std::cout << "\nWelcome to the game, " << player_name << std::endl; // Greet the player
	Player player(player_name, 100, 0, 0); //Player name with health and hitpoints
	//Define Items (by item name, description)
	Item burrito("Burrito", "A delicious burrito which looks tasty.");
	Item gun("Gun", "A gun which looks like it can kill off zombies.");
	Item shield("Shield", "A shield which looks like it can defend against zombies.");
	Item potion("Potion", "A potion which looks like it can either give you more health you or take your health away.");
	Item armor("Armor", "An armor which will provide protection.");
	Item MRB("MRB", "A missile remote button which can destroy the zombie spawn point.");
	Item Healing_Potion("HP", "A healing potion which will provide you max health.");
	Item Dragon_Egg("Egg", "A dragons egg which can only be claimed from defeating a dragon.");
	//Get the rooms (by calling GetRoom function under gameWorld)
	Room* currentRoom = gameWorld.GetRoom("startRoom"); // Set the player's starting room 
	Room* room2 = gameWorld.GetRoom("Room2");
	Room* room3 = gameWorld.GetRoom("Room3");
	Room* room4 = gameWorld.GetRoom("Room4");
	Room* room5 = gameWorld.GetRoom("Room5");
	Room* room6 = gameWorld.GetRoom("Room6");
	Room* room7 = gameWorld.GetRoom("Room7");
	Room* room8 = gameWorld.GetRoom("Room8");
	Room* exitRoom = gameWorld.GetRoom("exitRoom");
	//Setup the quests (by adding a quest to Quests)
	Quests quest1("Quest 1", "Collect the Dragon Egg", false);
	Quests quest2("Quest 2", "Collect the HP", false);
	Quests quest3("Quest 3", "Collect the MRB", false);
	Quests quest4("Quest 4", "Defeat the Zombie", false);
	Quests quest5("Quest 5", "Defeat the SuperDragon", false);
	playerQuests playerQuest("Player Quest Log:", "Description:", false);
	//Adds quests for the players (by calling the AddQuest function)
	playerQuest.AddQuest(quest1);
	playerQuest.AddQuest(quest2);
	playerQuest.AddQuest(quest3);
	playerQuest.AddQuest(quest4);
	playerQuest.AddQuest(quest5);
	playerQuest.displayQuestLog();
	std::cout << "\n\n";
	//Add items to room (by having the room point to an item being added so the item is added to the room)
	currentRoom->AddItem(burrito);
	currentRoom->AddItem(gun);
	room2->AddItem(shield);
	room2->AddItem(gun);
	room3->AddItem(potion);
	room4->AddItem(armor);
	room4->AddItem(shield);
	room7->AddItem(MRB);
	room7->AddItem(Healing_Potion);
	room8->AddItem(burrito);
	//Set the player location
	player.SetLocation(currentRoom);
	//Mobs visited (using boolean values all set to false)
	bool zombieVisited = false;
	bool dragonVisited = false;
	bool superdragonVisited = false;
	//Define mobs in the game
	Mobs Zombie("Zombie", 50);
	Mobs Dragon("Dragon", 100);
	MobBoss SuperDragon("SuperDragon", 200, 60);
	while (true) { 	//Game loop is below
		player.GetLocation(); //Retrieve the player's current location
		playerQuest.questLogComplete(); //Check if any quests in the player's quest log have been completed
		std::vector<Item>& playerInventory = player.GetInventory(); //Get a reference to the player's inventory
		std::cout << "\nItems in player's inventory: " << std::endl; //Print the items in the player's inventory
		for (Item& item : playerInventory) { //Loops through the player inventory
			std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl; //Prints out the item name and description
		}
		std::cout << "\nCurrent Location: " << player.GetLocation()->GetDescription() << std::endl; //Print the description of the player's current location
		if (player.GetLocation()->GetDescription() == "BOSS LEVEL: Zombie room." and zombieVisited == false) { //Checks if the player is at the Zombie room and has not visited it before
			zombieVisited = true; //Marks the Zombie room as visited
			std::cout << "\nYou have approached a boss level: Zombie level!" << std::endl; //Display message indicating the player has entered a boss level (Zombie level)
			Zombie.PrintMobStat(); //Print statistics of the Zombie boss
			std::cout << "\nWhat items do you use to defeat the zombie?" << std::endl; //Prompt the player to choose items to defeat the zombie
			std::string defeatZombie; //Declare a string variable to store the player's choice of weapon
			std::cin >> defeatZombie; //Take player input for the weapon choice
			bool suitableweapon_1 = false; //Initialize a flag to indicate if a suitable weapon is found
			for (Item& item : playerInventory) { // Iterate through the player's inventory to find a suitable weapon
				if (defeatZombie == item.GetName() and defeatZombie == "MRB") { //Check if the chosen weapon matches MRB and is present in the inventory
					suitableweapon_1 = true; //Mark the weapon as suitable
					player.RemoveFromInventory(MRB); //Remove MRB from the player's inventory
					player.TakeDamage(5); //Player takes damage from the battle
					player.Shield_System(-10); //Player's shield system is affected
					Zombie.TakeMobHealth(1000); //Inflict damage on the Zombie boss
					//Display updated player inventory
					std::cout << "\nItems in player's inventory: " << std::endl;
					for (Item& item : playerInventory) {
						std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
					}
					player.ExperiencePoints(1000); //Update player's experience points
				}
				else if (defeatZombie == item.GetName() and defeatZombie == "Gun") { //Check if the chosen weapon matches Gun and is present in the inventory
					suitableweapon_1 = true; //Mark the weapon as suitable
					player.RemoveFromInventory(gun); //Remove Gun from the player's inventory
					player.TakeDamage(25); //Player takes damage from the battle
					player.Shield_System(-20); //Player's shield system is affected
					Zombie.TakeMobHealth(20); //Inflict damage on the Zombie boss
					std::cout << "\nItems in player's inventory: " << std::endl; //Display updated player inventory
					for (Item& item : playerInventory) {
						std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
					}
					player.ExperiencePoints(500); //Update player's experience points
				}
			}
			if (suitableweapon_1 == false) { //If no suitable weapon is found, player dies
				std::cout << "You died!" << std::endl;
				std::exit(0); //Terminate the program
			}
		}
		if (zombieVisited == true) { //Checks if the Zombie boss level has been visited
			playerQuest.completingQuest(quest4); //Update the player's quest log to reflect the completion of Quest 4
		}
		if (player.GetLocation()->GetDescription() == "BOSS LEVEL: A dragons lair." and dragonVisited == false) { //Checks if the player is in the Dragon's lair and has not visited it before
			dragonVisited = true; //Marks Dragon's lair as visited
			std::cout << "\nYou have approached a boss level: Dragons lair!" << std::endl;
			Dragon.PrintMobStat(); //Prints Dragon's stats
			std::cout << "\nWhat items do you use to defeat the dragon?" << std::endl; //Displays available items in the player's inventory for defeating the dragon
			for (Item& item : playerInventory) {
				std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
			}
			std::string defeatDragon; //Stores player's input for defeating the dragon
			std::cin >> defeatDragon; //Takes input from the player
			bool suitableweapon_2 = false; //Flag to check if the selected weapon is suitable
			for (Item& item : playerInventory) {
				if (defeatDragon == item.GetName() and (defeatDragon == "MRB" or defeatDragon == "Gun")) { //Checks if the chosen item matches the available weapons and if the player has an MRB or Gun
					suitableweapon_2 = true; //Marks the weapon as suitable
					player.RemoveFromInventory(item); //Removes the chosen item from the player's inventory
					//Adjusts player's health and shield system based on the chosen weapon
					if (defeatDragon == "MRB") {
						player.TakeDamage(15);
						player.Shield_System(-10);
						Zombie.TakeMobHealth(1000);
					}
					else if (defeatDragon == "Gun") {
						player.TakeDamage(50);
						player.Shield_System(-40);
						Zombie.TakeMobHealth(20);
					}
					std::cout << "\nItems in player's inventory: " << std::endl; //Prints the updated inventory
					for (Item& item : playerInventory) {
						std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
					}
					player.ExperiencePoints((defeatDragon == "MRB") ? 1000 : 500); //Grants experience points to the player based on the outcome of the battle
					break; //Exits the loop after handling the chosen item
				}
			}
			if (suitableweapon_2 == false) { //If the player doesn't have a suitable weapon, they die
				std::cout << "You died!" << std::endl;
				std::exit(0); //Exits the program
			}
			player.AddToInventory(Dragon_Egg); //Adds Dragon's Egg to the player's inventory
		}
		if (dragonVisited == true) { //Checks if the Dragon boss level has been visited
			playerQuest.completingQuest(quest1); //Update the player's quest log to reflect the completion of Quest 1
		}
		if (dragonVisited == true and zombieVisited == true and superdragonVisited == false) {
			// Checks if the player has visited both the Dragon's lair and the Zombie room and hasn't encountered the SuperDragon yet
			std::cout << "\nYou now must defeat the SuperDragon to win the game!\n";
			std::cout << "Do you choose to defeat the SuperDragon?\n";
			std::cout << "Options: | ";
			std::cout << "1. Yes | ";
			std::cout << "2. No | ";
			std::string option; // Stores player's choice for defeating the SuperDragon
			std::cin >> option; // Takes input from the player
			if (option == "yes" or option == "1") { // If the player chooses to fight the SuperDragon
				std::cout << "The final boss of the game is here... you fall into a deep ditch to fight the SuperDragon." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(1)); // Pauses for dramatic effect (1 second)
				std::cout << "You keep going forward and it is pitch black. You cannot see anything but hear and feel a massive vibration." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(5)); // Pauses for dramatic effect (5 seconds)
				std::cout << "You have encountered the SuperDragon! It roars at you and spits fire at you!" << std::endl;
				std::cout << "SUPER BOSS LEVEL: Defeat the SuperDragon!" << std::endl;
				player.TakeDamage(SuperDragon.BossDamage()); // Inflicts damage on the player
				SuperDragon.TakeMobHealth(30); // Inflicts damage on the SuperDragon
				std::cout << "\nWhat items do you use to defeat the SuperDragon?" << std::endl;
				std::string defeatSuperDragon; // Stores the player's choice of weapon to defeat the SuperDragon
				std::cin >> defeatSuperDragon; // Takes input from the player
				for (Item& item : playerInventory) {
					std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl; // Displays available items in the player's inventory for defeating the SuperDragon
				}
				bool suitableWeapon_3 = false; // Flag to check if the selected weapon is suitable
				for (Item& item : playerInventory) {
					// Checks if the chosen item is suitable for defeating the SuperDragon
					if (defeatSuperDragon == "MRB" and defeatSuperDragon == item.GetName()) {
						suitableWeapon_3 = true; // Marks the weapon as suitable
						player.RemoveFromInventory(MRB); // Removes the MRB from the player's inventory
						// Adjusts player's health and shield system based on the chosen weapon
						player.TakeDamage(15);
						player.Shield_System(-10);
						Zombie.TakeMobHealth(50);
						std::cout << "\nItems in player's inventory: " << std::endl;
						for (Item& item : playerInventory) {
							std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
						}
						player.ExperiencePoints(2000); // Grants experience points to the player
					}
					else if (defeatSuperDragon == "MRB" and defeatSuperDragon == item.GetName()) {
						suitableWeapon_3 = true; // Marks the weapon as suitable
						player.RemoveFromInventory(MRB); // Removes the MRB from the player's inventory
						// Adjusts player's health and shield system based on the chosen weapon
						player.TakeDamage(30);
						player.Shield_System(-20);
						Zombie.TakeMobHealth(50);
						std::cout << "\nItems in player's inventory: " << std::endl;
						for (Item& item : playerInventory) {
							std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl;
						}
						player.ExperiencePoints(1000); // Grants experience points to the player
					}
				}
				if (suitableWeapon_3 == false) { // If the player doesn't have a suitable weapon, they die
					std::cout << "\nYou died!" << std::endl;
					std::exit(0); // Exits the program
				}
			}
			else {
				std::cout << "\nOne day, you will have to defeat the Super Dragon... play on, son." << std::endl;
			}
		}
		if (superdragonVisited == true) { //Checks if the SuperDragon boss level has been visited
			playerQuest.completingQuest(quest5); //Update the player's quest log to reflect the completion of Quest 5
		}


		std::cout << "\nItems in the room: " << std::endl;
		for (Item& item : player.GetLocation()->GetItems()) { //Parses through the items in the room
			std::cout << "- " << item.GetName() << ": " << item.GetDescription() << std::endl; //Outputs the items in the room
		}
		std::cout << "\nExits available: ";
		for (auto& exit : player.GetLocation()->GetExits()) { //Parses through the available exits in the room
			std::cout << exit.first << " "; //Outputs the available exits
		}
		player.PrintStats();
		std::cout << "\n\n| ";
		std::cout << "Options: | ";
		std::cout << "1. Look around | ";
		std::cout << "2. Interact with an item | ";
		std::cout << "3. Move to another room | ";
		std::cout << "4. Drop an item | ";
		std::cout << "5. Quit |" << std::endl;
		std::string choice; //choice is a variable string
		std::cin >> choice; //choice is taken in as an input
		if (choice == "1") { //Looks around the room if option 1 is selected
			std::cout << "You look around the room." << std::endl; //Player looks around (no action required)
		}
		else if (choice == "2") { //Interacts with an item if option 2 is selected
			player.GetInventory();
			std::cout << "Enter the name of the item you want to interact with: "; //Player interacts with an item in the room			
			std::string itemName; //itemName is a variable string
			std::cin >> itemName; //itemName is taken as an input
			for (Item& item : player.GetLocation()->GetItems()) { //Parses through the items in the room
				if (item.GetName() == itemName) { //Checks if item.GetName() matches itemName
					std::cout << itemName << "\n";
					item.Interact(); //The player can interact with the item
					if (itemName == "Burrito") { //Check if player selected burrito
						player.RegainHealth(25); //Adds 25 health to the player
						currentRoom->RemoveItem(burrito); //Removes item burrito from current room
						player.ExperiencePoints(2); //Adds 2 experience points
					}
					else if (itemName == "Potion") { //Check if player selected potion
						std::random_device rd; // Generates random numbers from a hardware entropy source
						std::mt19937 gen(rd()); // Mersenne Twister pseudo-random number generator engine seeded with rd
						std::uniform_int_distribution<int> distribution(-15, 15); // Generates random integers in the range [-15, 15]
						int random_number = distribution(gen); // Generates a random number using the distribution and engine
						if (random_number < 0) {
							player.TakeDamage(-random_number); //Takes damage from player
							player.ExperiencePoints(2); //Adds 2 experience points
						}
						else {
							player.RegainHealth(random_number); //Adds player health
							player.ExperiencePoints(2); //Adds 2 experience points
						}
						currentRoom->RemoveItem(potion); //Removes potion from room
					}
					else if (itemName == "Shield") { //Check if player selected shield
						player.Shield_System(20); //Adds 20 hitpoints to shield
						currentRoom->RemoveItem(shield); //Removes item shield from current room
						player.ExperiencePoints(2); //Adds 2 experience points
					}
					else if (itemName == "Gun") { //Check if player selected gun
						player.AddToInventory(gun); //Adds item gun to player inventory
						currentRoom->RemoveItem(gun); //Removes item gun from current room
						player.ExperiencePoints(2); //Adds 2 experience points
					}
					else if (itemName == "MRB") { //Check if player selected MRB
						player.AddToInventory(MRB); //Adds item MRB to player inventory
						currentRoom->RemoveItem(MRB); //Removes item MRB from current room
						player.ExperiencePoints(2); //Adds 2 experience points
						playerQuest.completingQuest(quest3); //Completes quest 3
					}
					else if (itemName == "Armor") { //Check if player selected armor
						player.Shield_System(100); //Adds 100 hitpoints to shield
						currentRoom->RemoveItem(armor); //Removes item armor from current room
						player.ExperiencePoints(2); //Adds 2 experience points
					}
					else if (itemName == "HP") { //Check if player selected HP
						player.RegainHealth(100); //Adds 100 health to the player
						currentRoom->RemoveItem(Healing_Potion); //Removes item Healing Potion from current room
						player.ExperiencePoints(2); //Adds 2 experience points
						playerQuest.completingQuest(quest2); //Completes quest 2
					}
					break;
				}
			}
		}
		else if (choice == "3") { //Moves player to room if option 3 if selected
			std::cout << "Enter the direction (e.g., north, south): "; // Player moves to another room
			std::string direction; //direction is a variable string
			std::cin >> direction; //direction is taken in as an input
			Room* nextRoom = player.GetLocation()->GetExit(direction); //Gets nextRoom assigned to Room pointing to nextRoom
			if (nextRoom != nullptr) { //Checks if nextRoom is not a null pointer
				player.SetLocation(nextRoom); //Sets location to nextRoom
				std::cout << "\nYou move to the next room: " << std::endl;
				currentRoom = nextRoom;
				player.GetLocation()->GetDescription(); //The description of the room is printed from the location of the players room
				player.ExperiencePoints(5); //Player gains 5 experience points (XP)
			}
			else {
				std::cout << "You can't go that way." << std::endl; //Outputs a message saying the player cannot go that way
			}
		}
		else if (choice == "4") { //Drops an item if option 4 is selected
			std::cout << "NOTE: If you drop an item, you will not be able to recover it!" << std::endl;
			std::cout << "Which item would you like to drop?" << std::endl;
			std::string dropItem; //dropItem is a variable string
			std::cin >> dropItem; //dropItem is taken in as an input
			for (Item& item : playerInventory) { //Parses through the playerInventory
				if (dropItem == item.GetName()) { //Checks if dropItem matches the name of the item in the playerInventory
					player.RemoveFromInventory(item); //Drops the item
				}
			}
		}
		else if (choice == "5") { //Leaves the game if option 5 is selected
			std::cout << "Goodbye!" << std::endl; // Quit the game
			break;
		}
		else {
			std::cout << "Invalid choice. Try again." << std::endl; //Outputs invalid choice
		}
	}
	return 0; //Returns 0
}
