#include <iostream> //��������ͷ�ļ���������
#include "student.h"

int main()
{
	Student stud; //�������
	Student stud1(007, "tcg", 'm');
	stud1.display(); //ִ�� stud1 ����� display ����
	stud.set_value();
	stud.display();
	return 0;
}