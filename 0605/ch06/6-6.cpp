#include <iostream>
using namespace std;

void main()
{
	int a[10];
	int i;
	//输入10个数据初始化数组
	cout<<"请输入10个数字来初始化数组"<<endl;
	for(i=0; i<10; i++)
		cin>>a[i];
	cout<<endl;
	cout<<"使用数组名和下标:"<<endl;
	for(i=0; i<10; i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	cout<<"使用数组名和指针运算:"<<endl;
	for(i=0; i<10; i++)
		cout<<*(a+i)<<"  ";
	cout<<endl;
	cout<<"使用指针变量(方法1):"<<endl;
	int * pa=a;
	for(i=0; i<10; i++)
		cout<<*(pa+i)<<"  ";
	cout<<endl;
	cout<<"使用指针变量(方法2):"<<endl;
	
	for(pa=a; pa<(a+10);pa++)
		cout<<*pa<<"  ";
	cout<<endl;
}
