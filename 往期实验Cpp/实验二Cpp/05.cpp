#include <iostream>
using namespace std;

int main()
{
    char content;
    int letter = 0, space = 0, number = 0, elset = 0;
    cout << "请输入一行字符：" << endl;
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
    cout << "英文字母个数为：" << letter << endl;
    cout << "空格个数为：" << space << endl;
    cout << "数字个数为：" << number << endl;
    cout << "其他字符个数为：" << elset << endl;
    system("pause");
    return 0;
}