#pragma once
#include <iostream>
using namespace std;

class Worker
{
public:

	//显示个人信息
	virtual void ShowInfo() = 0;

	//获取岗位名称
	virtual string GetdName() = 0;

	int w_Id;//编号

	string w_Name;//姓名

	int w_dId;//职位编号
};

