#include "stdafx.h"
#include "shortPalindromeClass.h"
#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

int findIndexOfCharGreaterThan(char ch, int pos, unordered_map<char, vector<int>> & charPositions)
{
	auto indices = charPositions[ch];

	for (size_t i = 0; i < indices.size(); ++i)
	{
		if (indices[i] > pos)
		{
			return indices[i];
		}
	}
	return -1;
}

int shortPalindrome(string s) 
{
	unordered_map<char, vector<int>> charPositions;
	int palindromeCount = 0;
	for (size_t i = 0; i < s.size(); ++i)
	{
		if (charPositions.find(s[i]) == charPositions.end())
		{
			vector<int> indices(1, i);
			charPositions[s[i]] = indices;
		}
		else
		{
			charPositions[s[i]].push_back(i);
		}
	}

	for (size_t i = 0; i < s.size(); i++)
	{
		for (size_t j = i + 1; j < s.size(); j++)
		{
			int nextJ = findIndexOfCharGreaterThan(s[j], j, charPositions);
			int nextI = findIndexOfCharGreaterThan(s[i], nextJ, charPositions);
			while (nextJ != -1 && nextI != -1)
			{
				++palindromeCount;
				nextI = findIndexOfCharGreaterThan(s[i], nextI, charPositions);
				while (nextI != -1)
				{
					++palindromeCount;
					nextI = findIndexOfCharGreaterThan(s[i], nextI, charPositions);
				}
				nextJ = findIndexOfCharGreaterThan(s[j], nextJ, charPositions);
				nextI = findIndexOfCharGreaterThan(s[i], nextJ, charPositions);

			}
		}
	}
	return palindromeCount;
}

shortPalindromeClass::shortPalindromeClass()
{
	string input;
	cin >> input;
	cout << "\n\n" << shortPalindrome(input) << "\n\n";
}


shortPalindromeClass::~shortPalindromeClass()
{
}
