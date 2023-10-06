#include <iostream>

const int size = 3;

bool checkIfXWins(char board[size][size], int moveX, int moveY, int size);
bool checkIfOWins(char board[size][size], int moveX, int moveY, int size);
void printBoard(char board[size][size]);

int main()
{
	bool xWins = false;
	bool oWins = false;

	char mainBoard[size][size] = { { 'x','_','_'},
								   { 'x','_','_'},
								   { 'x','_','_'} };

	printBoard(mainBoard);

	xWins = checkIfXWins(mainBoard, 0, 0, size);
	oWins = checkIfOWins(mainBoard, 2, 2, size);
	
	if (xWins) {
		std::cout << "X Wins";
	}
	if (oWins) {
		std::cout << "O Wins";
	}
	
}

bool checkIfXWins(char board[][size], int moveX, int moveY, int size)
{
	int numInARow = 0;
	
	//Check Diagonal 1
	if (moveX == moveY) 
	{
		numInARow = 0;

		for (int i = 0; i < size; i++)
		{
			if (board[i][i] == 'X' || board[i][i] == 'x')
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
	}

	////Check Diagonal 2
	if (moveX + moveY == size - 1) 
	{
		numInARow = 0;

		for (int i = 0; i < size; i++)
		{
			if (board[size - i - 1][i] == 'X' || board[size - i - 1][i] == 'x')
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
	}

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

bool checkIfOWins(char board[][size], int moveX, int moveY, int size)
{
	int numInARow = 0;

	//Check Diagonal 1
	if (moveX == moveY)
	{
		numInARow = 0;

		for (int i = 0; i < size; i++)
		{
			if (board[i][i] == 'O' || board[i][i] == 'o')
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
	}

	////Check Diagonal 2
	if (moveX + moveY == size - 1)
	{
		numInARow = 0;

		for (int i = 0; i < size; i++)
		{
			if (board[size - i - 1][i] == 'O' || board[size - i - 1][i] == 'o')
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
	}

	//Check Horozontal

	numInARow = 0;

	for (int i = 0; i < size; i++)
	{
		if (board[i][moveY] == 'O' || board[i][moveY] == 'o')
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

	//Check Vertical

	numInARow = 0;

	for (int i = 0; i < size; i++)
	{
		if (board[moveX][i] == 'O' || board[moveX][i] == 'o')
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
			std::cout << board[j][i];
		}
		std::cout << "\n";
	}
}



