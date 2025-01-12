#include <iostream>
#include <ctime>
#include <string>
#include "CardStack.h"
#include "Group.h"
#include "Player.h"
using namespace std;

//Randomly shuffle the array of Card objects
//Then push into drawpile CardStack one by one
void shuffle(CardStack &drawpile)
{
	const int SIZE = 108;
	
	struct Card
	{
		string value;
		string color;
	};
	
    // There are 108 different UNO cards
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
        // Generate random subscript r from remaining positions.
        int r = i + (rand() % (108 -i));
  
        Card temp = card[i]; //Swap card[i] with card[r]
        card[i] = card[r];
        card[r] = temp;
    }
    
     // Push the card into drawpile stack
    for (int i=0; i<SIZE; i++)
        drawpile.push(card[i].value, card[i].color); 
        
}

//Distribute card from one player to another player
//Each player get 7 cards
void distribute(Group *group, CardStack &drawpile, CardStack &discardpile)
{
	string draw_value, draw_color;
	
	for(int i=1; i<=7; i++) //Draw 7 cards
	{
		for(int j=1; j<=2; j++) //Each group has 2 players
		{
			for(int k=0; k<2; k++) //Sequence of each card g1p1 -> g2p1 -> g1p2 -> g2p2 -> g1p1 -> ...
			{
				drawpile.pop(draw_value, draw_color);
				group[k].draw(draw_value, draw_color);
				group[k].switchPlayer();
			}
		}	
	}
	
	//After distribute, draw until get a number card then push on the discard pile
	//To determine what card should the first player play
	drawpile.pop(draw_value, draw_color);
	
	while(draw_value == "Skip" || draw_value == "Reverse" || draw_value == "Draw 2" || draw_value == "Wild" || draw_value == "Wild Draw 4")
	{
		drawpile.pop(draw_value, draw_color);
	}
	
	discardpile.push(draw_value, draw_color);
}

//Player of the current group's turn 
void takeTurn(Group &current_group, CardStack &discardpile, CardStack &drawpile, bool &ignore_discard_pile)
{
	string discardpile_value, discardpile_color;
	
	//Show the player's cards
	cout<<"Card List: \n";
	current_group.showCards();
	
	//Get the value and color of the card at the top of discard pile
	discardpile.peekTop(discardpile_value, discardpile_color);
	
	//If the player has at least one card to play
	if(current_group.isPlayable(discardpile_value, discardpile_color))
	{
		int position;
		
		//Input the position of the card to be played
		cout<<"Choose the position of the card to be played : ";
		cin>>position;
		
		//Input validation for position 
		while(position < 1 || position > current_group.playerCardNum())
		{
			cout<<"Please enter a valid position: ";
			cin>>position;
		}
		
		//Player must choose the valid card (match symbol or color, or wildcard)
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
		cout<<"You played a card...\n";
	}
	
	else //If the player has no card match with discard pile
	{
		//Need draw a card from top of draw pile
		cout<<"No card can be played, need draw card from draw pile...\n";
		string draw_value, draw_color;
		
		drawpile.pop(draw_value, draw_color);
		
		//If card drawn can be played, the player must play it
		if(draw_color=="Black" || draw_value==discardpile_value ||  draw_color==discardpile_color)
		{
			cout<<"Drawn card can be played, placed on the discard pile...\n";			
			discardpile.push(draw_value, draw_color);
		}
			
		else //If the card drawn cannot be played, store in the card list of the player
		{
			cout<<"Drawn card cannot be played, remain at your hand...\n";
			current_group.draw(draw_value, draw_color);
			
			//This player did not play any card
			//The power/wild card played by previous player which still on the discard pile may trigger again
			//The power/wild card should be ignored
			ignore_discard_pile = true; 
		}
			
	}
	
	system("pause");
	cout<<endl;
}

//Current player played skip card
void skip(int &turn, Group group[], int current_group_subscript)
{
	cout<<"Used skip, skip the next player's move"<<endl; 
	
	if(current_group_subscript == 0) //group 1 player skip group 2 player
		group[1].switchPlayer(); 
	
	else //group 2 player skip group 1 player
		group[0].switchPlayer();
		
	turn+=2;  
} //next loop become 2nd next player

