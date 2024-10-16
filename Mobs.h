#pragma once //Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <vector> //Allows for working with dynamic arrays (vectors)


//Mobs class and MobBoss class (new classes)


class Mobs {
private:
	std::string mob_name; //A string for the mob name
	int health; //An integer for the health of the mob
public:
	Mobs(std::string mob_name, int health); //A constructor for Mobs class
	void PrintMobStat(); //A function to print the mob stats
	void TakeMobHealth(int damage); //A function to reduce mob health
};

class MobBoss : public Mobs {
private:
	int bossDamage; //An integer for the bossDamage
public:
	MobBoss(std::string mob_name, int health, int bossDamage); //A constructor for MobBoss class
	void PrintMobBossDamage(); //A function for printing the mob boss
	int BossDamage(); //A function for boss damage
};
#pragma once
