#include <iostream>
using namespace std;

int main()
{
	float a, b, c, temp;
	cout << "���������������߳�a b c: " << endl;
	cin >> a >> b >> c;
	if (c > b)
	{
		temp = b;
		b = c;
		c = temp;
	}
	if (b > a)
	{
		temp = a;
		a = b;
		b = temp;
	}
	if (b + c > a)
	{
		cout << "�������ܳ���: " << a + b + c << endl;
		if (a == b || b == c || c == a)
		{
			cout << "���������ǵ���������" << endl;
		}
		else
		{
			cout << "�������β��ǵ���������" << endl;
		}
	}
	else
	{
		cout << "�޷�����������" << endl;
	}
	system("pause");
	return 0;
}