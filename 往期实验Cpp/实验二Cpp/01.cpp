#include <iostream>
using namespace std;

int main()
{
	char a;
	cout << "������һ���ַ�:" << endl;
	cin >> a;
	if (a >= 'a' && a <= 'z')
	{
		a -= 32;
		cout << a << endl;
	}
	else if (a >= 'A' && a <= 'Z')
	{
		a += 1;
		cout << int(a) << endl;
	}
	system("pause");
	return 0;
}