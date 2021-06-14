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
	public:
		Player(){ first = nullptr; next = nullptr; };
		~Player(){ clearCard(); };
		void insertCard(string, string);
		void showInfo() const;
		void playCard(int &, string &, string &);
		bool checkCard(string, string);
		bool isEmpty() { return (first == nullptr); };
		void clearCard();
};
