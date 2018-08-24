#include "stdafx.h"
#include "KnightMoves.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> Square;

bool isValid(const Square & leftTop1, int n)
{
	return !(leftTop1.first < 0 || leftTop1.first >= n ||
		leftTop1.second < 0 || leftTop1.second >= n);
}

void addPossibleMove(const int x, const int y, vector<Square> & possibleMoves, const int n)
{
	Square neighbour;
	neighbour.first = x;
	neighbour.second = y;

	if (isValid(neighbour, n))
	{
		possibleMoves.push_back(neighbour);
	}
}

vector<Square> getpossibleMoves(Square & currentSquare, int n, int a, int b)
{
	vector<Square> possibleMoves;

	int x = currentSquare.first;
	int y = currentSquare.second;

	if (a != b)
	{
		addPossibleMove(x - a, y - b, possibleMoves, n);
		addPossibleMove(x - b, y - a, possibleMoves, n);
		addPossibleMove(x - a, y + b, possibleMoves, n);
		addPossibleMove(x - b, y + a, possibleMoves, n);
		addPossibleMove(x + a, y - b, possibleMoves, n);
		addPossibleMove(x + b, y - a, possibleMoves, n);
		addPossibleMove(x + a, y + b, possibleMoves, n);
		addPossibleMove(x + b, y + a, possibleMoves, n);
	}
	else
	{
		addPossibleMove(x - a, y - b, possibleMoves, n);
		addPossibleMove(x - a, y + b, possibleMoves, n);
		addPossibleMove(x + a, y - b, possibleMoves, n);
		addPossibleMove(x + a, y + b, possibleMoves, n);
	}	

	return possibleMoves;
}

int findMinMoves(int a, int b, int n)
{
	vector<vector<int>> movesFromStart(n, vector<int>(n, INT_MAX));
	movesFromStart[0][0] = 0;
	Square initSquare = make_pair<int, int>(0, 0);
	queue<Square> pendingSquares;
	pendingSquares.push(initSquare);

	while (!pendingSquares.empty())
	{
		auto currentSquare = pendingSquares.front();
		pendingSquares.pop();

		auto possibleMoves = getpossibleMoves(currentSquare, n, a, b);
		for (auto & nextMove : possibleMoves)
		{
			if (movesFromStart[currentSquare.first][currentSquare.second] + 1 < 
				movesFromStart[nextMove.first][nextMove.second])
			{
				movesFromStart[nextMove.first][nextMove.second] = movesFromStart[currentSquare.first][currentSquare.second] + 1;
				pendingSquares.push(nextMove);
			}
		}
	}
	
	return movesFromStart[n - 1][n - 1] == INT_MAX ? -1 : movesFromStart[n - 1][n - 1];
}

vector<vector<int>> knightlOnAChessboard(int n) 
{
	vector<vector<int>> minMoves(n - 1, vector<int> (n - 1, INT_MAX));

	for (size_t i = 0; i < n - 1; ++i)
	{
		for (size_t j = 0; j < n - 1; j++)
		{
			if (minMoves[i][j] == INT_MAX)
			{
				minMoves[i][j] = findMinMoves(i + 1, j + 1, n);
				minMoves[j][i] = minMoves[i][j];
			}
		}
	}
	return minMoves;
}

KnightMoves::KnightMoves()
{
	int n;
	cin >> n;
	auto output = knightlOnAChessboard(n);
	cout << "\n\n";
	for (auto row : output)
	{
		for (auto cell : row)
		{
			cout << cell << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

KnightMoves::~KnightMoves()
{
}