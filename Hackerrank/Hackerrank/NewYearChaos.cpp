#include "stdafx.h"
#include "NewYearChaos.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int minimumBribesFaster(vector<int> & finalPosition)
{
	int n = finalPosition.size();
	int swapCount = 0;
	for (size_t i = 0; i < n - 1; i++)
	{
		int singleSwapCount = 0;
		for (size_t j = i + 1; j < n; j++)
		{
			if (finalPosition[i] > finalPosition[j])
			{
				++swapCount;
				++singleSwapCount;
			}
		}
		if (singleSwapCount > 2)
		{
			cout << "Too chaotic\n";
			return;
		}
	}

	cout << swapCount << "\n";
}

int minimumBribes(vector<int> & finalPosition)
{
	int swapCount = 0;
	int arrSize = finalPosition.size();
	for (int i = 0; i < arrSize; i++)
	{
		int indexNextMax = distance(finalPosition.begin(), max_element(finalPosition.begin(), finalPosition.end() - i));
		if (indexNextMax < arrSize - (i + 1) - 2)
		{
			return -1;
		}
		if (indexNextMax == arrSize - (i + 1))
		{
			continue;
		}

		if (indexNextMax == arrSize - (i + 1) - 2)
		{
			swap(finalPosition[indexNextMax], finalPosition[arrSize - (i + 1) - 1]);
			swap(finalPosition[arrSize - (i + 1) - 1], finalPosition[arrSize - (i + 1)]);
			swapCount += 2;
		}
		else if (indexNextMax == arrSize - (i + 1) - 1)
		{
			swap(finalPosition[indexNextMax], finalPosition[arrSize - (i + 1)]);
			++swapCount;
		}
	}

	if (swapCount != -1)
	{
		cout << swapCount;
	}
	else
	{
		cout << "Too chaotic";
	}

	return swapCount;
}

NewYearChaos::NewYearChaos()
{
	int t;
	cin >> t;
	
	while (t--)
	{
		int n;
		cin >> n;

		vector<int> finalPosition(n);
		for (size_t i = 0; i < n; ++i)
		{
			cin >> finalPosition[i];
		}

		int minBribes = minimumBribesFaster(finalPosition);
		
	}
}


NewYearChaos::~NewYearChaos()
{
}
