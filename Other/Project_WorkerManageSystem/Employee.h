#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Employee : public Worker
{
public:
	
	//构造函数
	Employee(int id, string name, int did);

	//显示个人信息
	virtual void ShowInfo();

	//获取岗位名称
	virtual string GetdName();
};

