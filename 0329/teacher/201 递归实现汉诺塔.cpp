// 递归实现汉诺塔程序 
#include <iostream> 
using namespace std;
void move(char, char);
long steps=0;//记录移动的步数 
void hannuo(char A, char B, char C, int n){//将n个盘子从A针，借助B针，放到C针上 
	if(n==1)
		move(A, C);
	else{
		hannuo(A, C, B, n-1);// 先将n-1个盘子从A针，借助C针，放到B针上 
		move(A, C);//将第n个盘子从A针移动到C针上 
		hannuo(B, A, C, n-1);// 然后将n-1个盘子从B针，借助A针，放到C针上 
	}
} 

void move(char A, char B){//从A针移动一个盘子到B针上 
	cout<<"move "<<A<<" to "<<B<<endl;
	steps++; 
}
int main(){
	int n;
	cout<<"Please input the num of Disks:";
	cin>>n;
	hannuo('A', 'B', 'C', n);
	cout<<n<<"个盘子的汉诺塔，需要"<<steps<<"步可以完成。"<<endl; 
} 
