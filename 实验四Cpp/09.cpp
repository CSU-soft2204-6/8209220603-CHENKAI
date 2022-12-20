#include<iostream>
using namespace std;

void Sort(int*arr ,int num)
{
	int temp;
	for (int i = 0; i < num - 1; i++)
	{
		for (int j = 0; j < num - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

void main()
{
	int num;
	cout << "请输入数组大小: " << endl;
	cin >> num;
	int* arr = new int[num];
	cout << "请输入数组: " << endl;
	for (int i = 0; i < num; i++)
	{
		cin >> *(arr + i);
	}

	Sort(arr, num);

	for (int i = 0; i < num; i++)
	{
		cout << *(arr + i) << " ";
	}
}