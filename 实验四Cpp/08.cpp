#include<iostream>
using namespace std;

int parseHex(const char* const hexString)
{
	int len, sum = 0;
	len = strlen(hexString);
	int* arr=new int [len];
	for (int i = 0; i < len; i++)
	{
		if (hexString[i] >= 'A' && hexString[i] <= 'F')
		{
			arr[i] = (int(hexString[i]) - 55) * (pow(16, len - 1 - i));
		}
		else
		{
			arr[i] = (hexString[i] - 48) * pow(16, len - i - 1);
		}
		sum = sum + arr[i];
	}
	delete[] arr;
	return sum;
}

void main()
{
	char s[80];
	cout << "������һ��16��������: " << endl;
	cin.getline(s, 80);
	cout<<"��10���Ʊ�ʾΪ: "<<parseHex(s)<<endl;
	system("pause");
}