#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Boss : public Worker
{
public:

	//���캯��
	Boss(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetdName();
};

