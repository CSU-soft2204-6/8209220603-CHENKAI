#include<iostream>
using namespace std;
class Time // ���� Time ��
{
private: // ���ݳ�ԱΪ˽�е�
	int hour;
	int minute;
	int sec;

public:
	void settime()
	{
		cout << "SetTime :  hour minute second" << endl;
		cin >> this->hour; //�����趨��ʱ��
		cin >> this->minute;
		cin >> this->sec;
	}

	void showtime()
	{
		cout << "ShowTime :  ";
		cout << this->hour << " ��" << this->minute << " ��" << this->sec << endl;
	}
};
int main()
{
	Time t1; //���� t1 Ϊ Time �����
	t1.settime();
	t1.showtime();
	return 0;
}