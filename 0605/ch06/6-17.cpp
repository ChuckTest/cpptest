﻿#include<iostream>
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
class ArrayOfPoints
{   public:
     ArrayOfPoints(int n)
     {   numberOfPoints=n;  points=new Point[n];  }
     ~ArrayOfPoints()
     {   cout<<"Deleting..."<<endl;
         numberOfPoints=0;  delete[] points;     
      }
     Point& Element(int n)
     {  return points[n];  }
   private:
     Point *points;
     int numberOfPoints;
};

void main()
{
	int number;
	cout<<"Please enter the number of points:";
	cin>>number;
    //创建对象数组
    ArrayOfPoints points(number);    
    //通过指针访问数组元素的成员
    points.Element(0).Move(5,10); 
    //通过指针访问数组元素的成员
    points.Element(1).Move(15,20);   
}
