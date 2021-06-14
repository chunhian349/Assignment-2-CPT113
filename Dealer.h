#ifndef DEALER_H
#define DEALER_H

class Dealer
{
	private:
		struct Card
		{
			auto value;
			string color;
			Card *next;
		};
		Card *cardTop;
	public:
		Dealer(){cardTop = nullptr;};
		~Dealer();
		void push(auto, string);
		void pop(Card &);
		bool isEmpty();
}

#endif
