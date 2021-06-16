#include <iostream>
#include "CardStack.h"
using namespace std;

CardStack::~CardStack()
{
	Card *temp = nullptr;
	while(cardTop != nullptr)
	{
		temp = cardTop;
		cardTop = cardTop->next;
		delete temp;
	}
}

bool CardStack::isEmpty()
{
	if(cardTop == nullptr)
		return true;
	else
		return false;
}

void CardStack::push(string value, string color)
{
	Card *newNode = nullptr;
	
	newNode = new Card;
	newNode->value = value;
	newNode->color = color;
	
	if(isEmpty())
	{
		cardTop = newNode;
		newNode->next = nullptr;
	}
	
	else
	{
		newNode->next = cardTop;
		cardTop = newNode;
	}
}

void CardStack::pop(string &value, string &color)
{
	Card *temp = nullptr;
	
	if(isEmpty())
		cout << "There is no card left in the stack.\n";
		
	else
	{
		value = cardTop->value;
		color = cardTop->color;
		
		temp = cardTop;
		cardTop = cardTop->next;
		
		delete temp;
	}
}

void CardStack::peekTop(string& value, string &color) 
{
	if(isEmpty())
		cout << "There is no card left in the stack.\n";
		
	else
	{
		value = cardTop->value;
		color = cardTop->color;
	}
}
