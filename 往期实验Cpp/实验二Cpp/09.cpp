#include <iostream>
using namespace std;

int main()
{
    int i;
    int day = 0;//����
    double average;//ƽ��ÿ��Ļ���
    double sum = 0;//�ܷ���
    for (i = 2; i <= 100; i *= 2)
    {
        sum = sum + i * 0.8;
        day++;
    }
    average = sum / day;
    cout << "ÿ��ƽ������ " << average << "ԪǮ" << endl;
    system("pause");
    return 0;
}
