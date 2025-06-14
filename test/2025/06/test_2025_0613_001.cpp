#include <iostream>
using namespace std;

int main() {
    int i = 1;
    int sum = 0;
    i++;
    for(int j = 1; j < 3; j++) {
        sum = i + j;
        ++i;
        cout << i << ", " << j << endl;
    }
    return 0;
}
