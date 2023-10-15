//Project: Tic-Tac-Toe MiniMax AI     Date: 10/01/23
//Authors: David McDade, Jared Rivard

#include <iostream>
#include <chrono>

using namespace std::chrono;

const int size = 5;

int numOfNodesExplored = 0;

bool checkIfXWins(char* board[size], int size);
bool checkIfOWins(char* board[size], int size);
void printBoard(char* board[size]);
void initBoard(char* board[size], int size);

struct Move {
	int row = -100;
	int col = -100;
};

Move findBestMove(char* board[size]);
int miniMax(char* board[size], int depth, bool isMaximizing);
bool isMovesLeft(char* board[size], int size);

int main()
{
	bool xWins = false;
	bool oWins = false;
	bool tie = false;
	bool xTurn = true;
	bool validMove = false;
	int movesMade = 0;
	char userInput = ' ';

	auto start = high_resolution_clock::now();

	char** mainBoard = new char* [size];

	for (int i = 0; i < size; i++) 
	{
		mainBoard[i] = new char[size];
	}
	
	initBoard(mainBoard, size);

	Move xMove , oMove;

	printBoard(mainBoard);

	while(!xWins && !oWins && !tie)
	{
		if (xTurn)
		{
			validMove = false;

			while (!validMove) {

				xMove.col = -1;
				xMove.row = -1;
				while (xMove.row < 0 || xMove.row > size - 1) {
					std::cout << "Choose a row to play in: \n";
					std::cin >> xMove.row;
					if (xMove.row < 0 || xMove.row > size - 1) {
						std::cout << "Please enter a valid number. \n";
					}
				}
				while (xMove.col < 0 || xMove.col > size - 1) {
					std::cout << "Choose a column to play in: \n";
					std::cin >> xMove.col;
					if (xMove.col < 0 || xMove.col > size - 1) {
						std::cout << "Please enter a valid number. \n";
					}
				}
				if (mainBoard[xMove.col][xMove.row] == ' ') {
					validMove = true;
				}
				else {
					std::cout << "Please enter a move in an empty space. \n";
				}
			}
			movesMade++;
			mainBoard[xMove.col][xMove.row] = 'x';
			printBoard(mainBoard);
			xWins = checkIfXWins(mainBoard, size);
			xTurn = false;
		}
		else
		{
			oMove = findBestMove(mainBoard);
			movesMade++;
			mainBoard[oMove.row][oMove.col] = 'o';
			printBoard(mainBoard);
			oWins = checkIfOWins(mainBoard, size);
			xTurn = true;
		}
		if (isMovesLeft(mainBoard, size)) 
		{
			tie = true;
		}
	}
	
	if (xWins) {
		std::cout << "\n X Wins \n";
	}
	else if (oWins) {
		std::cout << "\n O Wins \n";
	}
	else 
	{
		std::cout << "\n Tie \n";
	}

	for (int i = 0; i < size; i++)
		delete[] mainBoard[i];
	delete[] mainBoard;

	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<milliseconds>(stop - start);

	std::cout << "Runtime: " << duration.count() << " milliseconds\n";
	std::cout << "Number of Nodes Explored:" << numOfNodesExplored << "\n";

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
		}
		if (numInARow == size)
		{
			return true;
		}

		numInARow = 0;
		
	}

	//Check Vertical
	
	numInARow = 0;

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (board[i][j] == 'O' || board[i][j] == 'o')
			{
				numInARow++;
			}

		}
		if (numInARow == size)
		{
			return true;
		}
		else
		{
			numInARow = 0;
		}
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
	}
	if (numInARow == size)
	{
		return true;
	}

	

	//Check Diagonal 2
	numInARow = 0;

	for (int i = 0; i < size; i++)
	{
		if (board[size - i - 1][i] == 'X' || board[size - i - 1][i] == 'x')
		{
			numInARow++;
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
		}
		if (numInARow == size)
		{
			return true;
		}
		else
		{
			numInARow = 0;
		}
	}

	//Check Vertical

	numInARow = 0;

	for (int j = 0; j < size; j++)
	{
		for (int i = 0; i < size; i++)
		{
			if (board[i][j] == 'X' || board[i][j] == 'x')
			{
				numInARow++;
			}
		}
		if (numInARow == size)
		{
			return true;
		}
		else
		{
			numInARow = 0;
		}
	}

	return false;
}

void printBoard(char* board[size]) 
{
	for (int i = 0; i < size; i++)
	{
		std::cout << "\n ";

		for (int j = 0; j < size; j++) 
		{
			std::cout << board[j][i];
			if (j != size - 1) 
			{
				std::cout << " | ";
			}
		}
		std::cout << "\n";
		for (int j = 0; j < size; j++)
		{
			
			if (i != size - 1)
			{
				std::cout << "----";
			}
		}
	}
	std::cout << "\n";
}

Move findBestMove(char* board[size]) {
	int bestVal = -100;
	Move bestMove;
	bestMove.col = -100;
	bestMove.row = -100;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == ' ') {
				board[i][j] = 'x';
				int moveVal = miniMax(board, 0, false);
				board[i][j] = ' ';
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
	numOfNodesExplored++;
	int score;
	if (checkIfXWins(board, size))
	{
		return 10;
	}
	if (checkIfOWins(board, size)) 
	{
		return -10;
	}
	if (!isMovesLeft(board, size)) 
	{
		return 0;
	}
	if (isMaximizing) 
	{
		int bestVal = -1000;
		for (int i = 0; i < size; i++) 
		{
			for (int j = 0; j < size; j++) 
			{
				if (board[i][j] == ' ') 
				{
					board[i][j] = 'X';
					bestVal = std::max(bestVal, miniMax(board, depth + 1, false));
					board[i][j] = ' ';
				}
				
			}

		}
		return bestVal;
	}
	else 
	{
		int bestVal = 1000;
		for (int i = 0; i < size; i++) 
		{
			for (int j = 0; j < size; j++) 
			{
				if (board[i][j] == ' ') 
				{
					board[i][j] = 'O';
					bestVal = std::min(bestVal, miniMax(board, depth + 1, true));
					board[i][j] = ' ';
				}
				
			}

		}
		return bestVal;
	}
}

void initBoard(char* board[size], int size) 
{
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			board[i][j] = ' ';
		}
	}
}

bool isMovesLeft(char* board[size], int size) {
	for (int i = 0; i < size; i++) 
	{
		for (int j = 0; j < size; j++) 
		{
			if (board[i][j] == ' ') 
			{
				return false;
			}
		}
	}
	return true;
}