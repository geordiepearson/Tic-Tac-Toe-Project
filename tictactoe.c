#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(int gameBoard[]);
void playTurn(int gameBoard[], int* turn);
int checkInt(int* index);
int isdigit(int arg);
void hasWon(int gameBoard[], bool* gameOver);
void resetGame(int gameBoard[], int*turn, bool* gameOver);

int main(int argc, char** argv){
	bool gameOver = false; 
	int turn = 1;
	int gameBoard[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	printf("Hello, Welcome to Tic Tac Toe.\n");

	while(1){
		printBoard(gameBoard);
		playTurn(gameBoard, &turn);
		hasWon(gameBoard, &gameOver);
		if(gameOver)
		{
			resetGame(gameBoard, &turn, &gameOver);
		}
	}
	
	return 0;
}

void printBoard(int gameBoard[]){
	int i;
	int j;

	for (int i = 0; i < 9; ++i){
			printf("%d ", gameBoard[i]);
			if((i+1) % 3 == 0){
				printf("\n");
			}
	}
}

void playTurn(int gameBoard[], int* turn){
	int input;
	int flag = 0;
	int index;
	
	printf("Enter a number between 1-9:");

	while(flag == 0){
		flag = checkInt(&input);
	}
	
	index = input-1;
	if(gameBoard[index] != 0){
		printf("Square already taken. \n");
	}

	else{
		if (*turn % 2 == 0){
			gameBoard[index] = 2;
		}

		else{
			gameBoard[index] = 1;;
		}

		++ *turn;
	}
}

int checkInt(int* input){
	int intChecker = 0;

	intChecker = getchar();
	if(isdigit(intChecker)!=0){
			*input = intChecker - '0';
			return 1;
	}

	else{
		return 0;
	}
}

void hasWon(int gameBoard[], bool* gameOver){
	for (int i = 0; i < 7; i += 3){ /*checks rows*/
		if(gameBoard[i] == gameBoard[i+1] && gameBoard[i+1]== gameBoard[i+2]){
			if(gameBoard[i] != 0){
			*gameOver = true;
			}	
		}
	}

	for (int i = 0; i < 3; ++i){/*checks columns*/
		if(gameBoard[i] == gameBoard[i+3] && gameBoard[i+3] == gameBoard[i+6]){
			if(gameBoard[i] != 0){
			*gameOver = true;
			}	
		}
	}

	if(gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8]){/*check diagonal 1*/
		if(gameBoard[4] != 0){
			*gameOver = true;
		}	
	}

	if(gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6]){/*checks diagonal 2*/
		if(gameBoard[4] != 0){
			*gameOver = true;
		}	
	}	
}

void resetGame(int gameBoard[], int* turn, bool* gameOver){
	int i;

	if (*turn % 2 == 0)
	{
		printf("Player 1 Wins. Starting New Game. \n\n");
	}
	else{
		printf("Player 2 Wins. \n");
	}

	*gameOver = false; 
	*turn = 1;
	for (int i = 0; i < 9; ++i){
		gameBoard[i] = 0;
	}
}