#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// given two strings, write a mehtod to decide if one as a permutation of the other

// first method, check if strings are the same length and sort
bool isPermutation(string str1, string str2)
{
	// check that the strings are the same length
	if (str1.length() != str2.length())
	{
		return false;
	}

	// sort both of the strings
	sort(str1.begin(), str1.end());
	sort(str2.begin(), str2.end());

	// compare both the strings
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[i])
		{
			return false;
		}
		i++;
	}

	return true;
}

int main()
{
	string word1 = "Dog";
	string word2 = "God   ";
	string word3 = "God";
	string word4 = "goD";

	cout << "Checking if " << word1 << " and " << word2 << " are permutations: " << boolalpha << isPermutation(word1, word2) << endl;
	cout << "Checking if " << word1 << " and " << word3 << " are permutations: " << boolalpha << isPermutation(word1, word3) << endl;
	cout << "Checking if " << word1 << " and " << word4 << " are permutations: " << boolalpha << isPermutation(word1, word4) << endl;


	return 0;
}