#include "Group.h"
#include <iostream>
using namespace std;

Group::Group()
{
	Player* player1 = new Player;  
	Player* player2 = new Player;
	 
	player1->next = player2; 
	player2->next = player1;  
	
	current = player1;
}

void Group::showCards()
{
	current->showInfo();
}

void Group::draw(string value, string color)
{
	current->insertCard(value, color);
}

void Group::play(int position, string &value, string &color)
{
	current->playCard(position, value, color);
}

bool Group::isPlayable(string value, string color)
{
	return current->checkCard(value, color);
}

bool Group::isPlayable(int position, string value, string color)
{
	return current->checkCard(position, value, color);
}

void Group::clearPlayer()
{
	Player *playerPtr = nullptr;
	
	while(current != nullptr)
	{
		playerPtr = current;
		current = current->next;
		delete playerPtr;
	}
}

void Group::switchPlayer()
{
	current = current->next;
}

int Group::playerCardNum()
{
	return current->getCardNum();
}
