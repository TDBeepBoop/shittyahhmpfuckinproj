#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdbool.h>

#define BETWEEN(value, min, max) (value < max && value > min)

void BoardState()
{
	system("cls");
	int i,j,k,l,m;
	char BackgammonBoard[50][50];
	char MoveFinder;
	int Rowsi[50];
	int Colsj[50];
	int Count = 0;
	int Total = 0;
	bool Game = true;
	int TurnCounter = 1;
	int WhosTurn = 1;
	char EndTurnChoice;

	for(k=0;k<14;k++)
	{
		for(l=0;l<28;l++)
		{
			if(k == 0 || k == 13 || k == 7 || k == 6)
			{
				BackgammonBoard[k][l] = '-';
			}
			else if(k > 0 && k < 14)
			{
				
				if(l == 13 || l == 14){
					BackgammonBoard[k][l] = '/';
				}
				else if(l % 2 == 1 && l < 13 )
				{
					BackgammonBoard[k][l] = ' ';
				}
				else if(l % 2 == 0 && l < 13 )
				{
					BackgammonBoard[k][l] = '|';
				}
				else if(l % 2 == 0 && l > 14 )
				{
					BackgammonBoard[k][l] = ' ';
				}
				else if(l % 2 == 1 && l > 14 )
				{
					BackgammonBoard[k][l] = '|';
				}
				else if(l == 29)
				{
					BackgammonBoard[k][l] = '|';
				}
			}
			
		}
		for(m=0;m<15;m++)
		{
			if(m>0 && m<6)
			{
				BackgammonBoard[m][1] = 'B';
			}
			if(m>7 && m<13)
			{
				BackgammonBoard[m][1] = 'W';
			}
			if(m>0 && m<4)
			{
				BackgammonBoard[m][9] = 'W';
			}
			if(m>9 && m<13)
			{
				BackgammonBoard[m][9] = 'B';
			}
			if(m>0 && m<6)
			{
				BackgammonBoard[m][16] = 'W';
			}
			if(m>7 && m<13)
			{
				BackgammonBoard[m][16] = 'B';
			}
			if(m>0 && m<3)
			{
				BackgammonBoard[m][26] = 'B';
			}
			if(m>10 && m<13)
			{
				BackgammonBoard[m][26] = 'W';
			}
		}
		
	}
	
	for(i=0;i<14;i++)
	{
		for(j=0;j<28;j++)
		{
			printf("%c",BackgammonBoard[i][j]);
		}
		printf("\n");
	}
	
	while (Game == true)
	{
		printf("Turn: %d\n",TurnCounter);
		if(WhosTurn == 1)
		{
			printf("Player 1's Turn\n");
		}
		if(WhosTurn == 0)
		{
			printf("Player 2's Turn\n");
		}

		printf("Find Moves?(Y/N):");
		scanf("%s",&MoveFinder);
		if(MoveFinder == 'Y' || MoveFinder == 'y')
		{
			if (WhosTurn == 1)
			{
				for(int i=0; i<14; i++){
    				for(int j=0; j<28; j++){
      					if(i<7 && BackgammonBoard[i][j] == 'W' && (BackgammonBoard[i+1][j] == ' ' || BackgammonBoard[i+1][j] == '-')){
        					printf("Item found at [%d, %d] \n", i, j);
							Rowsi[Count] = i;
							Colsj[Count] = j;
							Count++;
							Total++;
      					}
	  					if(i>7 && BackgammonBoard[i][j] == 'W' && (BackgammonBoard[i-1][j] == ' ' || BackgammonBoard[i-1][j] == '-'))
	  					{
							printf("Item found at [%d, %d] \n", i, j);
							Rowsi[Count] = i;
							Colsj[Count] = j;
							Count++;
							Total++;
	  					}
    				}
				}
			
			}
			if (WhosTurn == 0)
			{
				for(int i=0; i<14; i++){
    				for(int j=0; j<28; j++){
      					if(i<7 && BackgammonBoard[i][j] == 'B' && (BackgammonBoard[i+1][j] == ' ' || BackgammonBoard[i+1][j] == '-')){
        					printf("Item found at [%d, %d] \n", i, j);
							Rowsi[Count] = i;
							Colsj[Count] = j;
							Count++;
							Total++;
      					}
	  					if(i>7 && BackgammonBoard[i][j] == 'B' && (BackgammonBoard[i-1][j] == ' ' || BackgammonBoard[i-1][j] == '-'))
	  					{
							printf("Item found at [%d, %d] \n", i, j);
							Rowsi[Count] = i;
							Colsj[Count] = j;
							Count++;
							Total++;
	  					}
    				}
				}
			
			}

		int Move = 1;
		int PieceMoveChoice;
		int Movement;
		int Results1 = 0;
		int Results2 = 0;
		int CombinedResults = 0;
		int DiceSelect;
		int HorizontalMovement = 0;
		int VerticalMovement = 0;
        int MovesLeft;

		for(i=0; i<10; i++)
		{
			if(Rowsi[i]!=0 || Colsj[i]!=0)
			{
				printf("%d. Piece @ %d, %d\n",Move,Rowsi[i],Colsj[i]);
				Move++;
			}
		}
		
		printf("There are %d possible moves\n",Move-1);
		printf("Select a Piece to Move: ");
		scanf("%d",&PieceMoveChoice);
		if(PieceMoveChoice <= Move)
		{
			printf("You are Selecting Piece %d, at Location %d,%d\n",PieceMoveChoice,Rowsi[PieceMoveChoice-1],Colsj[PieceMoveChoice-1]);
            HorizontalMovement = Rowsi[PieceMoveChoice-1];
            VerticalMovement = Colsj[PieceMoveChoice-1];
			time_t t;
			srand((unsigned) time(&t));
			printf("Rolling Dice\n");
			Results1 = (rand ()%6 )+ 1;
			Results2 = (rand ()%6 )+ 1;
			printf("Die 1: %d\nDie 2: %d\n",Results1,Results2);
			printf("Would you like to Combine your dice?(1/2): ");
			scanf("%d",&DiceSelect);
			if(DiceSelect = 1)
			{
				CombinedResults = Results1 + Results2;
                MovesLeft = CombinedResults;
				
				if(WhosTurn = 1) 
				{
					if(BETWEEN(Colsj[PieceMoveChoice-1],0,13)) //Left Hand Side
					{
						if(BETWEEN(Rowsi[PieceMoveChoice-1],0,7)) //Quad 1
						{
							printf("Piece %d,%d is in Quad 1\n",Rowsi[PieceMoveChoice-1]+3,Colsj[PieceMoveChoice-1]);
						}
						if(BETWEEN(Rowsi[PieceMoveChoice-1],8,13)) //Quad 3
						{
							printf("Piece %d,%d is in Quad 3\n",Rowsi[PieceMoveChoice-1],Colsj[PieceMoveChoice-1]);
						}
					}
					if(BETWEEN(Colsj[PieceMoveChoice-1],15,26)) //Right Hand Side
					{
						if(BETWEEN(Rowsi[PieceMoveChoice-1],0,7)) //Quad 2
						{
							printf("Piece %d,%d is in Quad 2\n",Rowsi[PieceMoveChoice-1],Colsj[PieceMoveChoice-1]);
						}
						if(BETWEEN(Rowsi[PieceMoveChoice-1],8,13)) //Quad 4
						{
							printf("Piece %d,%d is in Quad 4\n",Rowsi[PieceMoveChoice-1],Colsj[PieceMoveChoice-1]);
						}
					}
                }
				BackgammonBoard[Rowsi[PieceMoveChoice-1]][Colsj[PieceMoveChoice-1]] = ' ';
                    BackgammonBoard[HorizontalMovement][VerticalMovement] = 'W';
				
			}



			/*system("cls");
			for(i=0;i<14;i++)
			{
			for(j=0;j<28;j++)
			{
				printf("%c",BackgammonBoard[i][j]);
			}
			printf("\n");
			}
			printf("%d,%d\n",HorizontalMovement,VerticalMovement);
		}*/
		}
		printf("Would you like to End Your Turn or Stop Playing?(E/S): ");
		scanf("%s",&EndTurnChoice);
		if (EndTurnChoice == 'E')
		{
			TurnCounter++;
			if (TurnCounter % 2 == 1)
			{
				WhosTurn = 1;
			}
			if (TurnCounter % 2 == 0)
			{
				WhosTurn = 0;
			}
			
			
		}
		if(EndTurnChoice == 'S')
		{
			Game = false;
		}
		

	}
}
}

	
 

