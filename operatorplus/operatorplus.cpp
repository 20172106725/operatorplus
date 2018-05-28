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
	void setvalue(int ft, int in);
	void display();
	CFeet add(CFeet & objf);
	CFeet operator -(CFeet & objf);
};
void CFeet::setvalue(int ft, int in)
{
	feet = ft + in / 12;
	inches = in % 12;
}
void CFeet::display()
{
	cout << feet << "英尺" << inches << "英寸" << endl;
};
/*CFeet CFeet::add(CFeet & objf)
{
	if (inches > objf.inches)
	{
		CFeet temp;
		temp.setvalue(feet - objf.feet, inches - objf.inches);
		return temp;
	}
	else
	{
		CFeet temp;
		temp.setvalue(feet - objf.feet, objf.inches - inches);
		return temp;
	}
}*/
CFeet CFeet :: operator - (CFeet & objf)
{
	if (feet > objf.feet)
	{
		if (inches > objf.inches)
		{
			CFeet temp;
			temp.setvalue(feet - objf.feet, inches - objf.inches);
			return temp;
		}
		else
		{
			CFeet temp;
			temp.setvalue(feet - objf.feet, objf.inches-inches);
			return temp;

		}
	}
	else
	{
		inches = inches + (feet * 12);
		objf.inches = objf.inches + (objf.feet * 12);
		if (inches > objf.inches)
		{
			CFeet temp;
			temp.setvalue(0, inches - objf.inches);
			return temp;
		}
		else
		{
			inches = inches + (feet * 12);
			CFeet temp;
			temp.setvalue(0, objf.inches - inches);
			return temp;
		}
	}
}
int main()
{
	CFeet A, B, C;
	A.setvalue(1, 3);
	B.setvalue(2, 2);
	C = A - B;
	C.display();
	return 0;
}
