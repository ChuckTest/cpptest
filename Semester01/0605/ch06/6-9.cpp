#include <iostream>
using namespace std;
void  splitfloat(float x, int *intpart, float *fracpart)
{  //形参intpart、 fracpart是指针
    *intpart = int(x);	// 取x的整数部分
    *fracpart = x - *intpart; //取x的小数部分
}
void main(void)
{
	int i, n;
	float x, f;
		
	cout << "Enter three (3) floating point numbers"<< endl;
	for (i = 0; i < 3; i++)
	{
		cin >> x;
		splitfloat(x,&n,&f);       //变量地址做实参
		cout << "Integer Part is " << n << "   Fraction Part is " << f << endl;
	}
}
