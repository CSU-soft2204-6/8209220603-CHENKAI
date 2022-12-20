#include<iostream>
using namespace std;

void count(const char s[], int counts[])
{
	for (int i = 0; i < 26; i++)
	{
		counts[i] = 0;
	}
	for (int i = 0; i < 80; i++)
	{
		if ((s[i] - 'a') >= 0)
		{
			counts[s[i] - 'a']++;
		}
		if ((s[i] - 'A') <= 25)
		{
			counts[s[i] - 'A']++;
		}
	}
}

void display(int counts[])
{
	for (int i = 0; i < 26; i++)
	{
		if (counts[i] != 0)
		{
			cout << char(i + 'a') << " : " << counts[i] << " times" << endl;
		}
	}
}

void main() 
{
	int counts[26];
	char s[80];
	cout << "Enter a string : ";
	cin.getline(s, 80);

	count(s, counts);

	display(counts);
}
