#include<iostream>
using namespace std;

int count(int day,int num)  //�����day��ʱʣnum�� �����1��ʱ�ܹ��ĸ���
{
	if (day > 1)
	{
		return count(--day,2 * (num + 1));
	}
	return num;
}
void main()
{
	cout<<"һ��ժ�� "<< count(10, 1) <<" ������"<<endl;
}