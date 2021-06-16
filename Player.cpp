#include "Player.h"
#include <iostream>
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
		while(nodePtr != nullptr && nodePtr->color < color)
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
	int count = 1;
	
	while(nodePtr != nullptr)
	{
		cout << count << ": (" << nodePtr->value << ", " << nodePtr->color << ")\n";
		nodePtr = nodePtr->next;
		count++;
	}
	
	cout<<endl;
}

void Player::playCard(int index, string &value, string &color)
{
	Card *nodePtr = nullptr;
	Card *previousNode = nullptr;
	int count = 1;
	
	if(!first)
		cout << "List is empty.";
	
	else if(index == 1)
	{
		value = first->value;
		color = first->color;
		nodePtr = first->next;
		delete first;
		first = nodePtr;
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
			previousNode->next = nodePtr->next;
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
	bool flag = false;
	
	while(card != nullptr)
	{
		if((card->value == "Wild" || card->value == "Wild Draw 4") && card->color == "Black")
		{
			flag = true;
			break;
		}
			
		else if(card->value == value || card->color == color)
		{
			flag = true;
			break;
		}
		card = card->next;
	}
	
	return flag;
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

bool Player::checkLegal(string discardpile_value, string discardpile_color)
{
	Card *card = first;
	
	while(card != nullptr)
	{
		if(card->color == discardpile_value || card->value == discardpile_color)
		{
			return true;
		}
		card = card->next;
	}
	
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
