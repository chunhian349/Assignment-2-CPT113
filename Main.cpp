#include <iostream>
#include <ctime>
#include <string>
#include "CardStack.h"
#include "Group.h"
#include "Player.h"
using namespace std;
  
// Function which shuffle and print the array
void shuffle(CardStack &drawpile)
{
	const int SIZE = 108;
	
	struct Card
	{
		string value;
		string color;
	};
	
    // Array from 0 to 107
	Card card[SIZE] = {"0", "Red",
					"1", "Red",
					"1", "Red",
					"2", "Red",
					"2", "Red",
					"3", "Red",
					"3", "Red",
					"4", "Red",
					"4", "Red",
					"5", "Red",
					"5", "Red",
					"6", "Red",
					"6", "Red",
					"7", "Red",
					"7", "Red",
					"8", "Red",
					"8", "Red",
					"9", "Red",
					"9", "Red",
					"Draw 2", "Red",
					"Draw 2", "Red",
					"Reverse", "Red",
					"Reverse", "Red",
					"Skip", "Red",
					"Skip", "Red",
					"0", "Blue",
					"1", "Blue",
					"1", "Blue",
					"2", "Blue",
					"2", "Blue",
					"3", "Blue",
					"3", "Blue",
					"4", "Blue",
					"4", "Blue",
					"5", "Blue",
					"5", "Blue",
					"6", "Blue",
					"6", "Blue",
					"7", "Blue",
					"7", "Blue",
					"8", "Blue",
					"8", "Blue",
					"9", "Blue",
					"9", "Blue",
					"Draw 2", "Blue",
					"Draw 2", "Blue",
					"Reverse", "Blue",
					"Reverse", "Blue",
					"Skip", "Blue",
					"Skip", "Blue",
					"0", "Green",
					"1", "Green",
					"1", "Green",
					"2", "Green",
					"2", "Green",
					"3", "Green",
					"3", "Green",
					"4", "Green",
					"4", "Green",
					"5", "Green",
					"5", "Green",
					"6", "Green",
					"6", "Green",
					"7", "Green",
					"7", "Green",
					"8", "Green",
					"8", "Green",
					"9", "Green",
					"9", "Green",
					"Draw 2", "Green",
					"Draw 2", "Green",
					"Reverse", "Green",
					"Reverse", "Green",
					"Skip", "Green",
					"Skip", "Green",
					"0", "Yellow",
					"1", "Yellow",
					"1", "Yellow",
					"2", "Yellow",
					"2", "Yellow",
					"3", "Yellow",
					"3", "Yellow",
					"4", "Yellow",
					"4", "Yellow",
					"5", "Yellow",
					"5", "Yellow",
					"6", "Yellow",
					"6", "Yellow",
					"7", "Yellow",
					"7", "Yellow",
					"8", "Yellow",
					"8", "Yellow",
					"9", "Yellow",
					"9", "Yellow",
					"Draw 2", "Yellow",
					"Draw 2", "Yellow",
					"Reverse", "Yellow",
					"Reverse", "Yellow",
					"Skip", "Yellow",
					"Skip", "Yellow",
					"Wild", "Black",
					"Wild", "Black",
					"Wild", "Black",
					"Wild", "Black",
					"Wild Draw 4", "Black",
					"Wild Draw 4", "Black",
					"Wild Draw 4", "Black",
					"Wild Draw 4", "Black"};
	
    // Initialize seed randomly
    srand(time(0));
  
    for (int i=0; i<SIZE ;i++)
    {
        // Random for remaining positions.
        int r = i + (rand() % (108 -i));
  
        Card temp = card[i]; //Swap card[i] with card[r]
        card[i] = card[r];
        card[r] = temp;
    }
    
     // Push the card into drawpile stack
    for (int i=0; i<SIZE; i++)
        drawpile.push(card[i].value, card[i].color); 
        
}

void distribute(Group group[], CardStack &drawpile)
{
	string draw_value, draw_color;
	
	for(int i=1; i<=7; i++) //Draw 7 cards
	{
		for(int i=1; i<=2; i++) //Each group has 2 players
		{
			for(int i=0; i<2; i++) //Sequence of each card g1p1 -> g2p1 -> g1p2 -> g2p2
			{
				drawpile.pop(draw_value, draw_color);
				group[i].draw(draw_value, draw_color);
				group[i].switchPlayer();
			}
		}	
			
	}
}

