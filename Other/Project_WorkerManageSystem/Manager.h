#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Manager : public Worker
{
public:

	//���캯��
	Manager(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetdName();
};

