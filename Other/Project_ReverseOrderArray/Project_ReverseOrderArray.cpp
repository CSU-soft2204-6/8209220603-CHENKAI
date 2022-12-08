#include<iostream>
using namespace std;

void Compare(int a, int b, int& m)
{
    if (a > b)
    {
        m = -1;
    }
    else if (a < b)
    {
        m = 1;
    }
    else
    {
        return;
    }
}

char Test()
{
    int Num = 0;
    cin >> Num;

    int* p = new int[Num];

    for (int i = 0; i < Num; ++i)
    {
        cin >> (*(p + i));
    }

    int test = 0, mark0 = 0, mark = 0;

    if (Num <= 4)
    {
        return 'Y';
    }

    for (int j = 0; j < (Num - 2); ++j)
    {
        Compare(*(p + j), *(p + j + 1), mark0);
        Compare(*(p + j + 1), *(p + j + 2), mark);
        if (mark0 == 0 || mark == 0)
        {
            continue;
        }
        if (mark != mark0)
        {
            test++;
        }
    }

    if (test >= 3)
    {
        return 'N';
    }
    else if (test <= 1)
    {
        return 'Y';
    }
    else if (test == 2)
    {
        int up = 0, down = 0, same = 0;
        for (int j = 0; j < (Num - 1); ++j)
        {
            if (*(p + j) > *(p + j + 1))
            {
                down++;
            }
            else if (*(p + j) < *(p + j + 1))
            {
                up++;
            }
            else
            {
                same++;
            }
        }
        if (up == 1 || down == 1)
        {
            return 'Y';
        }
        else
        {
            return 'N';
        }
    }
}

void main()
{
    char h = Test();
    if (h == 'N')
    {
        cout << "No" << endl;
    }
    else if (h == 'Y')
    {
        cout << "Yes" << endl;
    }
    system("pause");
}
