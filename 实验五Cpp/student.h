#pragma once
#include <string>
using namespace std;

class Student //������
{
public: //���ó�Ա����ԭ������
	void display();
	Student();
	Student(int _num,string _name, char _sex);
	void set_value();

private:
	int num;
	string name;
	char sex;
};
