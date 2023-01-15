#include <iostream>
#include"student.h" //不要漏写此行，否则编译通不过
using namespace std;


Student::Student(){}

Student::Student(int _num, string _name, char _sex)
{
	this->num = _num;
	this->name = _name;
	this->sex = _sex;
}

void Student::set_value()
{
	cout << "请输入学生的 num, name, sez: ";
	cin >> this->num >> this->name >> this->sex;
}

void Student::display() //在类外定义 display 类函数
{
	cout << "num：" << num << endl;
	cout << "name：" << name << endl;
	cout << "sex：" << sex << endl;
}

