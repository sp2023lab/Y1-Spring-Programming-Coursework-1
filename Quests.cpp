#include <iostream> //Allows for inputs and outputs
#include <string> //Allows for string manipulation
#include "Quests.h" //Includes the header file for "Quests.h"



//Quests and playerQuests class (new classes)


Quests::Quests(std::string questName, std::string description, bool completed) : questName(questName), description(description), completed(false) {}
/*
Constructor for Mobs class, intitializes member variables questName, description and completed with values passed as questName, description and false
*/
void Quests::printQuest() { //A function to print the quest status
	std::string lang; //lang ia a string variable
	if (completed == true or completed == 1) { //Checking if quest is completed
		lang = "completed."; //lang is set to completed
		std::cout << "Your quest is: " << questName << " and the description of the quest is: " << description << ". This quest is currently " << lang << std::endl;
		//A message which outputs the quest is completed along with the name and description
	}
	else {
		lang = "not completed."; //lang is set to not completed
		std::cout << "Your quest is: " << questName << " and the description of the quest is: " << description << ". This quest is currently " << lang << std::endl;
		//A message which outputs the quest is not completed along with the name and description
	}
}
std::string Quests::getQuestName() { //A function to get the name of the quest
	return questName; //Returns the name of the quest
}
std::string Quests::getQuestDescription() { //A function to get the description of the quest
	return description; //Returns the name of the description
}
void Quests::completeQuest() { //A function to set a completed quest to true
	completed = true; //completed is set to true
}
bool Quests::isCompleted() { //A function to return the completion status
	return completed; //completed is returned
}

playerQuests::playerQuests(std::string questName, std::string description, bool completed) : Quests(questName, description, completed) {}
/*
Constructor for playerQuests class, which is derived from the Quests class. The base class with the attributes questName, description, and completed are initialized
*/
void playerQuests::completingQuest(Quests& questToComplete) { //A function to complete the players quest
	for (Quests& quest : quests) { //Parses through all of the quests
		if (quest.getQuestName() == questToComplete.getQuestName()) { //Checks if the quest name matches the quest name to be completed
			if (!quest.isCompleted()) { //Checks if the quest name is not complete
				quest.completeQuest(); //Completes the quest
				break; //Breaks from the loop
			}
		}
	}
}
void playerQuests::AddQuest(Quests& quest) { //A function to add quests to the players quest log
	quests.emplace_back(quest); //Adds a quest to the players quest log
}
void playerQuests::displayQuestLog() { //A function to display the quest log
	std::cout << "\nQuest log book:\n";
	for (auto& quest : quests) { //Loops through the quests
		quest.printQuest(); //Prints the quest
	}
}
void playerQuests::questLogComplete() { //A function to check if all the quests are completed or not
	int questSize = quests.size(); //Gets the amount of quests using size() which is an integer
	int counter = 0; //counter is set to 0 which is an integer
	std::cout << "Quests pending:" << std::endl;
	for (Quests& quest : quests) { //Loops through all of the quests
		if (!quest.isCompleted()) { //Checks if the quest is not complete
			quest.printQuest(); //Outputs the incomplete quest
		}
		else {
			counter++; //The counter is added by 1
		}
	}
	if (questSize != counter) { //Checks if the counter is equal to the number of quests (so checks if all of the quests are complete)
		std::cout << "Make sure to finish the remaining quests!" << std::endl; //Outputs a message saying the quests need to be finished
	}
	else {
		std::cout << "Congratulations! All of the quests are complete!" << std::endl; //Outputs a message saying all of the quests are complete
	}
}
