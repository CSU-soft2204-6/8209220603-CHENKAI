#include "Boss.h"

//���캯��
Boss::Boss(int id, string name, int did)
{
	this->w_Id = id;
	this->w_Name = name;
	this->w_dId = did;
}

//��ʾ������Ϣ
void Boss::ShowInfo()
{
	cout << "ְ�����: " << this->w_Id << '\t'
		 << "ְ������: " << this->w_Name << '\t'
		 << "ְλ:" << this->GetdName() << endl;
}

//��ȡ��λ����
string Boss::GetdName()
{
	return string("�ϰ�");
}