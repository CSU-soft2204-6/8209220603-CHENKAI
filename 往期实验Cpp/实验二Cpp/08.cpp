#include <iostream>
using namespace std;

int main()
{
	double a, x1, x2, j = 1;

	cout << "请输入a的值: " << endl;
	cin >> a;
	x1 = a;

	if (a == 0)
	{
		cout << "a的平方根为: 0"<< endl;
		return 0;
	}
	else if (a < 0)
	{
		cout << "a在实数范围内没有平方根" << endl;
		return 0;
	}

	while (fabs(j) >= 1e-5)
	{
		x2 = (x1 + (a / x1)) * 1 / 2;
		j = x2 - x1;
		x1 = x2;
	}

	cout << "a的平方根为: " << x2 << endl;
	system("pause");
	return 0;
}
