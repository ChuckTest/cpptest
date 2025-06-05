#include<iostream>
using namespace std;
class Clock	//ʱ��������
{
  public:	//�ⲿ�ӿ�
	  Clock(int NewH=0, int NewM=0, int NewS=0){Hour=NewH; Minute=NewM; Second=NewS;};
	  void ShowTime();
	  Clock operator ++();  //ǰ�õ�Ŀ���������
	  Clock operator ++(int);  //���õ�Ŀ���������
  private:	//˽�����ݳ�Ա
	  int Hour,Minute,Second;
};
Clock Clock::operator ++()	//ǰ�õ�Ŀ��������غ���
{	Second++;
	if(Second>=60)
	{   Second=Second-60;
	     Minute++;
	     if(Minute>=60)
	     {
	          Minute=Minute-60;
	          Hour++;
	          Hour=Hour%24;
	     }
	}
    return *this;
}
//���õ�Ŀ���������
Clock Clock::operator ++(int)	
{		//ע���βα��е����Ͳ���
   Clock old=*this;
   ++(*this);
   return old;
}
void Clock::ShowTime(){
	cout<<"Now Time is "<<Hour<<":"<<Minute<<":"<<Second<<endl;
}

void main()
{
	Clock myClock(23,59,59);
	cout<<"First time output:";
	myClock.ShowTime();
	cout<<"Show myClock++:";
	(myClock++).ShowTime();
	cout<<"Show ++myClock:";
	(++myClock).ShowTime();
}
