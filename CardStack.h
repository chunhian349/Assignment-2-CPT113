#ifndef CARDSTACK_H
#define CARDSTACK_H
#include <string>
using namespace std;

//Stack data structure to store card objects
class CardStack
{
	private:
		//Card object is the node of the stack
		struct Card
		{
			//Store the value of the card (0-9/Skip/Reverse/Draw 2/Wild/Wild Draw 4)
			string value; 
			string color; //Store the color of the card
			Card *next; //Points next node
		};
		Card *cardTop; //Points the card at top of the stack
		
	public:
		CardStack(){cardTop = nullptr;}
		~CardStack(); 
		void push(string, string); 
		void pop(string&, string&);
		void peekTop(string&, string&);
		bool isEmpty();
};

#endif
