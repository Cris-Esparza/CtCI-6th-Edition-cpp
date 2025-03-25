#include <iostream>
#include <cstring>
using namespace std;

// write a method to replace all the spaces in a string with "%20"

void replaceSpaces(char *str, int length)
{
	// find number of spaces in string
	int numOfSpaces = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == ' ')
		{
			numOfSpaces++;
		}
	}

	// iterate through parsed string backwards
	int extendedLength = length + 2 * numOfSpaces;
	int i = extendedLength - 1;
	for (int j = length - 1; j >= 0; j--)
	{
		// if char at index isnt a space, copy it into the new string
		if (str[j] != ' ')
		{
			str[i--] = str[j];
		}
		// if its a space, create two additional spaces to fit the extra characters
		else 
		{
			str[i--] = '0';
			str[i--] = '2';
			str[i--] = '%';
		}
	}
}


int main()
{
	char str[] = "Dallas has a new toy    ";
	cout << "Actual string : " << str << endl;
	replaceSpaces(str, 20);
	cout << "URLified string: " << str << endl;
	
	return 0;
}