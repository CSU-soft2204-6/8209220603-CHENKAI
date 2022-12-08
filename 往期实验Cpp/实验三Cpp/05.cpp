#include<iostream>
using namespace std;

int count(int day,int num)  //输入第day天时剩num个 输出第1天时总共的个数
{
	if (day > 1)
	{
		return count(--day,2 * (num + 1));
	}
	return num;
}
void main()
{
	cout<<"一共摘了 "<< count(10, 1) <<" 个桃子"<<endl;
}