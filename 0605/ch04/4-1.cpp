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
	cout<<"��ǰʱ��Ϊ��";
    cout<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

void main(void)
{    
	Clock  myClock;
	int H,M,S;
	cout<<"���Ĭ��ʱ��"<<endl;
	myClock.SetTime();
    myClock.ShowTime();
	cout<<"���趨ʱ��"<<endl;
	cin>>H>>M>>S;
    myClock.SetTime(H,M,S);
	myClock.ShowTime();

}
