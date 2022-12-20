#include<iostream>
using namespace std;

void merge(int* a, int num1, int* b, int num2, int* c)
{
	int temp;
	for (int i = 0; i < num1; i++)
	{
		c[i] = a[i];
	}
	for (int i = 0; i < num2; i++)
	{
		c[num1 + i] = b[i];
	}
	for (int i = 0; i < (num1+num2) - 1; i++)
	{
		for (int j = 0; j < (num1 + num2) - i - 1; j++)
		{
			if (c[j] > c[j + 1])
			{
				temp = c[j];
				c[j] = c[j + 1];
				c[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < (num1 + num2); i++)
	{
		cout << c[i] << "  ";
	}
}

void main()
{
	int num1, num2, num3;
	
	cout << "输入数组1的大小: ";
	cin >> num1;
	cout << "输入数组1 : ";
	int*arr1 = new int [num1];
	for (int i = 0; i < num1; i++)
	{
		cin >> arr1[i];
	}
	
	cout << "输入数组2的大小: ";
	cin >> num2;
	cout << "输入数组2 : ";
	int* arr2 = new int[num2];
	for (int i = 0; i < num2; i++)
	{
		cin >> arr2[i];
	}

	num3 = num1 + num2;
	int* arr3 = new int[num3];
	
	merge(arr1, num1, arr2, num2, arr3);

	delete[] arr1,arr2,arr3;
}