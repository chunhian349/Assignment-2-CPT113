#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

class Group;

class Player
{
	private:
		struct Card
		{
			string value;
			string color;
			Card *next;
		};
		
		Card *first;
		Player *next;
		int sequence; //1st player or 2nd player of the group
		int num; //Number of card on the player's hand
		
	public:
		Player(){ first = nullptr; next = nullptr; num = 0;	sequence = 0; };
		~Player(){ clearCard(); }
		void insertCard(string, string); 
		void showInfo() const; 
		void playCard(int, string &, string &); 
		bool checkCard(string, string);
		bool checkCard(int, string, string);
		bool checkLegal(string, string);
		void clearCard();
		
		friend class Group;
};

#endif
