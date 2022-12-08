#include "WorkerManager.h"


//���캯��
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //���ļ�

    //���ļ�������
    if (!ifs.is_open())
    {
        //��ʼ������
        this->w_WorkerNum = 0;
        this->w_WorkerpSpace = NULL;
        this->w_FileisEmpty = true;

        ifs.close(); //�ر�
        return;
    }

    //���ļ�������Ϊ��
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //��ʼ������
        this->w_WorkerNum = 0;
        this->w_WorkerpSpace = NULL;
        this->w_FileisEmpty = true;

        ifs.close(); //�ر�
        return;
    }

    //���ļ������Ҳ�Ϊ��
    this->w_WorkerNum = this->GetWorkerNum(); //��ȡ����
    
    //���ٿռ䲢���ó�ʼ��
    this->w_WorkerpSpace = new Worker * [this->w_WorkerNum];
    this->InitWorker();
}

//����Ϸ��Լ��
bool WorkerManager::CheckNum(string test)
{
    int i;
    for (i = 0; i < test.size(); ++i)
    {
        //�ж��Ƿ�Ϊ����
        if (test[i] & 0x80) {
            return 0; //���� return 0
        }
        //�ж��Ƿ�Ϊ��ĸ���������ַ�
        if (!isdigit(test[i])) {
            return 0; //���� return 0
        }
    }
    if (i == test.size())
    {
        return 1; //��ȷ return 1
    }
    return 0;
}

//���뷶Χ�޶�
bool WorkerManager::LimitNum(int& test,int a,int b)
{
    if (test < a || test > b) //��ֵ��Χ�޶�
    {
        cout << "����Ƿ�  ����������" << endl;
        system("pause");
        return false;
    }
    return true;
}

//ְ���������ж�
int WorkerManager::IsExist(int id)
{
    int index = -1; //Ĭ��ֵΪ������
    for (int i = 0; i < this->w_WorkerNum; i++)
    {
        //����
        if (this->w_WorkerpSpace[i]->w_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

//��ʾ�˵�
void WorkerManager::ShowMenu()
{
    cout << "--------------------------" << endl;
    cout << "---��ӭʹ��ְ������ϵͳ---" << endl;
    cout << "--------------------------" << endl;
    cout << "------1.���ְ����Ϣ------" << endl;
    cout << "------2.��ʾְ����Ϣ------" << endl;
    cout << "------3.ɾ����ְְ��------" << endl;
    cout << "------4.�޸�ְ����Ϣ------" << endl;
    cout << "------5.����ְ����Ϣ------" << endl;
    cout << "------6.���ձ������------" << endl;
    cout << "------7.��������ĵ�------" << endl;
    cout << "------0.�˳�����ϵͳ------" << endl;
    cout << "--------------------------" << endl;
    cout << endl;
    cout << "��������Ӧ����ǰ�������:" << endl;
}

//�˳�����
void WorkerManager::ExitSystem()
{
    cout << "��ӭ�´�ʹ��!" << endl;
    system("pause");
    exit(0);
}

//�����ļ�
void WorkerManager::Save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); //д�ļ�

    //д��
    for (int i = 0; i < this->w_WorkerNum; i++)
    {
        ofs << this->w_WorkerpSpace[i]->w_Id << " "
            << this->w_WorkerpSpace[i]->w_Name << " "
            << this->w_WorkerpSpace[i]->w_dId << endl;
    }

    //�ر��ļ�
    ofs.close();

    //�����ļ��Ƿ�Ϊ��״̬
    this->w_FileisEmpty = false;
}

//��ȡ�ļ���¼��Ŀ
int WorkerManager::GetWorkerNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //���ļ�

    int id, did;
    string name;
    
    int num = 0; //����Ŀ��
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }

    ifs.close(); //�ر�
    return num;
}

//�ļ���ʼ��ְ��
void WorkerManager::InitWorker()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //���ļ�

    int id, did;
    string name;

    int index =0;
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        Worker* workerp = NULL;

        if (did == 1)
        {
            workerp = new Employee(id, name, did);
        }
        else if (did == 2)
        {
            workerp = new Manager(id, name, did);
        }
        else
        {
            workerp = new Boss(id, name, did);
        }
        this->w_WorkerpSpace[index] = workerp;
        index++;
    }

    ifs.close(); //�ر�
}

