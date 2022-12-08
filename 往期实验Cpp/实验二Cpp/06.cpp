#include <iostream>
using namespace std;

void main()
{
	int a, b, c, temp;
	cout << "请输入两个整数：";
	cin >> a >> b;
	c = a * b;
	if (b > a)  //将a,b中的大值令为a 小值为b
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (a % b) //辗转相除法求最大公约数
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	c = c / b;
	cout << "最大公约数是：" << b << endl;
	cout << "最小公倍数是：" << c << endl;
  system("pause");
}