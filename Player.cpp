#include "Player.h"
using namespace std;

void Player::insertCard(string value, string color)
{
	Card *newNode = nullptr;
	Card *nodePtr = nullptr;
	Card *previousNode = nullptr;
	
	newNode = new Card;
	newNode->value = value;
	newNode->color = color;
	newNode->next = nullptr;
	
	if(!first)
		first = newNode;
	else
	{
		nodePtr = first;
		while(nodePtr != nullptr && nodePtr->color != color)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}
		if(previousNode == nullptr)
		{
			first = newNode;
			newNode->next = nodePtr;
		}
		else
		{
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

void Player::showInfo() const
{
	Card *nodePtr = first;
	while(nodePtr != nullptr)
	{
		cout << "The card is " << nodePtr->value << ", with " << nodePtr->color << " color.\n";
	}
}

void Player::playCard(int &index, string &value, string &color)
{
	Card *nodePtr = nullptr;
	int count = 0;
	
	if(!first)
		cout << "List is empty.";
	
	if(first->value == value && first->color == color)
	{
		index = 1;
		value = first->value;
		color = first->color;
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	else
	{
		nodePtr = first;
		while(nodePtr != nullptr && nodePtr->value != value && nodePtr->color != color)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			count++;
		}
		
		if(nodePtr)
		{
			index = count;
			value = nodePtr->value;
			color = nodePtr->color;
			previousNode->next = nodePtr->next;
			delete nodePtr;
		}
	}
	// discard tile, don't know yet
}

bool Player::checkCard(int index, string value, string color)
{
	Card *card = nullptr;
	card = first;
	while(card == nullptr)
	{
		if((card->value == "Wild" || card->value == "Wild Plus 4") && card->color == "Black")
			return true;
		else if(card->value == value || card->color == color)
			return true;
		else
			return false;
		card = card->next;
	}
}

void Player::clearCard()
{
	Card *nodePtr = nullptr;
	Card *nextNode = nullptr;
	
	nodePtr = first;
	
	while(nodePtr != nullptr)
	{
		nextNode = nodePtr->next;
		delete nodePtr;
		nodePtr = nextNode;
	}
}