//���ְ��
void WorkerManager::AddWorker()
{
    int addnum = 0;//��ӵĸ���
    string addnum0;

    while (true)
    {
        cout << "���������Ա��������: " << endl;
        cin >> addnum0;

        if (this->CheckNum(addnum0))
        {
            addnum = atoi(addnum0.c_str());
        }
        else
        {
            cout << "����Ƿ�  ����������" << endl;
            system("pause");
            continue;
        }

        if (!this->LimitNum(addnum, 1, 100))
        {
            continue;
        }
        break;
    }

    //�����¿ռ��С
    int NewWorkerNum = this->w_WorkerNum + addnum;

    //�����¿ռ�
    Worker** NewWorkerpSpace = new Worker * [NewWorkerNum];

    //���ݿ���
    if (this->w_WorkerpSpace != NULL)
    {
        for (int i = 0; i < this->w_WorkerNum; i++)
        {
            NewWorkerpSpace[i] = this->w_WorkerpSpace[i];
        }
    }

    //�������������
    for (int i = 0; i < addnum; i++)
    {
        int id = 0; string id0;
        string name;
        int did = 0; string did0;
        
        while (true)
        {
            recheck1:
            cout << "������� " << i + 1 << " ��ְ���ı��: " << endl;
            cin >> id0;

            if (this->CheckNum(id0))
            {
                id = atoi(id0.c_str());
            }
            else
            {
                cout << "����Ƿ�  ����������" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(id, 0, 2147483647))
            {
                continue;
            }
            
            //������ظ�
            for (int j = 0; j < (this->w_WorkerNum + i); j++)
            {
                if (NewWorkerpSpace[j]->w_Id == id)
                {
                    cout << "����ظ�  ����������" << endl;
                    system("pause");
                    goto recheck1;
                }
            }
            break;
        }

        cout << endl;
        while (true)
        {
        recheck2:
            cout << "������� " << i + 1 << " ��ְ��������: " << endl;
            cin >> name;

            //��������ظ�
            for (int j = 0; j < (this->w_WorkerNum + i); j++)
            {
                if (NewWorkerpSpace[j]->w_Name == name)
                {
                    cout << "�����ظ�  ����������" << endl;
                    system("pause");
                    goto recheck2;
                }
            }
            break;
        }

        while (true)
        {
            cout << endl;
            cout << "������� " << i + 1 << " ��ְ����ְλ���: " << endl
                << "1. Ա��" << endl
                << "2. ����" << endl
                << "3. �ϰ�" << endl;
            cin >> did0;

            if (this->CheckNum(did0))
            {
                did = atoi(did0.c_str());
            }
            else
            {
                cout << "����Ƿ�  ����������" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(did, 1, 3))
            {
                continue;
            }
            break;
        }
        
        Worker* workerp = NULL;
        switch (did)
        {
        case 1:
            workerp = new Employee(id, name, 1);
            break;
        case 2:
            workerp = new Manager(id, name, 2);
            break;
        case 3:
            workerp = new Boss(id, name, 3);
            break;
        default:
            break;
        }

        //��ָ�뱣��������
        NewWorkerpSpace[this->w_WorkerNum + i] = workerp;
    }

    //�ͷ�ԭ�еĿռ�
    delete[] this->w_WorkerpSpace;

    //�����¿ռ�ָ��
    this->w_WorkerpSpace = NewWorkerpSpace;

    //����ְ������
    this->w_WorkerNum = NewWorkerNum;

    //�������ļ�
    this->Save();

    //��ʾ
    cout << "��ӳɹ� �� " << addnum << " λ��ְ��" << endl;

    system("pause");
    system("cls");
}

//��ʾְ��
void WorkerManager::ShowWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "ְ����Ϣ��ĿΪ��!" << endl;
    }
    else
    {
        cout << endl;
        for (int i = 0; i < this->w_WorkerNum; i++)
        {
            //��̬�Ե���չʾ�ӿ�
            this->w_WorkerpSpace[i]->ShowInfo();
        }
    }
    
    system("pause");
    system("cls");
}

