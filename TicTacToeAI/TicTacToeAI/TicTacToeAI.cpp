#include <iostream>

const int size = 4;

bool checkIfXWins(char board[size][size], int moveX, int moveY, int size);
void printBoard(char board[size][size]);

int main()
{
	bool xWins = false;

	char mainBoard[size][size] = { { 'x','o','o','x'},
								   { 'o','x','x','o'},
								   { 'o','x','x','o'},
								   { 'x','o','o','x'} };

	printBoard(mainBoard);

	xWins = checkIfXWins(mainBoard, 0, 0, size);
	
	std::cout << xWins;
}

bool checkIfXWins(char board[][size], int moveX, int moveY, int size)
{
	int numInARow = 0;

	std::cout << board[moveX][moveY] << "\n";
	
	//Check Diagonal 1
	//if (moveX == moveY) 
	//{

	//}

	////Check Diagonal 2
	//if (moveX + moveY == size - 1) 
	//{

	//}

	//Check Horozontal

	numInARow = 0;

	for (int i = 0; i < size; i++) 
	{
		if (board[i][moveY] == 'X' || board[i][moveY] == 'x')
		{
			numInARow++;
		}
		else 
		{
			break;
		}
	}

	if(numInARow == size)
	{
		return true;
	}

	//Check Vertical

	numInARow = 0;

	for (int i = 0; i < size; i++)
	{
		if (board[moveX][i] == 'X' || board[moveX][i] == 'x')
		{
			numInARow++;
		}
		else
		{
			break;
		}
	}

	if (numInARow == size)
	{
		return true;
	}

	return false;
}

void printBoard(char board[][size]) 
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++) 
		{
			std::cout << board[i][j];
		}
		std::cout << "\n";
	}
}



