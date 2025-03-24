#include <iostream>
#include <string>
#include <vector>
using namespace std;

// write a method to replace all the spaces in a string with "%20"

string modifiedString(const string& str)
{
	// create string to hold new string
	vector<char> newString;

	// iterate through parsed string and look for spaces (do not count spaces at the end of the string)
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] != ' ')
		{
			// if the character is not an empty space
			newString.insert(newString.end(), str[i]);
		}
		else
		{
			// if it is a space, insert the substituted character instead
			newString.insert(newString.end(), '%20');
		}
	}

	string modifiedString(newString.begin(), newString.end());
	return modifiedString;
}


int main()
{
	string testSentence = "Dallas has a new toy";

	cout << "Mutating string: " << testSentence << endl;
	cout << modifiedString(testSentence);

	return 0;
}