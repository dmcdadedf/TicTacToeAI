#include <iostream>
#include <chrono>

using namespace std::chrono;

const int size = 120;

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
	int movesMade = 0;
	char userInput = '_';
	while (userInput != 'X' && userInput != 'x' && userInput != 'O' && userInput != 'o')
	{
		std::cout << "Who Goes First? X or O \n";
		std::cin >> userInput;
		if (userInput == 'X' || userInput == 'x') 
		{
			xTurn = true;
		}
		else if (userInput == 'O' || userInput == 'o')
		{
			xTurn = false;
		}
		else
		{
			std::cout << "Please enter a valid input: X or O\n";
		}
		
	}
	auto start = high_resolution_clock::now();

	char** mainBoard = new char* [size];

	for (int i = 0; i < size; i++) 
	{
		mainBoard[i] = new char[size];
	}
	
	initBoard(mainBoard, size);

	Move xMove , oMove;

	while(!xWins && !oWins && !tie)
	{
		if (xTurn)
		{
			xMove = findBestMove(mainBoard);
			movesMade++;
			std::cout << movesMade << ". Xs Move:" << xMove.col << " " << xMove.row << "\n";
			mainBoard[xMove.row][xMove.col] = 'x';
			xWins = checkIfXWins(mainBoard, size);
			xTurn = false;
		}
		else
		{
			oMove = findBestMove(mainBoard);
			movesMade++;
			std::cout << movesMade << ". Os Move:" << oMove.col << " " << oMove.row << "\n";
			mainBoard[oMove.row][oMove.col] = 'o';
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
	printBoard(mainBoard);

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
	numOfNodesExplored++;
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
					board[i][j] = '_';
				}
				
			}

		}
		return bestVal;
	}
	else {
		int bestVal = 1000;
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < size; j++) {
				if (board[i][j] == '_') 
				{
					board[i][j] = 'O';
					bestVal = std::min(bestVal, miniMax(board, depth + 1, true));
					board[i][j] = '_';
				}
				
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