#include<iostream>
using namespace std;
const double Pi = 3.14159;

int main()
{
	double r;
	double h;
	double v;
	cout << "������Բ׶�ĵ���뾶 r = ";
	cin >> r;
	cout << "������Բ׶�ĸ� h = ";
	cin >> h;
	v = Pi * r * r * h / 3;
	cout << "Բ׶����� v = " << v << endl;
	return 0;
}