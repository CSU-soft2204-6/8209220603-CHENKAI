#include "Employee.h"

//���캯��
Employee::Employee(int id,string name,int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_dId = did;
}

//��ʾ������Ϣ
void Employee::ShowInfo()
{
	cout << "ְ�����: " << this->w_Id << '\t'
		 << "ְ������: " << this->w_Name << '\t'
		 << "ְλ:" << this->GetdName() << endl;
}

//��ȡ��λ����
string Employee::GetdName()
{
	return string("Ա��");
}