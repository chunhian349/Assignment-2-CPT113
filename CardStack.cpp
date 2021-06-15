#include <iostream>
#include "CardStack.h"
using namespace std;

Dealer::~Dealer()
{
	Card *temp = nullptr;
	while(cardTop != nullptr)
	{
		temp = cardTop;
		cardTop = cardTop->next;
		delete temp;
	}
}

bool Dealer::isEmpty()
{
	if(cardTop == nullptr)
		return true;
	else
		return false;
}

void Dealer::push(auto T, string color)
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

void Dealer::pop(Card &object)
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
