#include<iostream>
using namespace std;
class Clock
{
public:
	void SetTime(int NewH=0, int NewM=0, int NewS=0);
	void ShowTime();
private: 
    int Hour, Minute, Second;
};
void Clock :: SetTime(int NewH, int NewM, int NewS)
{
	Hour=NewH;
	Minute=NewM;
	Second=NewS;
}
void Clock :: ShowTime()
{
	cout<<"当前时间为：";
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

void main(void)
{    
	Clock  myClock;
	int H,M,S;
	cout<<"输出默认时间"<<endl;
	myClock.SetTime();
    myClock.ShowTime();
	cout<<"请设定时间"<<endl;
	cin>>H>>M>>S;
    myClock.SetTime(H,M,S);
	myClock.ShowTime();

}
