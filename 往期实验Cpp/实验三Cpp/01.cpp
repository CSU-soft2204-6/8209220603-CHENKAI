#include<iostream>
using namespace std;

int divisor(int &a,int &b)
{
	if (b > a)           //保证 a大 b小
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
	cout << "请输入两个数字: "<<endl;
	cin >> a >> b;
	cout << a << " 和 " << b << "的最大公约数是" << divisor(a, b) << endl
		 << "最小公倍数是" << multiple(a, b) << endl;
}