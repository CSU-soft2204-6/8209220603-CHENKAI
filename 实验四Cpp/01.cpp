#include<iostream>
using namespace std;

void main()
{
	const int Max = 10; //定义输入个数常量
	int arr[Max];
	for (int i = 0; i < Max; i++)
	{
		cin >> arr[i]; //存入arr
	}
	for (int i = 0; i < (Max - 1); i++)
	{
		bool flag = true; //是否输出标志 置为true
		for (int j = i + 1; j < Max; j++) //遍历当前数之后的每一个数
		{
			if (arr[i] == arr[j])
			{
				flag = false; //若有重复 置输出标志为false
			}
		}
		if (flag)
		{
			cout << arr[i]<<" "; //输出
		}
	}                            //通过此法 若有重复 则会输出重复数字中的最后的一个
	cout << arr[Max-1]; //最后数字无论是否重复都要输出
}
