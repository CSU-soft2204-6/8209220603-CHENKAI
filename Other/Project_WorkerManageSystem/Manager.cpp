#include "Manager.h"

//���캯��
Manager::Manager(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_dId = did;
}

//��ʾ������Ϣ
void Manager::ShowInfo()
{
	cout << "ְ�����: " << this->w_Id << '\t'
		<< "ְ������: " << this->w_Name << '\t'
		<< "ְλ:" << this->GetdName() << endl;
}

//��ȡ��λ����
string Manager::GetdName()
{
	return string("����");
}