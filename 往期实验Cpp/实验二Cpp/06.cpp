#include <iostream>
using namespace std;

void main()
{
	int a, b, c, temp;
	cout << "����������������";
	cin >> a >> b;
	c = a * b;
	if (b > a)  //��a,b�еĴ�ֵ��Ϊa СֵΪb
	{
		temp = a;
		a = b;
		b = temp;
	}
	while (a % b) //շת����������Լ��
	{
		temp = b;
		b = a % b;
		a = temp;
	}
	c = c / b;
	cout << "���Լ���ǣ�" << b << endl;
	cout << "��С�������ǣ�" << c << endl;
  system("pause");
}