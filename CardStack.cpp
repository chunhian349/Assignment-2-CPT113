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

void CardStack::push(auto T, string color)
{
	Card *newNode = nullptr;
	
	newNode = new Card;
	newNode->value = T;
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

void CardStack::pop(Card &object)
{
	Card *temp = nullptr;
	
	if(isEmpty())
		cout << "The stack is empty.\n";
	else
	{
		object = cardTop;
		temp = cardTop->next;
		delete cardTop;
		cardTop = temp;
	}
}
