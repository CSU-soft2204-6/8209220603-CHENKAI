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
	//构造函数
	WorkerManager();

	//输入合法性检测
	bool CheckNum(string test);

	//输入范围限定
	bool LimitNum(int &test,int a,int b);

	//职工存在性判断
	int IsExist(int id);

	//显示菜单
	void ShowMenu();

	//退出程序
	void ExitSystem();

	//职工总人数
	int w_WorkerNum;

	//职工数组指针
	Worker** w_WorkerpSpace;

	//保存文件
	void Save();
	
	//文件是否为空标志
	bool w_FileisEmpty;

	//读取文件记录数目
	int GetWorkerNum();

	//文件初始化职工
	void InitWorker();

	//添加职工
	void AddWorker();

	//显示职工
	void ShowWorker();

	//删除职工
	void DeleteWorker();

	//修改职工
	void ModifyWorker();

	//查找职工
	void FindWorker();

	//排序职工
	void SortWorker();

	//清空文件
	void ClearFile();

	//析构函数
	~WorkerManager();

};

