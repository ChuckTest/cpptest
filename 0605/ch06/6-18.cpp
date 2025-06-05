#include<iostream>
using namespace std;
void main()
{	float (*cp)[3][4];
	int i,j,k;
	cp = new float[2][3][4];
	for (i=0; i<2; i++)
		for (j=0; j<3; j++)
			for (k=0; k<4; k++)
			    *(*(*(cp+i)+j)+k)=i*100+j*10+k; 
                                        //通过指针访问数组元素
for (i=0; i<2; i++)
	{	for (j=0; j<3; j++)
		{      for (k=0; k<4; k++)
			 //将指针cp作为数组名使用，
                       //通过数组名和下标访问数组元素
                      cout<<cp[i][j][k]<<"  ";  
			cout<<endl;
		}
		cout<<endl;
	}
}