/*
int TurnFunc(int TurnCounter2, int WhosTurnIsIt)
{
	int Turn;
	Turn = TurnCounter2 % 2;
	if(Turn == 1)
	{
		WhosTurnIsIt = 1;
		return 1;
	}
	if(Turn = 0)
	{
		WhosTurnIsIt = 0;
		return 0;
	}
}
*/

void MovePiece()
{
		int ResultArray[3];
		int Results1 = 0;
		int Results2 = 0;
		char DiceRollSelection;

		time_t t;
		srand((unsigned) time(&t));
		printf("Rolling Dice\n");
		Results1 = (rand ()%6 )+ 1;
		Results2 = (rand ()%6 )+ 1;
		printf("Die 1: %d\nDie 2: %d\n",Results1,Results2);
}

void MainMenu()
{
	printf("Welcome to Backgammon!\n\n1. Start a New Game\n2.Load a Save\n3. High Scores\n4. Credits\n5. Quit\n\nEnter your selection: ");
	char MenuSelection;
	scanf("%s",&MenuSelection);
	if(MenuSelection == '1')
	{
		BoardState();
	}
}

int main()
{
	char Select;
	MainMenu();
	//printf("Roll Dice?(Y/N): ");
	//scanf("%s",&Select);
	//if(Select == 'Y' || Select == 'y')
	//{
	//	DiceRoll();
	//}
}

