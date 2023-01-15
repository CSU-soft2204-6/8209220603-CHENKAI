#include<iostream>
using namespace std;
class Time // 定义 Time 类
{
private: // 数据成员为私有的
	int hour;
	int minute;
	int sec;

public:
	void settime()
	{
		cout << "SetTime :  hour minute second" << endl;
		cin >> this->hour; //输入设定的时间
		cin >> this->minute;
		cin >> this->sec;
	}

	void showtime()
	{
		cout << "ShowTime :  ";
		cout << this->hour << " ：" << this->minute << " ：" << this->sec << endl;
	}
};
int main()
{
	Time t1; //定义 t1 为 Time 类对象
	t1.settime();
	t1.showtime();
	return 0;
}