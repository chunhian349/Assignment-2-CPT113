#ifndef CARDSTACK_H
#define CARDSTACK_H

class CardStack
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
		CardStack(){cardTop = nullptr;};
		~CardStack();
		void push(auto, string);
		void pop(Card &);
		bool isEmpty();
}

#endif
