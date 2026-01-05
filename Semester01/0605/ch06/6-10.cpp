#include <iostream>
#include <iomanip>
using namespace std;
void Array_Ptr(long *P, int n)
{	int i;
	cout << "In func, address of array is "<< unsigned long(P) << endl;
	cout << "Accessing array in the function using pointers" << endl;
	for (i = 0; i < n; i++)
	{	
		cout << "  Address for index " << i << " is "<< unsigned long(P+i);
		cout << "  Value is " << *(P+i)  << endl;
	}
}
void main(void)
{
	long list[5] = {50, 60, 70, 80, 90};
	
	cout << "In main, address of array is " << unsigned long(list) << endl;
	cout << endl;
	 
	Array_Ptr(list,5);
}
