#include<iostream>
using namespace std;
#include "5-point.cpp"
void main(){
	Point p1(3,4);
	p1.Display();
	p1.Move(5,6);
	p1.Display();
	Point p2(p1);
	p2.Display();
}
