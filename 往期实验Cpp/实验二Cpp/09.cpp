#include <iostream>
using namespace std;

int main()
{
    int i;
    int day = 0;//天数
    double average;//平均每天的花费
    double sum = 0;//总费用
    for (i = 2; i <= 100; i *= 2)
    {
        sum = sum + i * 0.8;
        day++;
    }
    average = sum / day;
    cout << "每天平均花费 " << average << "元钱" << endl;
    system("pause");
    return 0;
}
