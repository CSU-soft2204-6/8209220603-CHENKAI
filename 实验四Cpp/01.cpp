#include<iostream>
using namespace std;

void main()
{
	const int Max = 10; //���������������
	int arr[Max];
	for (int i = 0; i < Max; i++)
	{
		cin >> arr[i]; //����arr
	}
	for (int i = 0; i < (Max - 1); i++)
	{
		bool flag = true; //�Ƿ������־ ��Ϊtrue
		for (int j = i + 1; j < Max; j++) //������ǰ��֮���ÿһ����
		{
			if (arr[i] == arr[j])
			{
				flag = false; //�����ظ� �������־Ϊfalse
			}
		}
		if (flag)
		{
			cout << arr[i]<<" "; //���
		}
	}                            //ͨ���˷� �����ظ� �������ظ������е�����һ��
	cout << arr[Max-1]; //������������Ƿ��ظ���Ҫ���
}
