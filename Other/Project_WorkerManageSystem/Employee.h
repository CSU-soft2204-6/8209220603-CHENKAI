#pragma once
#include <iostream>
#include "Worker.h"
using namespace std;

class Employee : public Worker
{
public:
	
	//���캯��
	Employee(int id, string name, int did);

	//��ʾ������Ϣ
	virtual void ShowInfo();

	//��ȡ��λ����
	virtual string GetdName();
};

