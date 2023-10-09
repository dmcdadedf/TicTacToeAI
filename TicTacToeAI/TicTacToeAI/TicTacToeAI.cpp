#include <iostream>

const int size = 3;

bool checkIfXWins(char board[size][size], int size);
bool checkIfOWins(char board[size][size], int size);
void printBoard(char board[size][size]);
void initBoard(char board[size][size], int size);

struct Move;
Move findBestMove(char board[size][size]);
int miniMax(char board[size][size], int depth, bool isMaximizing);
bool isMovesLeft(char board[size][size], int size);

int main()
{
	bool xWins = false;
	bool oWins = false;

	char mainBoard[size][size];
	
	initBoard(mainBoard, size);

	printBoard(mainBoard);

	xWins = checkIfXWins(mainBoard, size);
	oWins = checkIfOWins(mainBoard, size);
	
	if (xWins) {
		std::cout << "X Wins";
	}
	if (oWins) {
		std::cout << "O Wins";
	}
	
}

struct Move {
	int row;
	int col;
};

bool checkIfOWins(char board[][size], int size)
{
	int numInARow = 0;
	
	//Check Diagonal 1
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

	////Check Diagonal 2
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

	//Check Horozontal

	numInARow = 0;

	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 'O' || board[i][j] == 'o')
			{
				numInARow++;
			}
			else
			{
				break;
			}
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
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 'O' || board[i][j] == 'o')
			{
				numInARow++;
			}
			else
			{
				break;
			}
		}
	}

	if (numInARow == size)
	{
		return true;
	}

	return false;
}

bool checkIfXWins(char board[][size], int size)
{
	int numInARow = 0;

	//Check Diagonal 1
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

	////Check Diagonal 2
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

	//Check Horozontal

	numInARow = 0;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'x')
			{
				numInARow++;
			}
			else
			{
				break;
			}
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
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'x')
			{
				numInARow++;
			}
			else
			{
				break;
			}
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

Move findBestMove(char board[size][size]) {
	int bestVal = 0;
	Move bestMove;
	bestMove.col = -1;
	bestMove.row = -1;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == '_') {
				board[i][j] = 'x';
				int moveVal = miniMax(board, 0, false);
				board[i][j] = '_';
				if (moveVal > bestVal) {
					bestVal = moveVal;
					bestMove.row = i;
					bestMove.col = j;
				}
			}
		}
		return bestMove;
	}
}

int miniMax(char board[size][size], int depth, bool isMaximizing) {
	int score;
	if (checkIfXWins(board, size)){
		return 10;
	}
	if (checkIfOWins(board, size)) {
		return -10;
	}
	if (!isMovesLeft(board, size)) {
		return 0;
	}
	if (isMaximizing) {
		int bestVal = -1000;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (board[i][j] == '_') {
					board[i][j] = 'X';
					bestVal = std::max(bestVal, miniMax(board, depth + 1, false));
				}
				board[i][j] = '_';
			}

		}
		return bestVal;
	}
	else {
		int bestVal = 1000;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (board[i][j] == '_') {
					board[i][j] = 'O';
					bestVal = std::min(bestVal, miniMax(board, depth + 1, true));
				}
				board[i][j] = '_';
			}

		}
		return bestVal;
	}
}

void initBoard(char board[][size], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			board[j][i] = '_';
		}
	}
}

bool isMovesLeft(char board[size][size], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == '-') {
				return false;
			}
		}
	}
	return true;
}