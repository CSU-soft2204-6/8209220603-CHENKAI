#pragma once
#include <iostream>
#include <fstream>
#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"
#define FILENAME "WorkerManagerSystemSaving.txt"
using namespace std;

class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//����Ϸ��Լ��
	bool CheckNum(string test);

	//���뷶Χ�޶�
	bool LimitNum(int &test,int a,int b);

	//ְ���������ж�
	int IsExist(int id);

	//��ʾ�˵�
	void ShowMenu();

	//�˳�����
	void ExitSystem();

	//ְ��������
	int w_WorkerNum;

	//ְ������ָ��
	Worker** w_WorkerpSpace;

	//�����ļ�
	void Save();
	
	//�ļ��Ƿ�Ϊ�ձ�־
	bool w_FileisEmpty;

	//��ȡ�ļ���¼��Ŀ
	int GetWorkerNum();

	//�ļ���ʼ��ְ��
	void InitWorker();

	//���ְ��
	void AddWorker();

	//��ʾְ��
	void ShowWorker();

	//ɾ��ְ��
	void DeleteWorker();

	//�޸�ְ��
	void ModifyWorker();

	//����ְ��
	void FindWorker();

	//����ְ��
	void SortWorker();

	//����ļ�
	void ClearFile();

	//��������
	~WorkerManager();

};

