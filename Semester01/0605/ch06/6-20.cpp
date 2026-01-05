#include<iostream>
using namespace std;
void main()
{  static char diamond[][5]={{' ',' ','*'},
                    {' ','*',' ','*'}, {'*',' ',' ',' ','*'},
                    {' ','*',' ','*'}, {' ',' ','*'}};
	int i,j;
	for (i=0;i<5;i++) 
	{  for(j=0;j<5 && diamond[i][j]!=0;j++)
		cout<<diamond[i][j];  
	    cout<<endl;
	}
}
