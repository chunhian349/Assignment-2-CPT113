#ifndef CARDSTACK_H
#define CARDSTACK_H

class CardStack
{
	private:
		struct Card
		{
			string value;
			string color;
			Card *next;
		};
		Card *cardTop;
		
	public:
		CardStack(){cardTop = nullptr;};
		~CardStack();
		void push(string, string);
		void pop(string&, string&);
		void peekTop(string&, string&) const;
		bool isEmpty();
};

#endif