//Player of this group's turn 
void takeTurn(Group &current_group, CardStack &discardpile, CardStack &drawpile)
{
	string discardpile_value, discardpile_color;
	
	current_group.showCards();
	
	discardpile.peekTop(discardpile_value, discardpile_color);
	
	if(current_group.isPlayable(discardpile_value, discardpile_color))
	{
		int position;
		
		cout<<"Choose the position of the card to be played : ";
		cin>>position;
		
		//Input validation for position 
		while(position < 1 || position > current_group.playerCardNum())
		{
			cout<<"Please enter a valid position: ";
			cin>>position;
		}
		
		//Player must choose the valid card (match symbol or color or use wildcard)
		while(!current_group.isPlayable(position, discardpile_value, discardpile_color))
		{
			cout<<"The card chosen not match with the card at discard pile, please choose a valid card: ";
			cin>>position;
		
			while(position < 1 || position > current_group.playerCardNum())
			{
				cout<<"Please enter a valid position: ";
				cin>>position;
			}
		}
		
		//The card played from player push into discard pile stack
		current_group.play(position, discardpile_value, discardpile_color);
		discardpile.push(discardpile_value, discardpile_color);
	}
	
	else
	{
		string draw_value, draw_color;
		
		drawpile.pop(draw_value, draw_color);
		
		//If card drawn can be played, the player must play it
		if(draw_color==”Black” || draw_value==discardpile_value ||  draw_color==discardpile_color)
		{
			discardpile.push(draw_value, draw_color);
			cout<<"Top of discard pile now is ("<<draw_value<<", "<<draw_color<<")"<<endl;
		}
			
		else 
			current_group.draw(draw_value, draw_color);
			
	}
	
	current_group.switchPlayer();
}

void skip(int &turn)
{
	cout<<"Used skip, skip the next player’s move"<<endl; 
	turn+=2;  
} //next loop become 2nd next player

void reverse(int &turn, Group group[]) //Change current player of other group to next 
{ 
	cout<<"Used reverse, the sequence is reversed"<<endl; 

	If(turn % 2 == 1) //group 1 used the reverse card 
		group[1].switchPlayer(); //next turn of the next group changed to another player 

	else 
		group[0].switchPlayer(); 

	turn++; 
} 

void draw2(int &turn, Group group[], CardStack &drawpile) 
{ 
	string draw_value, string draw_color; 

	cout<<"Used draw 2, next player draws 2 card and skip"<<endl; 

	if(turn % 2 == 1) //Group 1 player used draw 2 card, group2 player draw 2 

		for(int i=1; i<=2; i++)  
		{
			drawpile.pop(draw_value, draw_color); 
			group[1].draw(draw_value, draw_color); 
		}

	else // group 2 player used draw 2 card, group1 player draw 2 

		for(int i=1; i<=2; i++) 
		{
			drawpile.pop(draw_value, draw_color); 
			group[0].draw(draw_value, draw_color); 
		}

	turn+=2; //skip next player 
} 

void wild(int &turn, CardStack &discardpile) 
{ 
	int choice;

	cout<<"Please determine the color on the discard pile: "; 
	cout<<"1: Red\n"; 
	cout<<"2: Green\n"; 
	cout<<"3: Blue\n"; 
	cout<<"4: Yellow\n"; 

	cin>>choice;	
	
	while(choice<1 || choice>4)
	{
		cout<<"Please enter the valid choice again: ";
		cin>>choice;
	}
	
	switch(choice) 
	{ 
		case 1 : cout<<"Player chose Red color\n"; discardpile.push(“ “, “Red”);	break; 
		case 2 : cout<<"Player chose Green color\n"; discardpile.push(“ “, “Green”);	break; 
		case 3 : cout<<"Player chose Blue color\n";  discardpile.push(“ “, “Blue”);	break; 
		case 4 : cout<<"Player chose Yellow color\n";  discardpile.push(“ “, “Yellow”);  
	} 

	turn++; 
} 

