#include <iostream>
#include <chrono>

using namespace std::chrono;

const int size = 3;

bool checkIfXWins(char* board[size], int size);
bool checkIfOWins(char* board[size], int size);
void printBoard(char* board[size]);
void initBoard(char* board[size], int size);

struct Move {
	int row = -1;
	int col = -1;
};

Move findBestMove(char* board[size]);
int miniMax(char* board[size], int depth, bool isMaximizing);
bool isMovesLeft(char* board[size], int size);

int main()
{
	auto start = high_resolution_clock::now();
	bool xWins = false;
	bool oWins = false;

	char** mainBoard = new char* [size];

	for (int i = 0; i < size; i++) 
	{

		mainBoard[i] = new char[size];
	}
	
	initBoard(mainBoard, size);

	printBoard(mainBoard);

	Move xMove , yMove;
	
	xMove = findBestMove(mainBoard);
	std::cout << xMove.col << " " << xMove.row;
	//mainBoard[xMove.row][xMove.col] = 'x';
	printBoard(mainBoard);

	
	if (xWins) {
		std::cout << "X Wins";
	}
	else if (oWins) {
		std::cout << "O Wins";
	}
	else 
	{
		std::cout << "Tie";
	}

	for (int i = 0; i < size; i++)
		delete[] mainBoard[i];
	delete[] mainBoard;

	
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	std::cout << "Runtime: " << duration.count() << " milliseconds";
	

	return 0;
	
}


bool checkIfOWins(char* board[size], int size)
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

bool checkIfXWins(char* board[size], int size)
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

void printBoard(char* board[size]) 
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

Move findBestMove(char* board[size]) {
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
		
	}
	return bestMove;
}

int miniMax(char* board[size], int depth, bool isMaximizing) {
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

void initBoard(char* board[size], int size) 
{
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {

			// Assign values to the
			// memory blocks created
			board[i][j] = '_';
		}
	}
}

bool isMovesLeft(char* board[size], int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == '_') {
				return false;
			}
		}
	}
	return true;
}