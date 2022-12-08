#include<iostream>
using namespace std;
const double Pi = 3.14159;

int main()
{
	double r;
	double h;
	double v;
	cout << "请输入圆锥的底面半径 r = ";
	cin >> r;
	cout << "请输入圆锥的高 h = ";
	cin >> h;
	v = Pi * r * r * h / 3;
	cout << "圆锥的体积 v = " << v << endl;
	return 0;
}