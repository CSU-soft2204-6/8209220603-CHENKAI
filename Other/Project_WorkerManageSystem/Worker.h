#pragma once
#include <iostream>
using namespace std;

class Worker
{
public:

	//��ʾ������Ϣ
	virtual void ShowInfo() = 0;

	//��ȡ��λ����
	virtual string GetdName() = 0;

	int w_Id;//���

	string w_Name;//����

	int w_dId;//ְλ���
};

