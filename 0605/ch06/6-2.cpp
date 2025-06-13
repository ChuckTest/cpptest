#include <iostream>
using namespace std;
void RowSum(int A[][4], int nrow)
{
	int sum;
	for (int i = 0; i < nrow; i++)
	{
		sum = 0;
		for (int j = 0; j < 4; j++)
			sum += A[i][j];
		cout << "Sum of row " << i << " is " << sum << endl;
		A[i][0] = sum;
	}
}
int main(void)
{
	int Table[3][4] = {{1, 2, 3, 4}, {2, 3, 4, 5}, {3, 4, 5, 6}};
	int i;
	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << Table[i][j] << "   ";
		cout << endl;
	}
	RowSum(Table, 3);

	for (i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
			cout << Table[i][j] << "   ";
		cout << endl;
	}

	for (i = 0; i < 3; i++)
		cout << Table[i][0] << "   ";
	cout << endl;
	return 0;
}