//ɾ��ְ��
void WorkerManager::DeleteWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "ְ����Ϣ��ĿΪ��!" << endl;
    }
    else
    {
        int id = 0;
        string id0;

        while (true)
        {
            cout << "������ɾ��ְ���ı��: " << endl;
            cin >> id0;

            if (this->CheckNum(id0))
            {
                id = atoi(id0.c_str());
            }
            else
            {
                cout << "����Ƿ�  ����������" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(id, 1, 100))
            {
                continue;
            }
            break;
        }
        int index = this->IsExist(id);
        if (index == -1)
        {
            cout << "ɾ��ʧ��  ְ��������" << endl;
        }
        else
        {
            //����ǰ�����������Ŀ��ɾ��
            for (int i = index; i < (this->w_WorkerNum - 1); i++)
            {
                this->w_WorkerpSpace[i] = this->w_WorkerpSpace[i + 1];
            }
            //����ְ������
            this->w_WorkerNum--;

            //�������ļ�
            this->Save();

            //�����ļ��Ƿ�Ϊ��״̬
            char ch;
            ifstream ifs;
            ifs.open(FILENAME, ios::in);
            ifs >> ch;
            if (ifs.eof())
            {
                this->w_FileisEmpty = true;
                ifs.close(); //�ر�
            }

            //��ʾ
            cout << "ɾ���ɹ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

//�޸�ְ��
void WorkerManager::ModifyWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "ְ����Ϣ��ĿΪ��!" << endl;
    }
    else
    {
        int id = 0;
        string id0;

        while (true)
        {
            cout << "�������޸�ְ���ı��: " << endl;
            cin >> id0;

            if (this->CheckNum(id0))
            {
                id = atoi(id0.c_str());
            }
            else
            {
                cout << "����Ƿ�  ����������" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(id, 1, 100))
            {
                continue;
            }
            break;
        }
        int index = this->IsExist(id);
        if (index == -1)
        {
            cout << "�޸�ʧ��  ְ��������" << endl;
        }
        else
        {
            //�ͷ�
            delete this->w_WorkerpSpace[index];

            int newid = 0; string newid0;
            string newname;
            int newdid = 0; string newdid0;

            while (true)
            {
            recheck3:
                cout << "�Ѳ��ҵ����Ϊ " << id << " ��ְ��" << endl
                     << "�������µ�ְ�����: " << endl;
                cin >> newid0;

                if (this->CheckNum(newid0))
                {
                    newid = atoi(newid0.c_str());
                }
                else
                {
                    cout << "����Ƿ�  ����������" << endl;
                    system("pause");
                    continue;
                }

                if (!this->LimitNum(newid, 0, 2147483647))
                {
                    continue;
                }

                //������ظ�
                for (int j = 0; j < (this->w_WorkerNum); j++)
                {
                    if (this->w_WorkerpSpace[j]->w_Id == id)
                    {
                        cout << "����ظ�  ����������" << endl;
                        system("pause");
                        goto recheck3;
                    }
                }
                break;
            }

            cout << endl;
            while (true)
            {
            recheck4:
                cout << "��������ְ������: " << endl;
                cin >> newname;

                //��������ظ�
                for (int j = 0; j < (this->w_WorkerNum); j++)
                {
                    if (this->w_WorkerpSpace[j]->w_Name == newname)
                    {
                        cout << "�����ظ�  ����������" << endl;
                        system("pause");
                        goto recheck4;
                    }
                }
                break;
            }

            while (true)
            {
                cout << endl;
                cout << "��������ְλ���: " << endl
                    << "1. Ա��" << endl
                    << "2. ����" << endl
                    << "3. �ϰ�" << endl;
                cin >> newdid0;

                if (this->CheckNum(newdid0))
                {
                    newdid = atoi(newdid0.c_str());
                }
                else
                {
                    cout << "����Ƿ�  ����������" << endl;
                    system("pause");
                    continue;
                }

                if (!this->LimitNum(newdid, 1, 3))
                {
                    continue;
                }
                break;
            }

            Worker* workerp = NULL;
            switch (newdid)
            {
            case 1:
                workerp = new Employee(newid, newname, 1);
                break;
            case 2:
                workerp = new Manager(newid, newname, 2);
                break;
            case 3:
                workerp = new Boss(newid, newname, 3);
                break;
            default:
                break;
            }

            //�������ļ�
            this->Save();

            //��ʾ
            cout << "�޸ĳɹ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

//����ְ��
void WorkerManager::FindWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "ְ����Ϣ��ĿΪ��!" << endl;
    }
    else
    {
        int select = 0;
        string select0;

        while (true)
        {
            cout << "��������ҵķ�ʽ���: " <<  endl
                 << "1. ��ְ����Ų���" << endl
                 << "2. ��ְ����������" << endl;
            cin >> select0;

            if (this->CheckNum(select0))
            {
                select = atoi(select0.c_str());
            }
            else
            {
                cout << "����Ƿ�  ����������" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(select, 1, 2))
            {
                continue;
            }
            break;
        }
        if (select == 1)
        {
            int id;
            string id0;
            while (true)
            {
                cout << "���������ְ���ı��: " << endl;
                cin >> id0;

                if (this->CheckNum(id0))
                {
                    id = atoi(id0.c_str());
                }
                else
                {
                    cout << "����Ƿ�  ����������" << endl;
                    system("pause");
                    continue;
                }

                if (!this->LimitNum(id, 1, 100))
                {
                    continue;
                }
                break;
            }
            int index = this->IsExist(id);
            if (index == -1)
            {
                cout << "����ʧ��  ְ��������" << endl;
            }
            else
            {
                cout << "���ҳɹ�  ��ְ����Ϣ����: " << endl << endl;
                this->w_WorkerpSpace[index]->ShowInfo();
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "���������ְ��������: " << endl;
            cin >> name;

            bool flag = false; //���ҳɹ��ı�׼
            for (int i = 0; i < this->w_WorkerNum; i++)
            {
                if (this->w_WorkerpSpace[i]->w_Name == name)
                {
                    cout << "���ҳɹ�  ��ְ����Ϣ����: " << endl << endl;
                    this->w_WorkerpSpace[i]->ShowInfo();
                    flag = true;
                }
            }
            if (flag == false)
            {
                cout << "����ʧ��  ְ��������" << endl;
            }
        }
    }
    system("pause");
    system("cla");
}

//����ְ��
void WorkerManager::SortWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "ְ����Ϣ��ĿΪ��!" << endl;
        system("pause");
        system("cla");
    }
    else
    {
        int select = 0;
        string select0;

        while (true)
        {
            cout << "����������ķ�ʽ���: " << endl
                << "1. ��ְ�������������" << endl
                << "2. ��ְ����Ž�������" << endl;
            cin >> select0;

            if (this->CheckNum(select0))
            {
                select = atoi(select0.c_str());
            }
            else
            {
                cout << "����Ƿ�  ����������" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(select, 1, 2))
            {
                continue;
            }
            break;
        }
        for (int i = 0; i < (this->w_WorkerNum - 1); i++)
        {
            int MaxOrMin = i;
            for (int j = i + 1; j < this->w_WorkerNum; j++)
            {
                if (select == 1) //����
                {
                    if (this->w_WorkerpSpace[MaxOrMin]->w_Id > this->w_WorkerpSpace[j]->w_Id)
                    {
                        MaxOrMin = j;
                    }
                }
                else if (select == 2)  //����
                {
                    if (this->w_WorkerpSpace[MaxOrMin]->w_Id < this->w_WorkerpSpace[j]->w_Id)
                    {
                        MaxOrMin = j;
                    }
                }
            }

            if (i != MaxOrMin)
            {
                Worker* temp = this->w_WorkerpSpace[i];
                this->w_WorkerpSpace[i] = this->w_WorkerpSpace[MaxOrMin];
                this->w_WorkerpSpace[MaxOrMin] = temp;
            }
        }
        //�����ļ�
        this->Save();

        //��ʾ��չʾ
        cout << "����ɹ�  �������Ϊ: " << endl;
        this->ShowWorker();
    }
}

