#include <iostream>
using namespace std;
void main()
{	int array2[2][3]={{11,12,13},{21,22,23}};
    for(int i=0;i<2;i++)
    {  cout<<*(array2+i)<<endl;	
	    for(int j=0;j<3;j++)
        {  cout<<*(*(array2+i)+j)<<" ";   
           //Лђеп cout<<array2[i][j]<<" ";
        }	
	    cout<<endl;
	}
}
