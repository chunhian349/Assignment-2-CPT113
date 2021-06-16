#include "Group.h"
#include <iostream>
using namespace std;

Group::Group()
{
	Player* player1 = new Player;  
	Player* player2 = new Player;
	 
	player1->next = player2;
	player1->sequence = 1;
	player2->next = player1;
	player2->sequence = 2;
	
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

bool Group::isIllegal(string discardpile_value, string discardpile_color)
{
	return current->checkLegal(discardpile_value, discardpile_color);
}

void Group::clearPlayer()
{
	Player *player1 = current;
	//Player *player2 = current->getPlayerNext();
	Player *player2 = current->next;
	
	delete player1;
	delete player2;
}

int Group::playerCardNum()
{
	return current->num;
}

void Group::switchPlayer()	
{
	current = current->next;	
}

int Group::getPlayerSequence() const 
{
	return current->sequence;
}
