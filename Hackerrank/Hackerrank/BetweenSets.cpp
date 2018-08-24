#include "stdafx.h"
#include "BetweenSets.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
using namespace std;


int getTotalX(vector<int> a, vector<int> b) {
	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());

	auto newA = a;
	for (size_t i = 0; i < a.size(); ++i)
	{
		for (size_t j = 0; j < a.size(); ++j)
		{
			if (newA[j] % a[i] == 0 && (newA[j] / a[i] > 1 || (newA[j] != a[j] && newA[j] / a[i] == 1)))
			{
				newA[j] = newA[j] / a[i];
			}
		}
	}

	int lcm = newA[0];
	for (size_t i = 1; i < newA.size(); ++i)
	{
		lcm *= newA[i];
	}

	auto smallestInBItr = min_element(b.begin(), b.end());

	int totalDivisors = 0;
	int currentDivisor = lcm;
	int multiple = 1;

	while (currentDivisor <= *smallestInBItr)
	{
		bool dividesAll = true;
		for (size_t i = 0; i < b.size(); ++i)
		{
			if (b[i] % currentDivisor != 0)
			{
				dividesAll = false;
				break;
			}
		}

		if (dividesAll)
		{
			++totalDivisors;
		}
		++multiple;
		currentDivisor = lcm * multiple;
	}

	return totalDivisors;
}

BetweenSets::BetweenSets()
{
	int n, m;
	cin >> n >> m;

	vector<int> a(n);
	vector<int> b(m);

	for (size_t i = 0; i < n; ++i)
	{
		cin >> a[i];
	}

	for (size_t i = 0; i < m; ++i)
	{
		cin >> b[i];
	}

	cout << "\n" << getTotalX(a, b) << "\n\n";
}


BetweenSets::~BetweenSets()
{
}
