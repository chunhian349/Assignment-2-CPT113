#ifndef GROUP_H
#define GROUP_H
#include "Player.h"
#include <string>
using namespace std;

//Group contain circular linked list of Player object
//Allow switching to next player after the player's turn
class Group
{
	private:
		Player *current; //Point to current player to be played when the group take turn
		
	public:
		Group();
		~Group(){ clearPlayer(); };
		void showCards();
		void draw(string, string);
		void play(int, string &, string &);
		bool isPlayable(string, string);
		bool isPlayable(int, string, string);
		bool isIllegal(string, string);
		void clearPlayer();
		int playerCardNum();
		void switchPlayer();
		int getPlayerSequence() const;
};

#endif
