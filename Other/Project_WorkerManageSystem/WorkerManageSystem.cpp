#include <iostream>
#include "WorkerManager.h"
using namespace std;

void main()
{
	//ʵ���������߶���
	WorkerManager wm;

	//�����û�ѡ��
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
			cout << "����Ƿ�  ����������" << endl;
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
			case 0://�˳�
			{
				wm.ExitSystem();
				break;
			}
			case 1://���
			{
				wm.AddWorker();
				break;
			}
			case 2://��ʾ
			{
				wm.ShowWorker();
				break;
			}
			case 3://ɾ��
			{
				wm.DeleteWorker();
				break;
			}
			case 4://�޸�
			{
				wm.ModifyWorker();
				break;
			}
			case 5://����
			{
				wm.FindWorker();
				break;
			}
			case 6://����
			{
				wm.SortWorker();
				break;
			}
			case 7://���
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