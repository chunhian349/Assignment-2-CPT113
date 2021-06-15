#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		struct Card
		{
			string value;
			string color;
			Card *next
		}
		Card *first;
		Player *next;
		int num;
		
	public:
		Player(){ first = nullptr; next = nullptr; num = 0	};
		~Player(){ clearCard(); };
		void insertCard(string, string);
		void showInfo() const;
		void playCard(int, string &, string &);
		bool checkCard(string, string);
		bool checkCard(int, string, string);
		int getCardNum() const {	return num;	};
		void clearCard();
};

#endif
