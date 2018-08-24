// Hackerrank.pp : Defines the entry point for the console application.
#include "stdafx.h"
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iomanip>
#include "NewYearChaos.h"

using namespace std;

// Complete the entryTime function below.
int getRequiredTimeToMove(char from, char to, const string & keypad)
{
	if (from == to)
	{
		return 0;
	}

	int fromPos = keypad.find(from);
	int toPos = keypad.find(to);

	int fromRow = fromPos / 3;
	int fromColumn = fromPos % 3;
	int toRow = toPos / 3;
	int toColumn = toPos % 3;

	if (fromRow == toRow)
	{
		return abs(fromColumn - toColumn);
	}
	else if (fromColumn == toColumn)
	{
		return abs(fromRow - toRow);
	}
	else
	{
		return abs(fromColumn - toColumn) > abs(fromRow - toRow) ? abs(fromColumn - toColumn) : abs(fromRow - toRow);
	}
}

int entryTime(string s, string keypad) {
	int timeRequired = 0;
	char currentPos = s[0];
	for (int i = 1; i < s.size(); ++i)
	{
		timeRequired += getRequiredTimeToMove(currentPos, s[i], keypad);
		currentPos = s[i];
	}
	return timeRequired;
}

int maxTickets(vector<int> tickets) {
	sort(tickets.begin(), tickets.end());
	int currentSetCount = 1;
	int maxM = 0;

	for (size_t i = 1; i < tickets.size(); ++i)
	{
		if (tickets[i] - tickets[i-1] == 0 || tickets[i] - tickets[i - 1] == 1)
		{
			++currentSetCount;
		}
		else
		{
			if (currentSetCount > maxM)
			{
				maxM = currentSetCount;
			}
			currentSetCount = 1;
		}
	}

	if (currentSetCount > maxM)
	{
		maxM = currentSetCount;
	}
	return maxM;
}

void finalPrice(vector<int> prices) {
	vector<int> nonDiscounted;
	int totalPrice = 0;

	for (size_t i = 0; i < prices.size(); ++i)
	{
		int nextSmallOrEqual = -1;
		for (size_t j = i + 1; j < prices.size(); ++j)
		{
			if (prices[i] >= prices[j])
			{
				nextSmallOrEqual = j;
				break;
			}
		}

		if (nextSmallOrEqual == -1)
		{
			nonDiscounted.push_back(i);
			totalPrice += prices[i];
		}
		else
		{
			for (int k = i; k < nextSmallOrEqual; ++k)
			{
				totalPrice += prices[k] - prices[nextSmallOrEqual];
			}
			i = nextSmallOrEqual - 1;
		}
	}
	
	cout << totalPrice << "\n";

	for (auto index : nonDiscounted)
	{
		cout << index << " ";
	}
}

void reduceFraction(int & numerator, int & denominator)
{
	int smaller = numerator < denominator ? numerator : denominator;
	for (int i = 2; i <= smaller; ++i)
	{
		if (numerator % i == 0 && denominator % i == 0)
		{
			numerator /= i;
			denominator /= i;
			--i;
		}
	}
}

int main()
{

	while (true)
	{
		NewYearChaos n;
	}
    return 0;
}