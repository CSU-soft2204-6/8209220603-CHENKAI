#include <iostream>
#include"student.h" //��Ҫ©д���У��������ͨ����
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
	cout << "������ѧ���� num, name, sez: ";
	cin >> this->num >> this->name >> this->sex;
}

void Student::display() //�����ⶨ�� display �ຯ��
{
	cout << "num��" << num << endl;
	cout << "name��" << name << endl;
	cout << "sex��" << sex << endl;
}

