#include <iostream>
using namespace std;

const int listsize = 10;

void swap(double& a, double& b)
{
	double temp;
	temp = a;
	a = b;
	b = temp;
}

void bubbleSort(double list[10])
{
	double temp;
	bool changed = true;
	do
	{
		changed = false;
		for (int j = 0; j < listsize - 1; j++)
		{
			if (list[j] > list[j + 1])
			{
				swap(list[j], list[j + 1]);
				changed = true;
			}
		}
	} while (changed );
}
void main()
{
	double list[listsize];
	for (int i = 0; i < listsize; i++)
	{
		cin >> list[i];
	}
	
	bubbleSort(list);

	for (int i = 0; i < listsize; i++)
		cout << list[i] << " ";
}