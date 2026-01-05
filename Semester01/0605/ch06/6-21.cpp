#include <iostream>
using namespace std;
void main (void)
{	char city[80];
	char state[80];
	int  i;
	for (i = 0; i < 2; i++)
	{ cin.getline(city,80,',');
	  cin.getline(state,80,'\n');
	  cout << "City: " << city << "   State: "<< state << endl;
	}
}
