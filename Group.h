#ifndef GROUP_H
#define GROUP_H
#include "Player.h"

class Group
{
	private:
		Player *current;
	public:
		Group(){ current = nullptr; };
		~Group(){ clearPlayer(); };
		void showCards();
		void draw(string, string);
		void play(int &, string &, string &);
		bool isPlayable(string, string);
		void clearPlayer();
		void switchPlayer();
		bool cardCleared(){ return isEmpty(); };
};
