#include <iostream> //将类声明头文件包含进来
#include "student.h"

int main()
{
	Student stud; //定义对象
	Student stud1(007, "tcg", 'm');
	stud1.display(); //执行 stud1 对象的 display 函数
	stud.set_value();
	stud.display();
	return 0;
}