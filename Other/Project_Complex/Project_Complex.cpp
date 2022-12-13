#include<iostream>
using namespace std;

class Complex 
{
public:
	Complex()
	{
		this->real = 0;
		this->image = 0;
	}

	Complex(double t_real, double t_image)
	{
		this->real = t_real;
		this->image = t_image;
	}

	double real;
	double image;

	void displayComplex()
	{
		cout << "Real : " << this->real << "  Image : " << this->image << endl;
	}

	friend Complex operator + (Complex A, Complex B)
	{
		return Complex(A.real + B.real, A.image + B.image);
	}
	friend Complex operator - (Complex A, Complex B)
	{
		return Complex(A.real - B.real, A.image - B.image);
	}
	friend Complex operator ++ (Complex& A)
	{
		return Complex(++A.real, A.image);
	}
	friend Complex operator ++ (Complex& A,int)
	{
		return Complex(A.real++, A.image);
	}

};

int main()
{
	Complex A(1, 1), B(2, 2),C,D;
	C = A + B;
	C.displayComplex();
	D = A - B;
	D.displayComplex();
	A++;
	A.displayComplex();
	++A;
	A.displayComplex();
	return 0;
}