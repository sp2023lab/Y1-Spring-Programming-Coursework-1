#pragma once //Ensure header file is only included once
#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include <vector> //Allows for working with dynamic arrays (vectors)


//Quests class and playerQuests class (new classes)


class Quests {
private:
	std::string questName; //A string to hold the name of the quest
	std::string description; //A string to hold the description of the quest
	bool completed; //A boolean value to hold if the quest is completed or not
public:
	Quests(std::string questName, std::string description, bool completed); //Constructor for Quests class
	void printQuest(); //Function to print details of the quest (name, description, completion status)
	std::string getQuestName(); //A function to get the name of a quest
	std::string getQuestDescription(); //A function to get the description of a quest
	void completeQuest(); //A function to complete the quest
	bool isCompleted(); //A function to check if the quest is completed or not
};

class playerQuests : public Quests {
private:
	std::vector<Quests> quests; //A vector used to hold the number of quests
public:
	playerQuests(std::string questName, std::string description, bool completed); //Constructor for playerQuests class
	void completingQuest(Quests& quests); //A function to complete a specific quest
	void AddQuest(Quests& quests); //A function to add quests
	void displayQuestLog(); //A function to display all the quests
	void questLogComplete(); //A function to show the quests remaining
};
#pragma once
