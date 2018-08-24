#include "stdafx.h"
#include "Array2D.h"
#include <vector>

using namespace std;

int calcHourGlassSum(vector<vector<int>> & arr, int row, int column)
{
	int sum = 0;
	sum += arr[row][column];
	sum += arr[row][column + 1];
	sum += arr[row][column + 2];
	sum += arr[row + 1][column + 1];
	sum += arr[row + 2][column];
	sum += arr[row + 2][column + 1];
	sum += arr[row + 2][column + 2];
	return sum;
}

int hourglassSum(vector<vector<int>> arr) 
{
	int maxHourGlass = 0;
	for (size_t i = 0; i < arr.size(); i++)
	{
		for (size_t j = 0; j < arr[i].size() - 2; j++)
		{
			int sum = calcHourGlassSum(arr, i, j);
			if (maxHourGlass < sum)
			{
				maxHourGlass = sum;
			}
		}
	}
	return maxHourGlass;
}

Array2D::Array2D()
{

}


Array2D::~Array2D()
{
}
