#include <iostream>
using namespace std;
int main()
{
  int x=9,y=9;
 	  for(y=9;y>=1;y--) 
	  { 
		for (;x>=1;x--){  //此处（）内不声明i，空着也是正确的。
		cout <<y<<"*"<<x<<"="<<x*y<<"\t";
	  }
	  cout<<endl;
  }
  return 0;
}