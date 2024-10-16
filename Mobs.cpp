#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <vector> //Allows for working with dynamic arrays (vectors)
#include "Mobs.h" //Includes the header file for "Mobs.h"


//Mob class and MobBoss class (new classes)


Mobs::Mobs(std::string mob_name, int health) : mob_name(mob_name), health(health) {}
/*
Constructor for Mobs class, intitializes member variables mob_name and health with values passed as mob_name and health
*/
void Mobs::PrintMobStat() { //A function to print the mob statistics
	std::cout << "This is a " << mob_name << " and this has " << health << " health." << std::endl; //Outputs the mob stats
}
void Mobs::TakeMobHealth(int damage) { //A function to take away health from the mob
	while (health > 0) { //Indefinite loop until the health is less than 0
		std::cout << "Press F to do damage to the mob!" << std::endl;
		std::string key_F; //key_F is a string
		std::cin >> key_F; //key_F is taken as an input
		if (key_F == "F") { //Checks if F has been pressed
			health = health - damage; //Takes away health from the mob via damage
			if (health < 0) {
				std::cout << "The mob is dead!" << std::endl; //Outputs a message saying the mob is dead when it less than 0 points
			}
			else {
				std::cout << "This mob has " << health << " and you have done " << damage << " damage to the mob." << std::endl;
				//Outputs a message which shows the damage done to the mob and the health
			}
		}
		else {
			std::cout << "No damage was done on the mob! This mob is at a health of: " << health << std::endl;
			//Outputs a message to say the mob doesn't take damaage if F isn't pressed
		}
	}
	std::cout << "The mob has been banished!" << std::endl; //Outputs a message when it is less than 0 points on health
}

MobBoss::MobBoss(std::string mob_name, int health, int bossDamage) : Mobs(mob_name, health), bossDamage(bossDamage) {}
/*
Constructor for MobBoss class, intitializes member variables mob_name and health with values passed as mob_name and health (assigned to Mobs) and bossDamage is initialized
with value bossDamage
*/
void MobBoss::PrintMobBossDamage() { //A function to print the amount of damage the mob boss does to the player
	PrintMobStat(); //Prints the details of the mob
	std::cout << "This mob does: " << bossDamage << " damage." << std::endl; //Prints the amount of damage the mob boss does
}
int MobBoss::BossDamage() { //A function to get the amount of damage the mob boss does
	return bossDamage; //Returns the amount of damage the mob boss does
}
