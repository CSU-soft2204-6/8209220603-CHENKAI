#include "WorkerManager.h"


//构造函数
WorkerManager::WorkerManager()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //读文件

    //若文件不存在
    if (!ifs.is_open())
    {
        //初始化属性
        this->w_WorkerNum = 0;
        this->w_WorkerpSpace = NULL;
        this->w_FileisEmpty = true;

        ifs.close(); //关闭
        return;
    }

    //若文件存在且为空
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        //初始化属性
        this->w_WorkerNum = 0;
        this->w_WorkerpSpace = NULL;
        this->w_FileisEmpty = true;

        ifs.close(); //关闭
        return;
    }

    //若文件存在且不为空
    this->w_WorkerNum = this->GetWorkerNum(); //读取人数
    
    //开辟空间并调用初始化
    this->w_WorkerpSpace = new Worker * [this->w_WorkerNum];
    this->InitWorker();
}

//输入合法性检测
bool WorkerManager::CheckNum(string test)
{
    int i;
    for (i = 0; i < test.size(); ++i)
    {
        //判断是否为中文
        if (test[i] & 0x80) {
            return 0; //错误 return 0
        }
        //判断是否为字母或者其它字符
        if (!isdigit(test[i])) {
            return 0; //错误 return 0
        }
    }
    if (i == test.size())
    {
        return 1; //正确 return 1
    }
    return 0;
}

//输入范围限定
bool WorkerManager::LimitNum(int& test,int a,int b)
{
    if (test < a || test > b) //数值范围限定
    {
        cout << "输入非法  请重新输入" << endl;
        system("pause");
        return false;
    }
    return true;
}

//职工存在性判断
int WorkerManager::IsExist(int id)
{
    int index = -1; //默认值为不存在
    for (int i = 0; i < this->w_WorkerNum; i++)
    {
        //存在
        if (this->w_WorkerpSpace[i]->w_Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

//显示菜单
void WorkerManager::ShowMenu()
{
    cout << "--------------------------" << endl;
    cout << "---欢迎使用职工管理系统---" << endl;
    cout << "--------------------------" << endl;
    cout << "------1.添加职工信息------" << endl;
    cout << "------2.显示职工信息------" << endl;
    cout << "------3.删除离职职工------" << endl;
    cout << "------4.修改职工信息------" << endl;
    cout << "------5.查找职工信息------" << endl;
    cout << "------6.按照编号排序------" << endl;
    cout << "------7.清空所有文档------" << endl;
    cout << "------0.退出管理系统------" << endl;
    cout << "--------------------------" << endl;
    cout << endl;
    cout << "请输入相应功能前整数序号:" << endl;
}

//退出程序
void WorkerManager::ExitSystem()
{
    cout << "欢迎下次使用!" << endl;
    system("pause");
    exit(0);
}

//保存文件
void WorkerManager::Save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); //写文件

    //写入
    for (int i = 0; i < this->w_WorkerNum; i++)
    {
        ofs << this->w_WorkerpSpace[i]->w_Id << " "
            << this->w_WorkerpSpace[i]->w_Name << " "
            << this->w_WorkerpSpace[i]->w_dId << endl;
    }

    //关闭文件
    ofs.close();

    //更新文件是否为空状态
    this->w_FileisEmpty = false;
}

//读取文件记录数目
int WorkerManager::GetWorkerNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //读文件

    int id, did;
    string name;
    
    int num = 0; //总条目数
    while (ifs >> id && ifs >> name && ifs >> did)
    {
        num++;
    }

    ifs.close(); //关闭
    return num;
}

//文件初始化职工
void WorkerManager::InitWorker()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in); //读文件

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

    ifs.close(); //关闭
}

