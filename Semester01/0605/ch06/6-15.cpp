#include<iostream>
using namespace std;
class Point
{ public:
    Point()
    { X=Y=0; cout<<"Default Constructor called.\n";}
    Point(int xx,int yy)
    {   X=xx; Y=yy; cout<< "Constructor called.\n";  }
    ~Point() {   cout<<"Destructor called.\n";    }
    int GetX() {return X;}
    int GetY() {return Y;}
	void Move(int x,int y)	{  X=x;  Y=y;   }
  private:
       int  X,Y;
};
int main()
{   cout<<"Step One:"<<endl;
     Point *Ptr1=new Point;
     delete  Ptr1;   
     cout<<"Step Two:"<<endl;
     Ptr1=new Point(1,2);
     delete Ptr1;
     return 0;
}
