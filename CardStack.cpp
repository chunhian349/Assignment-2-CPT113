#include <iostream>
#include "CardStack.h"
using namespace std;

//Destructor
//Delete all the node(Card object) to free dynamic memory space
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

//Check the stack is empty or not
bool CardStack::isEmpty()
{
	if(cardTop == nullptr)
		return true;
	else
		return false;
}

//Push card onto top of the stack
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

//Pop the card from the top of stack
//The content of popped Card object store into reference variables
//Then delete the popped object
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

//Peek the content of card at the top of the stack
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
