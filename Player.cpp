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
	
	num++;
}

void Player::showInfo() const
{
	Card *nodePtr = first;
	while(nodePtr != nullptr)
	{
		cout << "The card is " << nodePtr->value << ", with " << nodePtr->color << " color.\n";
	}
}

void Player::playCard(int index, string &value, string &color)
{
	Card *nodePtr = nullptr;
	Card *previousPtr = nullptr;
	int count = 1;
	
	if(!first)
		cout << "List is empty.";
	
	else if(index == 1)
	{
		value = first->value;
		color = first->color;
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	}
	
	else
	{
		nodePtr = first;
		while(nodePtr != nullptr && count != index)
		{
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
			count++;
		}
		
		if(nodePtr)
		{
			value = nodePtr->value;
			color = nodePtr->color;
			previous->next = nodePtr->next;
			delete nodePtr;
		}
		
		else
			cout<<"Index exceed number of cards.\n";
	}
	
	num--;
}

bool Player::checkCard(string value, string color)
{
	Card *card = first;
	
	while(card != nullptr)
	{
		if((card->value == "Wild" || card->value == "Wild Draw 4") && card->color == "Black")
			return true;
		else if(card->value == value || card->color == color)
			return true;
		else
			return false;
		card = card->next;
	}
}

bool Player::checkCard(int position, string value, string color)
{
	Card *card = first;
	int count = 1;
	
	while(count != position && card != nullptr)
	{
		card = card->next;
		count++;
	}
	
	if((card->value == "Wild" || card->value == "Wild Draw 4") && card->color == "Black")
		return true;
	else if(card->value == value || card->color == color)
		return true;
	else
		return false;
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
	
	num = 0;
}
