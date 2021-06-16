#include "Group.h"
#include <iostream>
using namespace std;

//Constructor
//Create 2 player object where next will point to their respective teammate
//Current points to player 1 since the player will take turn first
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

//Print all the current player's cards at the player's turn
void Group::showCards()
{
	current->showInfo();
}

//Current player draw a card
void Group::draw(string value, string color)
{
	current->insertCard(value, color);
}

//Current player play a card
void Group::play(int position, string &value, string &color)
{
	current->playCard(position, value, color);
}

//Check current player has any card match with the card at top of discard pile
bool Group::isPlayable(string value, string color)
{
	return current->checkCard(value, color);
}

//Check selected card of current player match with the card at top of discard pile
bool Group::isPlayable(int position, string value, string color)
{
	return current->checkCard(position, value, color);
}

//Check current player played wild draw 4 card illegally
bool Group::isIllegal(string discardpile_value, string discardpile_color)
{
	return current->checkLegal(discardpile_value, discardpile_color);
}

//Will call by destructor
//Delete the dynamic Player object to free memory space
void Group::clearPlayer()
{
	Player *player1 = current;
	Player *player2 = current->next;
	
	delete player1;
	delete player2;
}

//Get number of card current player hold
int Group::playerCardNum()
{
	return current->num;
}

//Switch to next player
void Group::switchPlayer()	
{
	current = current->next;	
}

//To know current player of the group is first player or second player
int Group::getPlayerSequence() const 
{
	return current->sequence;
}
