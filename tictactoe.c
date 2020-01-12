#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*Function Declaration*/
void printBoard(int gameBoard[]);
void playTurn(int gameBoard[], int* turn);
int checkInt(int* index);
int isdigit(int arg);
void hasWon(int gameBoard[], bool* gameOver, bool* winner);
void resetGame(int gameBoard[], int*turn, bool* gameOver, bool* winner);

void printBoard(int gameBoard[]){
	/* A function used to print the gameboard. */
	int i;
	int j;

	for (int i = 0; i < 9; ++i){
			printf("%d ", gameBoard[i]);
			if((i+1) % 3 == 0){ /*For every 3 data points, prints a new line*/
				printf("\n");
			}
	}
}

int checkInt(int* input){
	/*A function to check whether the users input is an integer*/
	int intChecker = 0;

	intChecker = getchar();
	if(isdigit(intChecker)!=0){ /*If input is a digit*/
			*input = intChecker - '0'; /*Convert char to int*/
			return 1;
	}

	else{
		return 0;
	}
}

void playTurn(int gameBoard[], int* turn){
	/* A function used to take the players action and update the game board*/
	int input;
	int flag = 0;
	int index;
	
	printf("Enter a number between 1-9: \n");

	while(flag == 0){ /* While no number has been inputted*/
		flag = checkInt(&input);
	}
	
	index = input-1; /*Reduces the user input by 1 due to array indexing beginning at 0*/
	if(gameBoard[index] != 0){ /*If the tile is alreayd taken*/
		printf("Square already taken. \n");
	}

	else{
		if (*turn % 2 == 0){ /*If it is player 2's turn*/
			gameBoard[index] = 2;
		}

		else{ /*If it is player 1's turn*/
			gameBoard[index] = 1;
		}

		++ *turn;
	}
}

void hasWon(int gameBoard[], bool* gameOver, bool* winner){
	/*A function used to check if the game is over*/
	for (int i = 0; i < 7; i += 3){ /*checks rows*/
		if(gameBoard[i] == gameBoard[i+1] && gameBoard[i+1]== gameBoard[i+2]){
			if(gameBoard[i] != 0){
				*gameOver = true;
				*winner = true;
			}	
		}
	}

	for (int i = 0; i < 3; ++i){/*checks columns*/
		if(gameBoard[i] == gameBoard[i+3] && gameBoard[i+3] == gameBoard[i+6]){
			if(gameBoard[i] != 0){
			*gameOver = true;
			*winner = true;
			}	
		}
	}

	if(gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8]){/*check diagonal 1*/
		if(gameBoard[4] != 0){
			*gameOver = true;
			*winner = true;
		}	
	}

	if(gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6]){/*checks diagonal 2*/
		if(gameBoard[4] != 0){
			*gameOver = true;
			*winner = true;
		}	
	}

	int count=0; /*Checks if the board is full*/
	for (int i = 0; i < 9; ++i){
		if(gameBoard[i] != 0){
			++ count; 
		}
	}	
	if(count == 9){ /*If the board is full set the game to be over without a winner*/
		*gameOver = true;
	}
}

void resetGame(int gameBoard[], int* turn, bool* gameOver,bool* winner){
	/*A function to show the results of the previous game and begin a new game*/
	int i;
	if(*winner){
		if (*turn % 2 == 0) /*If the game ended in the previous turn of player 1*/
		{
			printf("Player 1 Wins. Starting New Game. \n\n");
		}
		else{ /*If the game ended in the previous turn of player 2*/
			printf("Player 2 Wins. Starting New Game. \n\n");
		}
	}

	else{ /*If the game ended without a winner*/
		printf("Stalemate. Starting New Game. \n\n");
	}

	/*Set the neccesary variables to intial values*/
	*gameOver = false; 
	*turn = 1;
	*winner = false;
	for (int i = 0; i < 9; ++i){
		gameBoard[i] = 0;
	}
}

int main(int argc, char** argv){
	/*Intialises variables and sets them to default state*/
	bool gameOver = false; 
	bool winner = false;
	int turn = 1;
	int gameBoard[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
	
	printf("Hello, Welcome to Tic Tac Toe.\n");

	while(1){ /*Causes the game to continously play and reset upon game over*/
		printBoard(gameBoard);
		playTurn(gameBoard, &turn);
		hasWon(gameBoard, &gameOver, &winner);
		if(gameOver)
		{
			resetGame(gameBoard, &turn, &gameOver, &winner);
		}
	}
	
	return 0;
}