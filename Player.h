#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <iostream>
using namespace std;

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
		int num;
		
	public:
		Player(){ first = nullptr; next = nullptr; num = 0;	};
		~Player(){ clearCard(); }
		void setPlayerNext(Player*);
		Player* getPlayerNext();
		void insertCard(string, string);
		void showInfo() const;
		void playCard(int, string &, string &);
		bool checkCard(string, string);
		bool checkCard(int, string, string);
		bool checkLegal(string, string);
		int getCardNum() const {	return num;	};
		void clearCard();
		friend void switchPlayer(Player *&);
};

#endif
