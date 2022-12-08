#include "Boss.h"

//构造函数
Boss::Boss(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_dId = did;
}

//显示个人信息
void Boss::ShowInfo()
{
	cout << "职工编号: " << this->w_Id << '\t'
		 << "职工姓名: " << this->w_Name << '\t'
		 << "职位:" << this->GetdName() << endl;
}

//获取岗位名称
string Boss::GetdName()
{
	return string("老板");
}