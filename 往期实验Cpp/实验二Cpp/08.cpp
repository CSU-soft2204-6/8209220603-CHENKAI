#include <iostream>
using namespace std;

int main()
{
	double a, x1, x2, j = 1;

	cout << "������a��ֵ: " << endl;
	cin >> a;
	x1 = a;

	if (a == 0)
	{
		cout << "a��ƽ����Ϊ: 0"<< endl;
		return 0;
	}
	else if (a < 0)
	{
		cout << "a��ʵ����Χ��û��ƽ����" << endl;
		return 0;
	}

	while (fabs(j) >= 1e-5)
	{
		x2 = (x1 + (a / x1)) * 1 / 2;
		j = x2 - x1;
		x1 = x2;
	}

	cout << "a��ƽ����Ϊ: " << x2 << endl;
	system("pause");
	return 0;
}
