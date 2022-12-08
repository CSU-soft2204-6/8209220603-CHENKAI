#include <iostream>
using namespace std;

int main()
{
	float a, b, c, temp;
	cout << "请输入三角形三边长a b c: " << endl;
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
		cout << "三角形周长是: " << a + b + c << endl;
		if (a == b || b == c || c == a)
		{
			cout << "此三角形是等腰三角形" << endl;
		}
		else
		{
			cout << "此三角形不是等腰三角形" << endl;
		}
	}
	else
	{
		cout << "无法构成三角形" << endl;
	}
	system("pause");
	return 0;
}