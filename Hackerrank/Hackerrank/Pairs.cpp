#include "stdafx.h"
#include "Pairs.h"
#include <unordered_map>
#include <iostream>

using namespace std;

int pairs(int k, vector<int> arr)
{
	unordered_map<int, int> numbers;
	int pairCount = 0;

	for (auto number : arr)
	{
		numbers[number] = 0;
	}

	for (auto number : arr)
	{
		if (numbers.find(number + k) != numbers.end())
		{
			++pairCount;
		}
		if (numbers.find(number - k) != numbers.end())
		{
			++pairCount;
		}
	}

	return pairCount / 2;
}

Pairs::Pairs()
{
	int n, k;
	cin >> n >> k;

	vector<int> arr(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	cout << "\n\n" << pairs(k, arr) << "\n\n";
}


Pairs::~Pairs()
{
}
