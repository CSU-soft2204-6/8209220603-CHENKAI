//通讯录程序

//写入头文件
#include <iostream> //cin和cout头文件
#include <string> //string头文件
#include <cstdlib> //system不明确的解决

//分配命名空间
using namespace std;

//定义宏常量
#define MAX 100 //通讯录人数最大值常量

//定义结构体
    //定义联系人结构体
    struct Person 
    {
        //姓名
        string m_Name;
        //性别
        int m_Sex = 0;
        //年龄
        int m_Age = 0;
        //电话
        string m_Phone;
        //住址
        string m_Address;
    };

    //定义通讯录结构体
    struct Addressbooks 
    {
        //通讯录中保存的联系人数组
        //为了保证最后一位数在覆盖删除中不越界 数组定义时上界为MAX + 1
        struct Person personArray[MAX + 1];
        //通讯录中当前的联系人分数
        int m_Size = 0;
    };

//定义函数
    //菜单函数定义
    void showMenu() 
    {
        cout << "--------------------------" << endl;
        cout << "------欢迎使用通讯录------" << endl;
        cout << "--------------------------" << endl;
        cout << "-----1.添加指定联系人-----" << endl;
        cout << "-----2.显示所有联系人-----" << endl;
        cout << "-----3.删除指定联系人-----" << endl;
        cout << "-----4.查找指定联系人-----" << endl;
        cout << "-----5.修改指定联系人-----" << endl;
        cout << "-----6.清空所有联系人-----" << endl;
        cout << "-----0.退出通讯录系统-----" << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        cout << "请输入相应功能前整数序号:" << endl;
    }

    //检测联系人存在函数定义
    int isExist(Addressbooks * abs, string name)  //通信录参数和检测姓名参数
    {
        for (int i = 0; i < abs->m_Size; i++) //遍历联系人
        {
            if (abs->personArray[i].m_Name == name) //检测成功 return数组中的编号
            {
                return i;
            }
        }
        //检测失败 return-1
        return - 1;
    }

    //合法输入检测函数定义
    int CheckNum(string test)
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

    //1.添加指定联系人函数定义
    void addPerson(Addressbooks * abs) 
    {
        //提示进入函数
        cout << "添加指定联系人:" << endl << endl;
        
        //判断通讯录是否已满
        if (abs->m_Size == MAX)
        {
            cout << "通讯录已满  无法添加" << endl <<endl;
        }
        else
        {
            //添加联系人信息

            //姓名
            string name; //定义姓名变量
            cout << "请输入联系人姓名:" << endl;
            cin >> name;

            //判断是否出现重名现象
            int ret = isExist(abs, name);
            if (ret != -1) //重名
            {
                cout << "联系人出现重名不合法  请尝试作区分后再添加" << endl << endl;
                
                //等待并清屏
                system("pause");
                system("cls");
                return; //终止函数
            }
            else //不重名
            {
                abs->personArray[abs->m_Size].m_Name = name; //保存姓名
                cout << endl;
            }

            //性别
            string sex0; //定义初始字符串性别变量 方便检测输入是否合法
            int sex; //定义最终检测合格的性别变量
            while (true) //重新输入循环体
            {
                cout << "请输入联系人性别:" << endl;
                cout << "1 --- 男    2 --- 女" << endl;
                cin >> sex0;
                if (CheckNum(sex0) == 0) //检测是否合法
                {
                    cout << "输入非法  请重新输入" << endl << endl;
                    continue;
                }
                else
                {
                    sex = atoi(sex0.c_str()); //为最终性别变量赋值

                    if (sex < 1 || sex > 2) //数值范围限定
                    {
                        cout << "输入非法  请重新输入" << endl;
                        system("pause");
                        continue;
                    }

                    abs->personArray[abs->m_Size].m_Sex = sex; //保存性别
                    cout << endl;
                    break;
                }
            }
           
            //年龄
            string age0; //定义初始字符串年龄变量 方便检测输入是否合法
            int age; //定义最终检测合格的年龄变量
            while (true) //重新输入循环体
            {
                cout << "请输入联系人年龄(整数):" << endl;
                cin >> age0;
                if (CheckNum(age0) == 0) //检测是否合法
                {
                    cout << "输入非法  请重新输入" << endl << endl;
                    continue;
                }
                else
                {
                    age = atoi(age0.c_str()); //为最终年龄变量赋值
                    abs->personArray[abs->m_Size].m_Age = age; //保存年龄
                    cout << endl;
                    break;
                }
            }

            //电话
            string phone;
            cout << "请输入联系人电话:" << endl;
            cin >> phone;
            abs->personArray[abs->m_Size].m_Phone = phone; //保存电话
            cout << endl;

            //地址
            string address;
            cout << "请输入联系人地址:" << endl;
            cin >> address;
            abs->personArray[abs->m_Size].m_Address = address; //保存地址
            cout << endl;

            //更新通讯录人数
            abs->m_Size++;

            //成功提示
            cout << "添加成功" << endl;
            cout << "你添加的联系人信息为:" << endl;
            cout << "姓名: " << name << '\t' << "性别: " << (sex == 1 ? "男" : "女") << '\t' << "年龄: " << age << '\t'
                 << "电话: " << phone << '\t' << "地址: " << address << endl << endl;
        }
        //等待并清屏
        system("pause");
        system("cls");
    }

    //2.显示所有联系人函数定义
    void showPerson(Addressbooks * abs)
    {
        //提示进入函数
        cout << "显示所有联系人:" << endl << endl;
        
        //判断通讯录中是否为0
        if (abs->m_Size == 0)
        {
            cout << "当前通讯录为空" << endl << endl;
        }
        else
        {
            for (int i = 0; i < abs->m_Size; i++) //遍历并显示联系人信息
            {
                cout << "姓名: " << abs->personArray[i].m_Name << '\t';
                cout << "性别: " << (abs->personArray[i].m_Sex == 1 ?"男":"女") << '\t';
                cout << "年龄: " << abs->personArray[i].m_Age << '\t';
                cout << "电话: " << abs->personArray[i].m_Phone << '\t';
                cout << "地址: " << abs->personArray[i].m_Address << endl;
            }
            cout << endl;
        }
        //等待并清屏
        system("pause");
        system("cls");
    }

    //3.删除指定联系人函数定义
    void deletePerson(Addressbooks * abs)
    {
        //提示进入函数
        cout << "删除指定联系人:" << endl << endl;
        cout << "请输入要删除的联系人姓名" << endl;
        string name; //定义接受名字变量
        cin >> name; //输入接受名字变量
        
        int ret = isExist (abs, name); //调用检测函数并接受结果

        if (ret != -1) //检测成功
        {
            for (int i = ret; i < abs->m_Size; i++)
            {
                //数据前移  进行覆盖删除
                abs->personArray[i] = abs->personArray[i + 1];
            }
            (abs->m_Size)--; //更新通讯录联系人总数
            cout << "删除成功" << endl << endl;
        }
        else //检测失败
        {
            cout << "查无此人" << endl << endl;
        }
        //等待并清屏
        system("pause");
        system("cls");
    }

    //4.查找指定联系人函数定义
    void findPerson(Addressbooks * abs)
    {
        //提示进入函数
        cout << "查找指定联系人:" << endl << endl;
        cout << "请输入要查找的联系人姓名" << endl;
        string name; //定义接受名字变量
        cin >> name; //输入接受名字变量

        int ret = isExist(abs, name); //调用检测函数并接受结果

        if (ret != -1) //检测成功
        {
            cout << endl;
            cout << "你查找的联系人信息为: " << endl;
            cout << "姓名: " << abs->personArray[ret].m_Name << '\t';
            cout << "性别: " << (abs->personArray[ret].m_Sex == 1 ?"男":"女") << '\t';
            cout << "年龄: " << abs->personArray[ret].m_Age << '\t';
            cout << "电话: " << abs->personArray[ret].m_Phone << '\t';
            cout << "地址: " << abs->personArray[ret].m_Address << endl << endl;
        }
        else //检测失败
        {
            cout << "查无此人" << endl << endl;
        }
        //等待并清屏
        system("pause");
        system("cls");
    }

    //5.修改指定联系人函数定义
    void modifyPerson(Addressbooks * abs)
    {
        //提示进入函数
        cout << "修改指定联系人:" << endl << endl;
        cout << "请输入要修改的联系人姓名" << endl;
        string name; //定义接受名字变量
        cin >> name; //输入接受名字变量

        int ret = isExist(abs, name); //调用检测函数并接受结果

        if (ret != -1) //检测成功
        {
            //原信息提示
            cout << endl;
            cout << "将要修改的联系人原始信息为: " << endl;
            cout << "姓名: " << abs->personArray[ret].m_Name << '\t';
            cout << "性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << '\t';
            cout << "年龄: " << abs->personArray[ret].m_Age << '\t';
            cout << "电话: " << abs->personArray[ret].m_Phone << '\t';
            cout << "地址: " << abs->personArray[ret].m_Address << endl << endl;


            //修改条目选择

            //定义用户修改变量
            string modify0; //定义为字符串 方便检测输入是否合法
            int modify; //定义最终检测合格的选择变量

            //修改菜单显示
            cout << "请输入要修改的项目编号" << endl;
            cout << "-------1.姓名-------" << endl;
            cout << "-------2.性别-------" << endl;
            cout << "-------3.年龄-------" << endl;
            cout << "-------4.电话-------" << endl;
            cout << "-------5.地址-------" << endl;
            cout << "-------0.退出-------" << endl << endl;


            //重新输入循环体
            while (true)
            {
                cout << "项目编号: ";
                cin >> modify0;

                //是否合法输入的检测
                if (CheckNum(modify0) == 0)
                {
                    cout << "输入非法  请重新输入" << endl;
                    continue;
                }
                else
                {
                    modify = atoi(modify0.c_str()); //为最终选择变量赋值
                }

                if (modify < 0 || modify > 5) //数值范围限定
                {
                    cout << "输入非法  请重新输入" << endl;
                    system("pause");
                    continue;
                }

                //检测并执行修改条目
                switch (modify)
                {
                case 1: //姓名
                    {
                    string name; //定义姓名变量
                    cout << "请输入联系人姓名:" << endl;
                    cin >> name;

                    //判断是否出现重名现象
                    int ret_0 = isExist(abs, name);
                    if (ret_0 != -1) //重名
                    {
                        cout << "联系人出现重名不合法  请尝试作区分后再添加" << endl << endl;

                        //等待并清屏
                        system("pause");
                        system("cls");
                        return; //终止函数
                    }
                    else //不重名
                    {
                        abs->personArray[ret].m_Name = name; //保存姓名
                        cout << "修改成功" << endl;
                        cout << endl;
                    }
                    break;
                    }

                case 2: //性别
                    {
                    string sex0; //定义初始字符串性别变量 方便检测输入是否合法
                    int sex; //定义最终检测合格的性别变量
                    while (true) //重新输入循环体
                    {
                        cout << "请输入联系人性别:" << endl;
                        cout << "1 --- 男    2 --- 女" << endl;
                        cin >> sex0;
                        if (CheckNum(sex0) == 0) //检测是否合法
                        {
                            cout << "输入非法  请重新输入" << endl << endl;
                            continue;
                        }
                        else
                        {
                            sex = atoi(sex0.c_str()); //为最终性别变量赋值

                            if (sex < 1 || sex > 2) //数值范围限定
                            {
                                cout << "输入非法  请重新输入" << endl;
                                system("pause");
                                continue;
                            }

                            abs->personArray[ret].m_Sex = sex; //保存性别
                            cout << "修改成功" << endl;
                            cout << endl;
                            break;
                        }
                    }
                    break;
                    }

                case 3: //年龄
                    {
                    string age0; //定义初始字符串年龄变量 方便检测输入是否合法
                    int age; //定义最终检测合格的年龄变量
                    while (true) //重新输入循环体
                    {
                        cout << "请输入联系人年龄(整数):" << endl;
                        cin >> age0;
                        if (CheckNum(age0) == 0) //检测是否合法
                        {
                            cout << "输入非法  请重新输入" << endl << endl;
                            continue;
                        }
                        else
                        {
                            age = atoi(age0.c_str()); //为最终年龄变量赋值
                            abs->personArray[ret].m_Age = age; //保存年龄
                            cout << "修改成功" << endl;
                            cout << endl;
                            break;
                        }
                    }
                    break;
                    }

                case 4: //电话
                    {
                    string phone;
                    cout << "请输入联系人电话:" << endl;
                    cin >> phone;
                    abs->personArray[ret].m_Phone = phone; //保存电话
                    cout << "修改成功" << endl;
                    cout << endl;
                    break;
                    }

                case 5: //地址
                    {
                    string address;
                    cout << "请输入联系人地址:" << endl;
                    cin >> address;
                    abs->personArray[ret].m_Address = address; //保存地址
                    cout << "修改成功" << endl;
                    cout << endl;
                    break;
                    }

                case 0: //退出
                    cout << "成功退出修改" << endl << endl;
                    system("pause");
                    system("cls");
                    return;
                    break;
                
                default: //其他
                    break;
                }
            }
        }
        else //检测失败
        {
            cout << "查无此人" << endl << endl;
        }
              
        //等待并清屏
        system("pause");
        system("cls");
    }

    //6.清空所有联系人函数定义
    void cleanPerson(Addressbooks* abs)
    {
        //提示进入函数
        cout << "清空所有联系人:" << endl << endl;
        cout << "确定要清空所有联系人吗  此项操作不可撤销" << endl;
        cout << "1 --- 确定   2 --- 取消" << endl;
        
        //定义用户清空变量
        string clean0 ; //定义为字符串 方便检测输入是否合法
        int clean; //定义最终检测合格的选择变量

        //重新选择循环体
        while (true)
        {
            //用户输入选择变量
            cin >> clean0;

            //选择变量是否合法的检测
            if (CheckNum(clean0) == 0)
            {
                cout << "输入非法  请重新输入" << endl;
                system("pause");
                continue;
            }
            else
            {
                clean = atoi(clean0.c_str()); //为最终选择变量赋值
                
                if (clean < 1 || clean > 2) //数值范围限定
                {
                    cout << "输入非法  请重新输入" << endl;
                    system("pause");
                    continue;
                }

                if (clean == 1)
                {
                    abs->m_Size = 0; //将人数记为0  实现逻辑清空
                    cout << "通讯录已清空" << endl<< endl;
                }
                else if (clean == 2)
                {
                    cout << "已取消清空" << endl<< endl;
                }
                else
                {
                    continue;
                }
                system("pause");
                system("cls");
                return;
            }
        }
    }

