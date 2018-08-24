#include "stdafx.h"
#include "connectedCell.h"
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

void addNeighbour(vector<pair<int, int>> & neighbours, int x, int y, vector<vector<int>> & matrix)
{
	int rows = matrix.size();
	int columns = matrix[0].size();

	if (x < 0 || y < 0 || x >= rows || y >= columns)
	{
		return;
	}
	
	if (matrix[x][y] == 1)
	{
		neighbours.push_back(pair<int, int>(x, y));
	}
}

vector<pair<int, int>> getNeighbours(pair<int, int> & cell, vector<vector<int>> & matrix)
{
	vector<pair<int, int>> neighbours;	

	addNeighbour(neighbours, cell.first - 1, cell.second - 1, matrix);
	addNeighbour(neighbours, cell.first - 1, cell.second, matrix);
	addNeighbour(neighbours, cell.first - 1, cell.second + 1, matrix);
	addNeighbour(neighbours, cell.first, cell.second - 1, matrix);
	addNeighbour(neighbours, cell.first, cell.second + 1, matrix);
	addNeighbour(neighbours, cell.first + 1, cell.second - 1, matrix);
	addNeighbour(neighbours, cell.first + 1, cell.second, matrix);
	addNeighbour(neighbours, cell.first + 1, cell.second + 1, matrix);

	return neighbours;
}

void formRegion(int i, int j, vector<vector<int>> & matrix, int regionId)
{
	int regionMemberCount = 0;
	queue<pair<int, int>> pendingNeighbours;
	pendingNeighbours.push(pair<int, int>(i, j));

	while (!pendingNeighbours.empty())
	{
		auto currentCell = pendingNeighbours.front();
		pendingNeighbours.pop();
		matrix[currentCell.first][currentCell.second] = regionId;
		//++regionMemberCount;
		auto neighbours = getNeighbours(currentCell, matrix);

		for (auto & neighbour : neighbours)
		{
			pendingNeighbours.push(neighbour);
		}
	}
	//return regionMemberCount;
}

int connectedCell1(vector<vector<int>> matrix) 
{
	unordered_map<int, int> regionCount;
	int regionId = 2;
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		for (size_t j = 0; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] == 1)
			{
				formRegion(i, j, matrix, regionId);				
				regionCount[regionId] = 0;
				++regionId;
			}
		}
	}
	
	int maxCount = 0;
	for (size_t i = 0; i < matrix.size(); ++i)
	{
		for (size_t j = 0; j < matrix[i].size(); ++j)
		{
			if (matrix[i][j] != 0)
			{
				++regionCount[matrix[i][j]];
			}
		}
	}
	
	if (regionCount.empty())
	{
		return 0;
	}

	auto itrMax = max_element(regionCount.begin(), 
		regionCount.end(),
		[](const pair<int, int>& p1, const pair<int, int>& p2) {
		return p1.second < p2.second; });
	return itrMax->second;
}

connectedCell::connectedCell()
{
	int n, m;
	cin >> n >> m;
	vector<vector<int>> matrix(n, vector<int>(m));

	for (size_t i = 0; i < n; ++i)
	{
		for (size_t j = 0; j < m; ++j)
		{
			cin >> matrix[i][j];
		}
	}

	cout << "\n\n" << connectedCell1(matrix) << "\n\n";
}


connectedCell::~connectedCell()
{
}