void draw4(int &turn, Group group[], CardStack &drawpile, CardStack &discardpile) 
{ 
	string chosen_color; 

	char choice;

	cout<<"Please determine the color on the discard pile: "; 
	cout<<"1: Red\n"; 
	cout<<"2: Green\n"; 
	cout<<"3: Blue\n"; 
	cout<<"4: Yellow\n"; 

	cin>>choice;	
	
	while(choice<'1' || choice>'4')
	{
		cout<<"Please enter the valid choice again: ";
		cin>>choice;
	}
	
	switch(choice) 
	{ 
		case 1 : cout<<"Player chose Red color\n"; chosen_color="Red";	break; 
		case 2 : cout<<"Player chose Green color\n"; chosen_color="Green";	break; 
		case 3 : cout<<"Player chose Blue color\n";  chosen_color="Blue";	break; 
		case 4 : cout<<"Player chose Yellow color\n";  chosen_color="Yellow";  
	}

	//Ask next player to challenge the player that used draw 4 card
	cout<<"Do you think opponent played draw 4 illegally? (have a card which is same color as chosen color) (Y/N)\n";
	cin>>choice; 
	
	while(choice != 'Y' || choice != 'y' || choice != 'N' || choice != 'n')
	{
		cout<<"Please enter valid input (Y/N) : ";
		cin>>choice
	}

	if(choice == 'Y' || choice == 'y') //try to challenge 
	{
		int challenged, challenger;
		
		if(turn % 2 == 1) //first group used +4 become challenged by other group 
		{
			challenged = 0; 
			challenger = 1;	 
		}
	
		else //second group used +4 become challenged by other group 
		{
			challenged = 1; 
			challenger = 0;	 
		}
	
		string draw_value, string draw_color; 
	
		if(group[challenged].isPlayable(" ", chosen_color) ) //challenge successfully 
		{
			cout<<"Challenge successfully, opponent draw 4 cards.\n"; 
	
			for(int i=1; i<=4; i++)  
			{
					drawpile.pop(draw_value, draw_color); 
					group[challenged].draw(draw_value, draw_color); 
			}
		}
	
		else //challenge failed 
		{
			cout<<"Challenge failed, you draw 6 cards.\n"; 
	
			for(int i=1; i<=6; i++)  
			{
				drawpile.pop(draw_value, draw_color); 
				group[challenger].draw(draw_value, draw_color); 
			}
		}
	}

	else //refuse to challenge, next player draw 4 cards
	{
		if(turn % 2 == 1) 
		{
			for(int i=1; i<=4; i++) 
			{
				drawpile.pop(draw_value, draw_color); 
				group[1].draw(draw_value, draw_color); 
			}
		}
		
		else 
		{
			for(int i=1; i<=4; i++) 
			{
				drawpile.pop(draw_value, draw_color); 
				group[0].draw(draw_value, draw_color); 
			}
		}
	}

	discardpile.push(" ", chosen_color); //Change color of discardpile

	turn+=2; //Skip next player

} 

int main()
{
	CardStack drawpile, discardpile; 

	Group group[2]; 

	shuffle(drawpile); //Generate and shuffle cards randomly
	distribute(group, drawpile); //distribute cards to players 

	int turn = 1;
	const int max_turn = 50; 
	bool win = false;

	while(!win || turn != max_turn) //Loop until player win the game or max turn reached
	{
		if(turn % 2 == 1) //odd turn for group 1, even for g2 
		{
			takeTurn(group[0], discardpile, drawpile); 

			if(group[0].playerCardNum == 0 )
			{
				cout<<"A player of group 1 has cleared all the card, group 1 win!!!"; 
				win == true; 
			}
		}

		else
		{
			takeTurn(group[1], discardpile, drawpile); 

			if(group[0].playerCardNum == 0 ) 
			{
				cout<<"A player of group 2 has cleared all the card, group 2 win!!!"; 
				win == true; 
			}
		}
 		
		discardpile.peekTop(discardpile_value, discardpile_color); 
	
		//Check the played card is power card that affect the player's move
		if(discardpile_value==”Skip”) 
			skip(turn); 
	
		else if(discardpile_value==”Reverse”) 
			reverse(turn, group);	 
	
		else if(discardpile_value==Draw 2”) 
			draw2(turn, group, drawpile); 
	
		else if(discardpile_value==”Wild”) 
			wild(turn, discardpile); 
	
		else if(discardpile_value==”Wild Draw 4”) 
			draw4(turn, group, drawpile, discardpile); 
	
		else 
			turn++; 
		
	}

}
