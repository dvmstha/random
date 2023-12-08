#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void drawHangman(int numLives); 
int main() {
	char choice;
do
{
	srand(time(NULL));
	
	char guessWords[][16] = {
		"green", "yellow","purple","windows","linux","apple","basketball","football","golf"	
	};
	
	int randomIndex = rand() % 9;
	
	int numLives = 0;
	int numCorrect = 0;
	int oldCorrect = 0;
	
	int lengthOfWord = strlen(guessWords[randomIndex]);

	int letterGuessed[11] = { 0,0,0,0,0,0,0,0,0,0,0 };
	
	int quit = 0;	
	
	int loopIndex = 0;
	int reguessed = 0;
	
	char guess[16];
	char letterEntered;	
		
	while ( numCorrect < lengthOfWord ) {
	
		printf("\n\nNew Turn....\nHangman Word:");
		
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				printf("%c",guessWords[randomIndex][loopIndex]);				
			} else {
				printf("_");
			}
		
		}	
		
		drawHangman(numLives);
		
		printf("\n");
	
		printf("Number Correct So Far:%d\n",numCorrect);
		printf("Enter a guess letter:");
		fgets(guess, 16, stdin);
		strlwr(guess);
		if( strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}
		system("cls");
		letterEntered = guess[0];
		reguessed = 0; 
		
		printf("Letter Entered:%c\n",letterEntered);
		printf("Lives used:%d/5\n",numLives+1);
		
		oldCorrect = numCorrect;
		
		for( loopIndex = 0; loopIndex < lengthOfWord; loopIndex++) {
		
			if(letterGuessed[loopIndex] == 1) {
				if(guessWords[randomIndex][loopIndex] == letterEntered) {
					reguessed = 1; 
					break;
				} 
				continue;
			}
			if( letterEntered == guessWords[randomIndex][loopIndex] ) {
				letterGuessed[loopIndex] = 1;
				numCorrect++;				
			}		
		
		}	
		
		if( oldCorrect == numCorrect && reguessed == 0) {
			numLives++;
			printf("Sorry, wrong guess\n");
			if (numLives == 5) {
				break;
			}
		} else if( reguessed == 1) {
			printf("Already Guessed!!\n");
		} else {
			printf("Correct guess :)\n");
		}

	}
	if( quit == 1 ) {	
		printf("\nthe user quit early\n");
	} else if (numLives == 5) {
		printf("\nSorry you lose, the word was: %s\n",
		guessWords[randomIndex]);	
	} else  {	
		printf("\nYOU WIN!!! :)\n");
	} 
	
	printf("\nDo you want to Play Again?(Y/N)\n");
	choice= getche();
	} 
	while (choice=='Y'|| choice =='y');
	return 0;
}
void drawHangman(int numLives)
{
    const char* hangmanParts[]
        = { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };
 
    printf("\n");
    for (int i = 0; i <= numLives; i++) {
        printf("%s\n", hangmanParts[i]);
    }
}
