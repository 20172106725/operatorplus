// operatorplus.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CFeet
{
private:
	int feet;
	int inches;
public:
	void setvalue(int fe, int in);
	void display();
	//CFeet add(CFeet & objf);
	CFeet operator-(CFeet & objf);
};
void CFeet::setvalue(int fe, int in)
{
	feet = fe;
	inches = in;
}
void CFeet::display()
{
	cout << feet << "英尺" << inches << "英寸" << endl;
}
CFeet CFeet::operator-(CFeet &objf)
{
	CFeet temp;
	if (feet > 0)
	{
		temp.setvalue(inches = feet * 12 + inches, objf.inches = objf.feet * 12 + objf.inches);
		if (inches < objf.inches)
		{
			temp.inches = (inches - objf.inches) % 12;
			if (temp.inches < 0)
			{
				temp.inches = inches*(-1);
			}
		}
		else
		{
			temp.inches = (inches - objf.inches) % 12;
			if (temp.inches < 0)
			{
				temp.inches = inches*(-1);
			}
		}

		temp.feet = (inches - objf.inches) / 12;
	}
	if (feet < 0)
	{
		temp.setvalue(inches = feet * 12 - inches, objf.inches = objf.feet * 12 + objf.inches);
		temp.inches = (inches - objf.inches) % 12 * (-1);
	}
	temp.feet = (inches - objf.inches) / 12;
	return temp;
}
int main()
{
	CFeet A, B, C;
	A.setvalue(-3, 2);
	B.setvalue(1, 5);
	C = A - B;
	C.display();
	return 0;
}

