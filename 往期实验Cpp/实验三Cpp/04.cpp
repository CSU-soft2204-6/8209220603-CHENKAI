#include<iostream>
#include"Mytriangle.h"
using namespace std;

bool is_valid(double side1, double side2, double side3)
{
	if (side1 + side2 > side3 && side1 + side3 > side2 && side2 + side3 > side1)
	{
		return true;
	}
	return false;
}
double double_area(double side1, double side2, double side3)
{
	double s, area;
	s = (side1 + side2 + side3) / 2;
	area = sqrt(s*(s - side1)*(s - side2)*(s - side3));
	return area;
}

void main()
{
	double a, b, c;
	cout << "请输入三角形的三边长: " << endl;
	cin >> a >> b >> c;
	if (is_valid(a,b,c))
	{
		cout << "此三角形面积为 " << double_area(a, b, c) << endl;
	}
	else
	{
		cout << "Error" << endl;
	}
}