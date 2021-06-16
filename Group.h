#ifndef GROUP_H
#define GROUP_H
#include "Player.h"
#include <string>
using namespace std;

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
		bool isIllegal(string, string);
		void clearPlayer();
		int playerCardNum();
		void switchPlayer();
		int getPlayerSequence() const;
};

#endif
