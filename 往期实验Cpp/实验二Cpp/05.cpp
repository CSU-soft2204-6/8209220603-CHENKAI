#include <iostream>
using namespace std;

int main()
{
    char content;
    int letter = 0, space = 0, number = 0, elset = 0;
    cout << "������һ���ַ���" << endl;
    while ((content = getchar()) && (content != '\n'))
    {
        if ((content >= 'a' && content <= 'z') || (content >= 'A' && content <= 'Z'))
            letter += 1;
        else if (content >= '0' && content <= '9')
            number += 1;
        else if (content == ' ')
            space += 1;
        else
            elset += 1;
    }
    cout << "Ӣ����ĸ����Ϊ��" << letter << endl;
    cout << "�ո����Ϊ��" << space << endl;
    cout << "���ָ���Ϊ��" << number << endl;
    cout << "�����ַ�����Ϊ��" << elset << endl;
    system("pause");
    return 0;
}