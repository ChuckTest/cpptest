#include <iostream>
using namespace std;
void  splitfloat(float x, int *intpart, float *fracpart)
{  //�β�intpart�� fracpart��ָ��
    *intpart = int(x);	// ȡx����������
    *fracpart = x - *intpart; //ȡx��С������
}
void main(void)
{
	int i, n;
	float x, f;
		
	cout << "Enter three (3) floating point numbers"<< endl;
	for (i = 0; i < 3; i++)
	{
		cin >> x;
		splitfloat(x,&n,&f);       //������ַ��ʵ��
		cout << "Integer Part is " << n << "   Fraction Part is " << f << endl;
	}
}
