#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float f, c;
	cout << "�����뻪���¶�:" << endl;
	cin >> f;
	c = (f - 32) / 1.8;
	cout << "�����¶�: " << f << "�H" << '\t' 
		 << "�����¶�: " << fixed << setprecision(2) << c << "��" << endl;
	system("pause");
	return 0;
}