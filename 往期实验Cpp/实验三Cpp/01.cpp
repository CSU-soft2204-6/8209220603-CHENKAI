#include<iostream>
using namespace std;

int divisor(int &a,int &b)
{
	if (b > a)           //��֤ a�� bС
	{
		int temp = a;
		a = b;
		b = temp;
	}
	while (a % b)
	{
		int c = a % b;
		a = b;
		b = c;
	}
	return b;
}
int multiple(int &a, int &b)
{
	int m = a * b;
	int c = m / divisor(a, b);
	return c;
}

void main()
{
	int a, b;
	cout << "��������������: "<<endl;
	cin >> a >> b;
	cout << a << " �� " << b << "�����Լ����" << divisor(a, b) << endl
		 << "��С��������" << multiple(a, b) << endl;
}