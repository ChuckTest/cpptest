#include<iostream>
#include<ctime>
#include<cmath>
using namespace std;
 
clock_t start, end;

int main() {
	int x,i,n=0;
	int num=0;
	//����ⷨ
	start=clock();
	for(x=2; x<=90000; x++) {
		n=0;
		for(i=1; i<=x; i++)
			if(x%i==0)
				n++;
		if(n==2) 
			num ++; 
	}
	cout<<"����"<<num<<"������"<<endl;
	end=clock();
	cout << "�������ʱ��Ϊ��" <<end-start<<"����"<<endl<<endl;
	
	//�Ż�1
	num=0;
	start=clock();
	for(x=2; x<=90000; x++) {
		for(i=2; i<x; i++)
			if(x%i==0)
				break;
		if(i==x)
			num ++;
	}
	cout<<"����"<<num<<"������"<<endl;
	end=clock();
	cout << "�������ʱ��Ϊ��" <<end-start<<"����"<<endl<<endl;
	
	//�Ż�2
	num=0;
	start=clock();
	for(x=2; x<=90000; x++) {
		n=0;
		for(i=2; i<=x/2; i++)
			if(x%i==0){
				n++;
				break;
			}
		if(n==0) 
			num ++;
	}
	cout<<"����"<<num<<"������"<<endl;
	end=clock();
	cout << "�������ʱ��Ϊ��" <<end-start<<"����"<<endl<<endl;
	
	//�Ż�3
	num=0;
	start=clock(); 
	for(x=2; x<=90000; x++) {
		n=0;
		for(i=2; i<=sqrt(x); i++)
			if(x%i==0){
				n++;
				break;
			}
		if(n==0)
			num ++;
	}
	cout<<"����"<<num<<"������"<<endl;
	end=clock();
	cout << "�������ʱ��Ϊ��" <<end-start<<"����"<<endl<<endl;
	
	return 0;
}
