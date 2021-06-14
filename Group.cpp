#include "Group.h"
#include <iostream>
using namespace std;

void Group::showCards()
{
	current.showInfo();
}

void Group::draw(string value, string color)
{
	current.insertCard(value, color);
}

void Group::play(int &index, string &value, string &color)
{
	current.playCard(index, value, color);
	current = current->next;
}

bool Group::isPlayable(string value, string color)
{
	return(current.checkCard(value, color);
}

void Group::clearPlayer()
{
	current.clearCard();
}

void Group::switchPlayer()
{
	current = current->next;
}
