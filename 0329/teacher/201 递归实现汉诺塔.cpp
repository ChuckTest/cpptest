// �ݹ�ʵ�ֺ�ŵ������ 
#include <iostream> 
using namespace std;
void move(char, char);
long steps=0;//��¼�ƶ��Ĳ��� 
void hannuo(char A, char B, char C, int n){//��n�����Ӵ�A�룬����B�룬�ŵ�C���� 
	if(n==1)
		move(A, C);
	else{
		hannuo(A, C, B, n-1);// �Ƚ�n-1�����Ӵ�A�룬����C�룬�ŵ�B���� 
		move(A, C);//����n�����Ӵ�A���ƶ���C���� 
		hannuo(B, A, C, n-1);// Ȼ��n-1�����Ӵ�B�룬����A�룬�ŵ�C���� 
	}
} 

void move(char A, char B){//��A���ƶ�һ�����ӵ�B���� 
	cout<<"move "<<A<<" to "<<B<<endl;
	steps++; 
}
int main(){
	int n;
	cout<<"Please input the num of Disks:";
	cin>>n;
	hannuo('A', 'B', 'C', n);
	cout<<n<<"�����ӵĺ�ŵ������Ҫ"<<steps<<"��������ɡ�"<<endl; 
} 
