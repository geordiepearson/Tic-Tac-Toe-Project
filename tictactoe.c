#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void printBoard(int gameBoard[]);
void playTurn(int gameBoard[], int* turn);
int checkInt(int* index);
int isdigit(int arg);
void hasWon(int gameBoard[]);

int main(int argc, char** argv){
	bool gameOver = false; 
	int turn = 1;
	int gameBoard[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	printf("Hello, Welcome to Tic Tac Toe.\n");

	printBoard(gameBoard);
	hasWon(gameBoard);

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

	if (*turn % 2 == 0){
		gameBoard[index] = 2;
	}

	else{
		gameBoard[index] = 1;;
	}

	++ *turn;
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

void hasWon(int gameBoard[]){
	for (int i = 0; i < 7; i += 3){
		if(gameBoard[i] == gameBoard[i+1] == gameBoard[i+2]){
			printf("winner \n");
		}
	}	
}