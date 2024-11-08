#include <string>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool IsUnique(const string& str)
{
	// is string longer than alphabet
	if (str.length() > 128)
	{
		return false;
	}

	// vector to hold unique values for character set
	vector<bool> charSet(128);
	for (int i = 0; i < str.length(); i++)
	{
		int val = str[i];
		if (charSet[val])	// if character is already contained within the set
		{
			return false;
		}
		charSet[val] = true;
	}
	return true;
}

int main()
{
	vector<string> words = { "abcde", "hello", "apple", "kite", "padle" };
	for (auto word : words)
	{
		cout << word << string(": ") << boolalpha << IsUnique(word) << endl;
	}

	return 0;
}