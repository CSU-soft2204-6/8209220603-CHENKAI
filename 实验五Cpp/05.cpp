#include<iostream>
#include<vector>
using namespace std;

void print_Vector(vector<string>& v)  //vector��ӡ(string)
{
	if (v.size() != 0)  //��Ϊ��
	{
		cout << "{ ";
		for (vector<string>::iterator it = v.begin(); it != v.end(); it++)
		{
			cout << (*it) << " ";
		}
		cout << "}" << endl;
	}
	else
	{
		cout << "{ }" << endl;  //��Ϊ�մ�ӡ��
	}
}

template<typename T>
vector<T> intersection(const vector<T>& v1, const vector<T>& v2)
{
	vector<T>v; 
	bool is = false;                       
	for (int i = 0; i < v1.size(); i++)
	{
		for (int j = 0; j < v2.size(); j++)
		{
			if (v1.at(i) == v2.at(j))
			{
				if (v.size() != 0)     //д��v
				{
					for (int m = 0; m < v.size(); m++)
					{
						if (v1.at(i) == v.at(m))  //�ظ��ж�
						{
							break;
						}
						else
						{
							v.push_back(v1.at(i));
						}

					}
				}
				else
				{
					v.push_back(v1.at(i));
				}
			}
		}
	}
		return v;
}

int main()
{
	cout << "�������һ������������: ";
	vector<string>v1;
	for (int i = 0; i < 5; i++)
	{
		string complex;
		cin >> complex;
		v1.push_back(complex);
	}

	cout << "������ڶ�������������:" ;
	vector<string>v2;
	for (int j = 0; j < 5; j++)
	{
		string complex;
		cin >> complex;
		v2.push_back(complex);
	}

	vector<string>v = intersection(v1, v2);
	cout << "v1��v2�Ľ���Ϊ:";
	print_Vector(v);

	system("pause");
	return 0;
}