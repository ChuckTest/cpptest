#include <iostream>
using namespace std;
int main()
{
	int A[5], B[5];
	// int C[]={1,2,3,4,5};
	int i;
	for (i = 0; i < 5; i++)
	{
		A[i] = i * 2 + 1;
		B[5 - i - 1] = A[i];
	}
	for (i = 0; i < 5; i++)
	{
		cout << "A[" << i << "]=" << A[i];
		cout << " B[" << i << "]=" << B[i] << endl;
	}
	/*for(i=0;i<5;i++)
		cout<<"C["<<i<<"]="<<C[i]<<" "; */
	cout << endl;
	return 0;
}
