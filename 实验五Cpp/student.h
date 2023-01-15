#pragma once
#include <string>
using namespace std;

class Student //类声明
{
public: //公用成员函数原型声明
	void display();
	Student();
	Student(int _num,string _name, char _sex);
	void set_value();

private:
	int num;
	string name;
	char sex;
};
