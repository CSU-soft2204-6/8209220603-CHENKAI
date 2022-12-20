#include <iostream>
using namespace std;

const int num = 100;
void main()
{
	bool box[num];
	for (int i = 0; i < num; i++)
	{
		box[i] = false;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = i; j < num; j += (i + 1))
		{
			if (box[j] == false)
			{
				box[j] = true;
			}
			else if(box[j] == true)
			{
				box[j] = false;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (box[i])
		{
			cout << i + 1 << " ";
		}
	}
}