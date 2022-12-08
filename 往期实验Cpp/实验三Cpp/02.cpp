#include<iostream>
using namespace std;

bool is_prime(int num)
{
	for (int d = 2; d <= num / 2; d++)
	{
		if (num % d == 0)
		{
			return false;
		}
	}
	return true;
}

void display(int total,int line)
{
	int count = 0;
	int num = 2;
	while (count < total)
	{
		if (is_prime(num))
		{
			count++;
			if (count % line == 0)
			{
				cout << num << '\t' << '\n';
			}
			else
			{
				cout << num << '\t';
			}
		}
		num++;
	}
}

void main()
{
	display(200, 10);
}