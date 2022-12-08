#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	float f, c;
	cout << "请输入华氏温度:" << endl;
	cin >> f;
	c = (f - 32) / 1.8;
	cout << "华氏温度: " << f << "℉" << '\t' 
		 << "摄氏温度: " << fixed << setprecision(2) << c << "℃" << endl;
	system("pause");
	return 0;
}