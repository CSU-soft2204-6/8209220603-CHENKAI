#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char c;
	cout << "����������������ʽ : " << endl;
	cin >> a >> c >> b ;
	switch (c)
	{
	case '+': cout << a << " + " << b << " = " << a + b << endl; break;
	case '-': cout << a << " - " << b << " = " << a - b << endl; break;
	case '*': cout << a << " * " << b << " = " << a * b << endl; break;
	case '%': cout << a << " % " << b << " = " << a % b << endl; break;
	case '/': {
		if (b == 0)
			cout << "��������Ϊ 0 " << endl;
		else
			cout << a << " / " << b << " = " << a / b << endl; break; }
	default: cout << "������һ����ȷ����ʽ" << endl; break;
	}
	system("pause");
	return 0;
}