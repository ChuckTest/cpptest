#include "5-point.h"
Point::Point()
{   
	X=Y=0;
    cout<<"Default Constructor called."<<endl;
}
Point::Point(int xx,int yy)
{   
	X=xx;
    Y=yy;
    cout<< "Constructor called."<<endl;
}
Point::Point(Point & p)
{   
	X=p.X;
    Y=p.Y;
    cout<< "Copy Constructor called."<<endl;
}
void Point::Display()
{   
	cout<< "The point is ("<<X<<","<<Y<<")!"<<endl;
}
Point ::~Point()
{   
	cout<<"Destructor called."<<endl;  
}
void Point::Move(int x,int y)
{     
	X=x;    
	Y=y;  
}