//主程序入口
int main()
{
    //定义通讯录结构体变量
    Addressbooks abs;

    //初始化通讯录人数变量
    abs.m_Size = 0;

    //定义用户选择变量
    string select0 ; //定义为字符串 方便检测输入是否合法
    int select; //定义最终检测合格的选择变量

    //循环体 循环菜单选择
    while (true)
    {
        //显示菜单
        showMenu();

        //用户输入选择变量
        cin >> select0;

        //选择变量是否合法的检测
        if (CheckNum(select0) == 0)
        {
            cout << "输入非法  请重新输入" << endl;
            system("pause");
            system("cls");
            continue;
        }
        else
        {
            select = atoi(select0.c_str()); //为最终选择变量赋值
        }

        if (select < 0 || select > 6) //数值范围限定
        {
            cout << "输入非法  请重新输入" << endl;
            system("pause");
            system("cls");
            continue;
        }

        //检测选择变量并执行
        switch (select)
        {
        case 1: //添加指定联系人
            addPerson(&abs);
            break;

        case 2: //显示所有联系人
            showPerson(&abs);
            break;

        case 3: //删除指定联系人
            deletePerson(&abs);
            break;

        case 4: //查找指定联系人
            findPerson(&abs);
            break;

        case 5: //修改指定联系人
            modifyPerson(&abs);
            break;

        case 6: //清空所有联系人
            cleanPerson(&abs);
            break;

        case 0: //退出通讯录系统
            cout << "欢迎下次使用" << endl << endl;
            system("pause");
            return 0;
            break;

        default: //其余情况
            cout << "出错";
            break;
        }
    }
    
    //暂停程序
    system("pause");

    //返回值
    return 0;
}