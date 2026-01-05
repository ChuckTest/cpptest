// Recursive implementation of the Tower of Hanoi problem
#include <iostream>
using namespace std;

void move(char, char);
long steps = 0; // Count the number of steps

void hannuo(char A, char B, char C, int n) { // Move n disks from pole A to pole C using pole B as auxiliary
    if (n == 1)
        move(A, C);
    else {
        hannuo(A, C, B, n - 1); // First, move n-1 disks from A to B using C as auxiliary
        move(A, C); // Move the nth disk from A to C
        hannuo(B, A, C, n - 1); // Then, move n-1 disks from B to C using A as auxiliary
    }
}

void move(char A, char B) { // Move one disk from A to B
    cout << "Move " << A << " to " << B << endl;
    steps++;
}

int main() {
    int n;
    cout << "Please input the number of disks: ";
    cin >> n;
    hannuo('A', 'B', 'C', n);
    cout << "For " << n << " disks in the Tower of Hanoi, it takes " << steps << " steps to complete." << endl;
}
