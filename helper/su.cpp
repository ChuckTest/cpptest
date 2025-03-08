
#include <iostream>
using namespace std;
int main()
{
    int x = 9, y = 9;
    for (int i = 9; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << j << " x " << i << " = " << i * j << "\t";
        }
        cout << endl;
    }
    return 0;
}