//Current player played reverse card
//Reverse the player sequence by switching other group's player
//Example g1p1 -> g2p1 -> g1p2 become g1p1 -> g2p2 -> g1p2
void reverse(int &turn, Group group[]) 
{ 
	cout<<"Used reverse, the sequence is reversed"<<endl; 

	if(turn % 2 == 1) //Group 1 player used the reverse card 
		group[1].switchPlayer(); 
	
	else  //Group 2 player used reverse card
		group[0].switchPlayer(); 

	turn++; 
} 

//Current player played draw 2 card to next player
void draw2(int &turn, Group group[], CardStack &drawpile) 
{ 
	string draw_value, draw_color; 

	cout<<"Used draw 2, next player draws 2 card and skip"<<endl; 

	if(turn % 2 == 1) //Group 1 player used draw 2 card, group 2 player draw 2 
	{
		for(int i=1; i<=2; i++)  
		{
			drawpile.pop(draw_value, draw_color); 
			group[1].draw(draw_value, draw_color); 
		}
		
		group[1].switchPlayer();
	}

	else // group 2 player used draw 2 card, group 1 player draw 2 
	{
		for(int i=1; i<=2; i++) 
		{
			drawpile.pop(draw_value, draw_color); 
			group[0].draw(draw_value, draw_color); 
		}
		
		group[0].switchPlayer();
	}

	turn+=2; //skip next player 
} 

//Current player played wild card
//Select a desired color to change the color can be played on the discardpile
void wild(int &turn, CardStack &discardpile) 
{ 
	int choice;

	cout<<"You used wild card.\n";
	cout<<"Please determine the color on the discard pile: \n"; 
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
		case 1 : cout<<"Player chose Red color\n"; discardpile.push("Wild", "Red");	break; 
		case 2 : cout<<"Player chose Green color\n"; discardpile.push("Wild", "Green");	break; 
		case 3 : cout<<"Player chose Blue color\n";  discardpile.push("Wild", "Blue");	break; 
		case 4 : cout<<"Player chose Yellow color\n";  discardpile.push("Wild", "Yellow");  
	} 
	
	cout<<endl;
	turn++; 
} 

//Current player played wild draw 4 card
void draw4(int &turn, Group group[], CardStack &drawpile, CardStack &discardpile) 
{ 
	string chosen_color; 

	char choice;
	
	//Select a desired color to change the color can be played on the discardpile 
	cout<<"You used wild draw 4 card.\n";
	cout<<"Please determine the color on the discard pile: \n"; 
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
		case '1' : cout<<"Player chose Red color\n"; chosen_color="Red";	break; 
		case '2' : cout<<"Player chose Green color\n"; chosen_color="Green";	break; 
		case '3' : cout<<"Player chose Blue color\n";  chosen_color="Blue";	break; 
		case '4' : cout<<"Player chose Yellow color\n";  chosen_color="Yellow";  
	}

	//Ask next player to challenge the player that used draw 4 card
	cout<<"Question to next player: Do you think opponent played draw 4 illegally? (Y/N)\n";
	cin>>choice; 
	
	while(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n')
	{
		cout<<"Please enter valid input (Y/N) : ";
		cin>>choice;
	}

	string draw_value, draw_color; 
	
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
	
		string discardpile_value, discardpile_color;
	
		discardpile.pop(discardpile_value, discardpile_color); //This get the +4 record
		discardpile.peekTop(discardpile_value, discardpile_color); //This get the card at discard pile before +4 played
	
		//Challenge successfully
		//Means the player can play a non-wild card before he/she choose to play wild draw 4
		if(group[challenged].isIllegal(discardpile_value, discardpile_color) ) 
		{
			cout<<"Challenge successfully, opponent draw 4 cards, your move still will be skipped.\n"; 
	
			for(int i=1; i<=4; i++)  
			{
					drawpile.pop(draw_value, draw_color); 
					group[challenged].draw(draw_value, draw_color); 
			}
		}
	
		else //challenge failed 
		{
			cout<<"Challenge failed, you draw 6 cards and your move will be skipped.\n"; 
	
			for(int i=1; i<=6; i++)  
			{
				drawpile.pop(draw_value, draw_color); 
				group[challenger].draw(draw_value, draw_color); 
			}
		}
		
		group[challenger].switchPlayer();
	}

	else //No attempt to challenge, draw 4 cards and skip
	{
		cout<<"You will draw 4 cards and your move will be skipped.\n";
		
		if(turn % 2 == 1) 
		{
			for(int i=1; i<=4; i++) 
			{
				drawpile.pop(draw_value, draw_color); 
				group[1].draw(draw_value, draw_color); 
			}
			
			group[1].switchPlayer();
		}
		
		else 
		{
			for(int i=1; i<=4; i++) 
			{
				drawpile.pop(draw_value, draw_color); 
				group[0].draw(draw_value, draw_color); 
			}
			
			group[0].switchPlayer();
		}
	}

	discardpile.push("Wild Draw 4", chosen_color); //Change color of discardpile

	turn+=2; //Skip next player's turn
	
	cout<<endl;
} 

