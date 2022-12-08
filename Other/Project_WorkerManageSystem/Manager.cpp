#include "Manager.h"

//构造函数
Manager::Manager(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_dId = did;
}

//显示个人信息
void Manager::ShowInfo()
{
	cout << "职工编号: " << this->w_Id << '\t'
		<< "职工姓名: " << this->w_Name << '\t'
		<< "职位:" << this->GetdName() << endl;
}

//获取岗位名称
string Manager::GetdName()
{
	return string("经理");
}