//添加职工
void WorkerManager::AddWorker()
{
    int addnum = 0;//添加的个数
    string addnum0;

    while (true)
    {
        cout << "请输入添加员工的数量: " << endl;
        cin >> addnum0;

        if (this->CheckNum(addnum0))
        {
            addnum = atoi(addnum0.c_str());
        }
        else
        {
            cout << "输入非法  请重新输入" << endl;
            system("pause");
            continue;
        }

        if (!this->LimitNum(addnum, 1, 100))
        {
            continue;
        }
        break;
    }

    //计算新空间大小
    int NewWorkerNum = this->w_WorkerNum + addnum;

    //开辟新空间
    Worker** NewWorkerpSpace = new Worker * [NewWorkerNum];

    //数据拷贝
    if (this->w_WorkerpSpace != NULL)
    {
        for (int i = 0; i < this->w_WorkerNum; i++)
        {
            NewWorkerpSpace[i] = this->w_WorkerpSpace[i];
        }
    }

    //批量添加新数据
    for (int i = 0; i < addnum; i++)
    {
        int id = 0; string id0;
        string name;
        int did = 0; string did0;
        
        while (true)
        {
            recheck1:
            cout << "请输入第 " << i + 1 << " 个职工的编号: " << endl;
            cin >> id0;

            if (this->CheckNum(id0))
            {
                id = atoi(id0.c_str());
            }
            else
            {
                cout << "输入非法  请重新输入" << endl;
                system("pause");
                continue;
            }

            if (!this->LimitNum(id, 0, 2147483647))
            {
                continue;
            }
            
            //检测编号重复
            for (int j = 0; j < (this->w_WorkerNum + i); j++)
            {
                if (NewWorkerpSpace[j]->w_Id == id)
                {
                    cout << "编号重复  请重新输入" << endl;
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
            cout << "请输入第 " << i + 1 << " 个职工的姓名: " << endl;
            cin >> name;

            //检测姓名重复
            for (int j = 0; j < (this->w_WorkerNum + i); j++)
            {
                if (NewWorkerpSpace[j]->w_Name == name)
                {
                    cout << "姓名重复  请重新输入" << endl;
                    system("pause");
                    goto recheck2;
                }
            }
            break;
        }

        while (true)
        {
            cout << endl;
            cout << "请输入第 " << i + 1 << " 个职工的职位编号: " << endl
                << "1. 员工" << endl
                << "2. 经理" << endl
                << "3. 老板" << endl;
            cin >> did0;

            if (this->CheckNum(did0))
            {
                did = atoi(did0.c_str());
            }
            else
            {
                cout << "输入非法  请重新输入" << endl;
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

        //将指针保存入数组
        NewWorkerpSpace[this->w_WorkerNum + i] = workerp;
    }

    //释放原有的空间
    delete[] this->w_WorkerpSpace;

    //更改新空间指向
    this->w_WorkerpSpace = NewWorkerpSpace;

    //更新职工人数
    this->w_WorkerNum = NewWorkerNum;

    //保存至文件
    this->Save();

    //提示
    cout << "添加成功 共 " << addnum << " 位新职工" << endl;

    system("pause");
    system("cls");
}

//显示职工
void WorkerManager::ShowWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "职工信息条目为空!" << endl;
    }
    else
    {
        cout << endl;
        for (int i = 0; i < this->w_WorkerNum; i++)
        {
            //多态性调用展示接口
            this->w_WorkerpSpace[i]->ShowInfo();
        }
    }
    
    system("pause");
    system("cls");
}

//删除职工
void WorkerManager::DeleteWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "职工信息条目为空!" << endl;
    }
    else
    {
        int id = 0;
        string id0;

        while (true)
        {
            cout << "请输入删除职工的编号: " << endl;
            cin >> id0;

            if (this->CheckNum(id0))
            {
                id = atoi(id0.c_str());
            }
            else
            {
                cout << "输入非法  请重新输入" << endl;
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
            cout << "删除失败  职工不存在" << endl;
        }
        else
        {
            //数据前移做除最后条目外删除
            for (int i = index; i < (this->w_WorkerNum - 1); i++)
            {
                this->w_WorkerpSpace[i] = this->w_WorkerpSpace[i + 1];
            }
            //更新职工人数
            this->w_WorkerNum--;

            //更新至文件
            this->Save();

            //更新文件是否为空状态
            char ch;
            ifstream ifs;
            ifs.open(FILENAME, ios::in);
            ifs >> ch;
            if (ifs.eof())
            {
                this->w_FileisEmpty = true;
                ifs.close(); //关闭
            }

            //提示
            cout << "删除成功" << endl;
        }
    }
    system("pause");
    system("cls");
}

//修改职工
void WorkerManager::ModifyWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "职工信息条目为空!" << endl;
    }
    else
    {
        int id = 0;
        string id0;

        while (true)
        {
            cout << "请输入修改职工的编号: " << endl;
            cin >> id0;

            if (this->CheckNum(id0))
            {
                id = atoi(id0.c_str());
            }
            else
            {
                cout << "输入非法  请重新输入" << endl;
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
            cout << "修改失败  职工不存在" << endl;
        }
        else
        {
            //释放
            delete this->w_WorkerpSpace[index];

            int newid = 0; string newid0;
            string newname;
            int newdid = 0; string newdid0;

            while (true)
            {
            recheck3:
                cout << "已查找到编号为 " << id << " 号职工" << endl
                     << "请输入新的职工编号: " << endl;
                cin >> newid0;

                if (this->CheckNum(newid0))
                {
                    newid = atoi(newid0.c_str());
                }
                else
                {
                    cout << "输入非法  请重新输入" << endl;
                    system("pause");
                    continue;
                }

                if (!this->LimitNum(newid, 0, 2147483647))
                {
                    continue;
                }

                //检测编号重复
                for (int j = 0; j < (this->w_WorkerNum); j++)
                {
                    if (this->w_WorkerpSpace[j]->w_Id == id)
                    {
                        cout << "编号重复  请重新输入" << endl;
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
                cout << "请输入新职工姓名: " << endl;
                cin >> newname;

                //检测姓名重复
                for (int j = 0; j < (this->w_WorkerNum); j++)
                {
                    if (this->w_WorkerpSpace[j]->w_Name == newname)
                    {
                        cout << "姓名重复  请重新输入" << endl;
                        system("pause");
                        goto recheck4;
                    }
                }
                break;
            }

            while (true)
            {
                cout << endl;
                cout << "请输入新职位编号: " << endl
                    << "1. 员工" << endl
                    << "2. 经理" << endl
                    << "3. 老板" << endl;
                cin >> newdid0;

                if (this->CheckNum(newdid0))
                {
                    newdid = atoi(newdid0.c_str());
                }
                else
                {
                    cout << "输入非法  请重新输入" << endl;
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

            //更新至文件
            this->Save();

            //提示
            cout << "修改成功" << endl;
        }
    }
    system("pause");
    system("cls");
}

//查找职工
void WorkerManager::FindWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "职工信息条目为空!" << endl;
    }
    else
    {
        int select = 0;
        string select0;

        while (true)
        {
            cout << "请输入查找的方式序号: " <<  endl
                 << "1. 按职工编号查找" << endl
                 << "2. 按职工姓名查找" << endl;
            cin >> select0;

            if (this->CheckNum(select0))
            {
                select = atoi(select0.c_str());
            }
            else
            {
                cout << "输入非法  请重新输入" << endl;
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
                cout << "请输入查找职工的编号: " << endl;
                cin >> id0;

                if (this->CheckNum(id0))
                {
                    id = atoi(id0.c_str());
                }
                else
                {
                    cout << "输入非法  请重新输入" << endl;
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
                cout << "查找失败  职工不存在" << endl;
            }
            else
            {
                cout << "查找成功  该职工信息如下: " << endl << endl;
                this->w_WorkerpSpace[index]->ShowInfo();
            }
        }
        else if (select == 2)
        {
            string name;
            cout << "请输入查找职工的姓名: " << endl;
            cin >> name;

            bool flag = false; //查找成功的标准
            for (int i = 0; i < this->w_WorkerNum; i++)
            {
                if (this->w_WorkerpSpace[i]->w_Name == name)
                {
                    cout << "查找成功  该职工信息如下: " << endl << endl;
                    this->w_WorkerpSpace[i]->ShowInfo();
                    flag = true;
                }
            }
            if (flag == false)
            {
                cout << "查找失败  职工不存在" << endl;
            }
        }
    }
    system("pause");
    system("cla");
}

//排序职工
void WorkerManager::SortWorker()
{
    if (this->w_FileisEmpty)
    {
        cout << "职工信息条目为空!" << endl;
        system("pause");
        system("cla");
    }
    else
    {
        int select = 0;
        string select0;

        while (true)
        {
            cout << "请输入排序的方式序号: " << endl
                << "1. 按职工编号升序排序" << endl
                << "2. 按职工编号降序排序" << endl;
            cin >> select0;

            if (this->CheckNum(select0))
            {
                select = atoi(select0.c_str());
            }
            else
            {
                cout << "输入非法  请重新输入" << endl;
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
                if (select == 1) //升序
                {
                    if (this->w_WorkerpSpace[MaxOrMin]->w_Id > this->w_WorkerpSpace[j]->w_Id)
                    {
                        MaxOrMin = j;
                    }
                }
                else if (select == 2)  //降序
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
        //保存文件
        this->Save();

        //提示并展示
        cout << "排序成功  排序后结果为: " << endl;
        this->ShowWorker();
    }
}

//清空文件
void WorkerManager::ClearFile()
{
    if (this->w_FileisEmpty)
    {
        cout << "职工信息条目为空!" << endl;
    }
    else
    {
        int select = 0;
        string select0;

        while (true)
        {
            cout << "确认清空 此操作无法撤回: " << endl
                << "1. 确认" << endl
                << "2. 取消" << endl;
            cin >> select0;

            if (this->CheckNum(select0))
            {
                select = atoi(select0.c_str());
            }
            else
            {
                cout << "输入非法  请重新输入" << endl;
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
           //若文件存在  删除文件并重新创建
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
            cout << "清空成功" << endl;
        }
        else if (select == 2)
        {
            cout << "清空取消成功" << endl;
        }
    }
    system("pause");
    system("cls");
}

//析构函数
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
