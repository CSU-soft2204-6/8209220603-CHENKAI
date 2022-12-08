#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char c;
	cout << "请输入四则运算算式 : " << endl;
	cin >> a >> c >> b ;
	switch (c)
	{
	case '+': cout << a << " + " << b << " = " << a + b << endl; break;
	case '-': cout << a << " - " << b << " = " << a - b << endl; break;
	case '*': cout << a << " * " << b << " = " << a * b << endl; break;
	case '%': cout << a << " % " << b << " = " << a % b << endl; break;
	case '/': {
		if (b == 0)
			cout << "除数不得为 0 " << endl;
		else
			cout << a << " / " << b << " = " << a / b << endl; break; }
	default: cout << "请输入一个正确的算式" << endl; break;
	}
	system("pause");
	return 0;
}