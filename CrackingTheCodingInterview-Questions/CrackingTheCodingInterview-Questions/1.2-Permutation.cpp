#include <string>
#include <iostream>
#include <vector>

using namespace std;


bool isPermutation(const string& str1, const string& str2)
{
	// first check to see if the two strings are the same length
	if (str1.length() != str2.length())
	{
		return false;
	}

	// check to see if first string is the second string in reverse
	for (int i = 0; i < str1.length(); i++)
	{
		if (str1[i] != str2[str2.length() - (i + 1)])
		{
			return false;
		}
	}
	return true;
}


int main()
{
	string word1 = "dog";
	string word2 = "god";
	string word3 = "kayak";

	cout << "Checking if " << word1 << " and " << word2 << " are a permutation: " << boolalpha << isPermutation(word1, word2) << endl;
	cout << "Checking if " << word1 << " and " << word3 << " are a permutation: " << boolalpha << isPermutation(word1, word3) << endl;
	cout << "Checking if " << word2 << " and " << word3 << " are a permutation: " << boolalpha << isPermutation(word2, word3) << endl;
	cout << "Checking if " << word3 << " and " << word3 << " are a permutation: " << boolalpha << isPermutation(word3, word3) << endl;

	return 0;
}