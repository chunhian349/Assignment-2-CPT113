#include <iostream>
#include <ctime>
using namespace std;
  
// Function which shuffle and print the array
void shuffle(CardStack drawpile)
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

int main()
{
	
}
