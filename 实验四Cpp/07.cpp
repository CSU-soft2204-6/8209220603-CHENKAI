#include<iostream>
using namespace std;

int indexOf(char* ch1, char* ch2)
{
	int num1, num2;
	num1 = strlen(ch1);
	num2 = strlen(ch2);

	int i = 0;
	int j = 0;
	while (i < num2)
	{

		if (j == (num1 - 1) && ch1[j] == ch2[i])
		{
			//×Ó´®
			return i - num1 + 1;
		}
		if (ch1[j] == ch2[i]) 
		{
			i++;
			j++;
		}
		if (ch1[j] != ch2[i])
		{
			i++;
			j = 0;
		}
	}
	return -1;
}

void main()
{
	char ch1[80], ch2[80];

	cout << "Enter the first string : ";
	cin.getline(ch1, 80);
	cout << "Enter the second string: ";
	cin.getline(ch2, 80);

	cout << "indexOf(\"" << ch1 << "\", \"" << ch2 << "\") is " << indexOf(ch1, ch2) << endl;
}
