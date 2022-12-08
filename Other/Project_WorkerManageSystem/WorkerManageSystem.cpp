#include <iostream>
#include "WorkerManager.h"
using namespace std;

void main()
{
	//实例化管理者对象
	WorkerManager wm;

	//接受用户选择
	int choice = 0;
	string choice0;

	while (true)
	{
		wm.ShowMenu();
		cin >> choice0;

		if (wm.CheckNum(choice0))
		{
			choice = atoi(choice0.c_str());
		}
		else
		{
			cout << "输入非法  请重新输入" << endl;
			system("pause");
			system("cls");
			continue;
		}

		if (!wm.LimitNum(choice, 0, 7))
		{
			system("cls");
			continue;
		}

		switch (choice)
		{
			case 0://退出
			{
				wm.ExitSystem();
				break;
			}
			case 1://添加
			{
				wm.AddWorker();
				break;
			}
			case 2://显示
			{
				wm.ShowWorker();
				break;
			}
			case 3://删除
			{
				wm.DeleteWorker();
				break;
			}
			case 4://修改
			{
				wm.ModifyWorker();
				break;
			}
			case 5://查找
			{
				wm.FindWorker();
				break;
			}
			case 6://排序
			{
				wm.SortWorker();
				break;
			}
			case 7://清空
			{
				wm.ClearFile();
				break;
			}
			default:
				system("cls");
				break;
		}

	}

	system("pause");
}