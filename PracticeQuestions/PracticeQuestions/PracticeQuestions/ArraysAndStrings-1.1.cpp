#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <algorithm>
using namespace std;

// Is Unique - implement an algorithm to determine if a string has all unique characters. What if you cannot use additonal data structures?

// boolean to test for unique characters
bool isUnique(const string &string)
{
	// if the string is longer than the amount of unique characters available
	if (string.length() > 128)
	{
		return false;
	}
	vector<bool> char_set(128);	// vector(array) that holds set of unique characters
	for (int i = 0; i < string.length(); i++)
	{
		int value = string[i];
		if (char_set[value])	// if the character already exist in the string
		{
			return false;
		}
		char_set[value] = true;
	}
	return true;
}

// using bit vectors
bool isUniqueBitVector(const string& str)
{
	bitset<256> bits(0);
	for (int i = 0; i < str.length(); i++)
	{
		int val = str[i];
		if (bits.test(val) > 0)
		{
			return false;
		}
		bits.set(val);
	}
	return true;
}

// using no data structure
bool isUniqueNoDataStructure(string str)
{
	sort(str.begin(), str.end());	

	bool noRepeat = true;
	for (int i = 0; i < str.size() - 1; i++)
	{
		if (str[i] == str[i + 1])
		{
			noRepeat = false;
			break;
		}
	}

	return noRepeat;
}


int main()
{
	vector<string> words = { "abcde", "Dallas", "Ripple", "Jake", "Lyle" };

	// basic unique char check
	for (string word : words)
	{
		cout << word << ": " << boolalpha << isUnique(word) << endl;
	}

	cout << endl;

	// using bit vector
	for (string word : words)
	{
		cout << "Using bit vector ";
		cout << word << ": " << boolalpha << isUniqueBitVector(word) << endl;
	}

	cout << endl;

	// using no repeat
	for (string word : words)
	{
		cout << "Using no data structure ";
		cout << word << ": " << boolalpha << isUniqueNoDataStructure(word) << endl;
	}

	return 0;
}