#include <iostream>
using namespace std;

void main()
{
	int a[10];
	int i;
	//����10�����ݳ�ʼ������
	cout<<"������10����������ʼ������"<<endl;
	for(i=0; i<10; i++)
		cin>>a[i];
	cout<<endl;
	cout<<"ʹ�����������±�:"<<endl;
	for(i=0; i<10; i++)
		cout<<a[i]<<"  ";
	cout<<endl;
	cout<<"ʹ����������ָ������:"<<endl;
	for(i=0; i<10; i++)
		cout<<*(a+i)<<"  ";
	cout<<endl;
	cout<<"ʹ��ָ�����(����1):"<<endl;
	int * pa=a;
	for(i=0; i<10; i++)
		cout<<*(pa+i)<<"  ";
	cout<<endl;
	cout<<"ʹ��ָ�����(����2):"<<endl;
	
	for(pa=a; pa<(a+10);pa++)
		cout<<*pa<<"  ";
	cout<<endl;
}