//����ļ�
void WorkerManager::ClearFile()
{
    if (this->w_FileisEmpty)
    {
        cout << "ְ����Ϣ��ĿΪ��!" << endl;
    }
    else
    {
        int select = 0;
        string select0;

        while (true)
        {
            cout << "ȷ����� �˲����޷�����: " << endl
                << "1. ȷ��" << endl
                << "2. ȡ��" << endl;
            cin >> select0;

            if (this->CheckNum(select0))
            {
                select = atoi(select0.c_str());
            }
            else
            {
                cout << "����Ƿ�  ����������" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(select, 1, 2))
            {
                continue;
            }
            break;
        }
        if (select == 1)
        {
           //���ļ�����  ɾ���ļ������´���
            ofstream ofs(FILENAME, ios::trunc);
            ofs.close();

            if (this->w_WorkerpSpace != NULL)
            {
                for (int i = 0; i < this->w_WorkerNum; i++)
                {
                    if (this->w_WorkerpSpace[i] != NULL)
                    {
                        delete this->w_WorkerpSpace[i];
                    }
                }
                this->w_WorkerNum = 0;
                delete[] this->w_WorkerpSpace;
                this->w_WorkerpSpace = NULL;
                this->w_FileisEmpty = true;
            }
            cout << "��ճɹ�" << endl;
        }
        else if (select == 2)
        {
            cout << "���ȡ���ɹ�" << endl;
        }
    }
    system("pause");
    system("cls");
}

//��������
WorkerManager::~WorkerManager()
{
    if (this->w_WorkerpSpace != NULL)
    {
        for (int i = 0; i < this->w_WorkerNum; i++)
        {
            if (this->w_WorkerpSpace[i] != NULL)
            {
                delete this->w_WorkerpSpace[i];
            }
        }
        
        delete[] this->w_WorkerpSpace;
        this->w_WorkerpSpace = NULL;
    }
}