int main()
{
	//2 instance of CardStack:
	//	-Drawpile stack where the player draw the card at the top of the stack
	//	-Discardpile stack where the player place the played card at the top of the stack	
	CardStack drawpile, discardpile; 

	Group group[2]; //This game is 2v2 (2 groups, 2 players each group)
	
	cout<<"Game start...\n";
	cout<<"Distribute card to each player...\n";
	system("pause");
	shuffle(drawpile); //Generate and shuffle cards randomly
	distribute(group, drawpile, discardpile); //distribute cards to players 

	int turn = 1;
	int current_group_subscript;
	const int max_turn = 50; 
	
	while(turn <= max_turn) //Game continues until player win the game or max turn reached
	{
		//Show the card at the top of discard pile to know which card can be played 
 		string discardpile_value, discardpile_color;
		discardpile.peekTop(discardpile_value, discardpile_color); 
		cout<<"\nTop of discard pile now is ("<<discardpile_value<<", "<<discardpile_color<<")"<<endl;
		cout<<"Turn: "<<turn<<endl;
		
		if(turn % 2 == 1) //Odd turn, group 1 player's move
		{
			current_group_subscript = 0;
			cout<<"Group 1 Player "<<group[current_group_subscript].getPlayerSequence()<<"'s move..."<<endl;
		}
		
		else //Even turn, group 2 player's move
		{
			current_group_subscript = 1;
			cout<<"Group 2 Player "<<group[current_group_subscript].getPlayerSequence()<<"'s move..."<<endl;
		}
		
		bool ignore_discard_pile = false; //Ignore power/wild card on the discard pile if the card is played by previous player
		takeTurn(group[current_group_subscript], discardpile, drawpile, ignore_discard_pile); 

		//If the player cleared all the card before max turn, the player and teammate win.
		if(group[current_group_subscript].playerCardNum() == 0 )
		{
			cout<<"A player of group "<<current_group_subscript+1<<" has cleared all the card, group "<<current_group_subscript+1<<" win!!!\n"; 
			break;
		}
		
		//If the player left 1 card after played a card, the player will say 'UNO'
		else if(group[current_group_subscript].playerCardNum() == 1 )
			cout<<"Group "<<current_group_subscript+1<<" Player "<<group[current_group_subscript].getPlayerSequence()<<" says UNO!!!\n";
		
		//Get the card played by current player
		discardpile.peekTop(discardpile_value, discardpile_color); 
		
		//If current player has played a card, check the type of card played
		if(ignore_discard_pile == false)
		{
			//Check the played card is power card that affect the player's move
			if(discardpile_value=="Skip") 
				skip(turn, group, current_group_subscript); 
		
			else if(discardpile_value=="Reverse") 
				reverse(turn, group);	 
		
			else if(discardpile_value=="Draw 2") 
				draw2(turn, group, drawpile); 
		
			else if(discardpile_value=="Wild") 
				wild(turn, discardpile); 
		
			else if(discardpile_value=="Wild Draw 4") 
				draw4(turn, group, drawpile, discardpile); 
		
			else 
				turn++; 
		}
		
		//If current player do not play card, power/wild card on the discard pile played by previous player should be ignored
		else
			turn++;
		
		//Next same group's turn should be next player play the card 
		//Example g1p1 -> g2p1 -> g1p2 so next time g1's turn should switched to p2
		group[current_group_subscript].switchPlayer();
		cout<<"Next player...\n";
		system("pause");
		system("cls");
	}
	
	//If the loop exit because exceed maximum turn, the match is considered draw
	if(turn > max_turn)
	{
		cout<<"Number of turns exceed the maximum turn, this match considered draw...\n";
	}

	return 0;
}
