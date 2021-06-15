#ifndef GROUP_H
#define GROUP_H
#include "Player.h"

class Group
{
	private:
		Player *current;
		
	public:
		Group();
		~Group(){ clearPlayer(); };
		void showCards();
		void draw(string, string);
		void play(int, string &, string &);
		bool isPlayable(string, string);
		bool isPlayable(int, string, string);
		void clearPlayer();
		void switchPlayer();
		int playerCardNum();
};

#endif
