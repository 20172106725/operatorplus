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
	//CFeet add(CFeet & objf);
	CFeet operator+(CFeet & objf);
};
void CFeet::setvalue(int ft, int in)
{
	feet = ft+in/12;
	inches = in%12;
}
void CFeet::display()
{
	cout << feet << "英尺" << inches << "英寸" << endl;
}
/*{
	if (inches < 0)
	{
		cout << inches / 12 << "英尺" << -inches % 12 << "英寸" << endl;
	}
	if (inches > 0)
	{
		cout << inches / 12 << "英尺" << inches % 12 << "英寸" << endl;
	}
}
/*CFeet CFeet::add(CFeet & objf)  //objf是对象引用b
{
CFeet temp;
temp.setvalue(feet + objf.feet, inches + objf.inches);
return temp;
}*/
CFeet CFeet::operator+(CFeet & objf)
{
	CFeet temp;
	if (feet > 0)
	{
		temp.setvalue(0, inches = (feet * 12 + inches) - (objf.feet * 12 + objf.inches));
	}
	else
	{
		temp.setvalue(0, inches = (feet * 12 - inches) - (objf.feet * 12 + objf.inches));
	}
	return temp;
}
int main()
{
	CFeet A, B, C;
	A.setvalue(-2, 3);
	B.setvalue(2, 3);
	C = A + B; //有CFeet CFeet::operator+(CFeet & objf)的时候能用c=a+b ，有CFeet CFeet::add(CFeet & objf)时用c=a.add(b)
	C.display();
	return 0;
}
