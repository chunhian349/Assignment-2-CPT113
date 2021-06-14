#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	private:
		struct Card
		{
			auto value;
			string color;
			Card *next
		}
		Card *first;
		Player *next;
	public:
		Player(){ first = nullptr; next = nullptr; };
		~Player(){ clearCard(); };
		void insertCard(auto value, string color);
		void showInfo() const;
		void playCard(auto value, string color);
		void clearCard();
};
