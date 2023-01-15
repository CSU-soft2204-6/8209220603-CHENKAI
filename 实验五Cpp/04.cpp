#include <iostream>
#include <iomanip>
using namespace std;

class Shape  //����
{
public:
	virtual double Area() = 0;
	virtual void display() = 0;
};

class Rectangle :public Shape  //����
{
public:
	double a, b;
	Rectangle(double _a, double _b)
	{
		this->a = _a;
		this->b = _b;
	}
	virtual double Area() 
	{ 
		return a * b; 
	}
	virtual void display()
	{
		cout << "���ε����Ϊ: " << this->Area() << endl;
	}
};

class Circle :public Shape  //Բ
{
public:
	double r;
	Circle(double _r)
	{
		this->r = _r;
	}
	virtual double Area() 
	{ 
		return 3.14 * r * r; 
	}
	virtual void display()
	{
		cout << "Բ�����Ϊ: " << this->Area() << endl;
	}
};

class Triangle :public Shape //����
{
public:
	double a, b ,c;
	Triangle(double _a, double _b, double _c)
	{
		this->a = _a;
		this->b = _b;
		this->c = _c;
	}
	virtual double Area() 
	{
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	virtual void display()
	{
		cout << "�����ε����Ϊ: " << this->Area() << endl;
	}
};

class Square :public Shape  //������
{
public:
	double a;
	Square(double _a)
	{
		this->a = _a;
	}
	virtual double Area() 
	{ 
		return a * a; 
	}
	virtual void display()
	{
		cout << "�����ε����Ϊ: " << this->Area() << endl;
	}
};

class Trapezoid :public Shape  //����
{
public:
	double a, b, h;
	Trapezoid(double _a, double _b, double _h)
	{
		this->a = _a;
		this->b = _b;
		this->h = _h;
	}
	virtual double Area() 
	{ 
		return (a + b) * h / 2.0; 
	}
	virtual void display()
	{
		cout << "���ε����Ϊ: " << this->Area() << endl;
	}
};

int main()
{
	Circle circle(10.2);
	Square square(3);
	Rectangle rectangle(3, 4);
	Trapezoid trapezoid(2.0, 4.5, 3);
	Triangle triangle(4, 5, 6);

	Shape* pShape[5] = { &circle,&square,&rectangle,&trapezoid,&triangle };

	double sum = 0;
	for (int i = 0; i < 5; i++)
	{
		pShape[i]->display();
		sum += pShape[i]->Area();
	}
	cout << "�����Ϊ: " << sum << endl;
	return 0;
}
