#include <iostream>
using namespace std;

class Box
{
public:

	void setValue();
	float getVolume();
	void display();

private:
	float lengh;
	float width;
	float height;
};

void Box::setValue()
{
	cout << "请输入长方体长, 宽, 高: " << endl;
	cin >> this->lengh;
	cin >> this->width;
	cin >> this->height;

}

float Box::getVolume()
{
	float volume;
	volume = lengh * width * height;
	return volume;
}

void Box::display()
{
	cout << "该长方体体积是: " << this->getVolume() << endl;
}

void main()
{
	Box box1,box2,box3;
	box1.setValue();
	box1.display();
	box2.setValue();
	box2.display();
	box3.setValue();
	box3.display();
}
