#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

clock_t start, endTime; // Renamed 'end' to 'endTime'

int main() {
    int x, i, n = 0;
    int num = 0;

    // Regular solution
    start = clock();
    for(x = 2; x <= 90000; x++) {
        n = 0;
        for(i = 1; i <= x; i++)
            if(x % i == 0)
                n++;
        if(n == 2)
            num++;
    }
    cout << "There are " << num << " prime numbers" << endl;
    endTime = clock();  // Renamed to 'endTime'
    cout << "The program duration is: " << endTime - start << " milliseconds" << endl << endl;

    // Optimization 1
    num = 0;
    start = clock();
    for(x = 2; x <= 90000; x++) {
        for(i = 2; i < x; i++)
            if(x % i == 0)
                break;
        if(i == x)
            num++;
    }
    cout << "There are " << num << " prime numbers" << endl;
    endTime = clock();  // Renamed to 'endTime'
    cout << "The program duration is: " << endTime - start << " milliseconds" << endl << endl;

    // Optimization 2
    num = 0;
    start = clock();
    for(x = 2; x <= 90000; x++) {
        n = 0;
        for(i = 2; i <= x / 2; i++)
            if(x % i == 0) {
                n++;
                break;
            }
        if(n == 0)
            num++;
    }
    cout << "There are " << num << " prime numbers" << endl;
    endTime = clock();  // Renamed to 'endTime'
    cout << "The program duration is: " << endTime - start << " milliseconds" << endl << endl;

    // Optimization 3
    num = 0;
    start = clock(); 
    for(x = 2; x <= 90000; x++) {
        n = 0;
        for(i = 2; i <= sqrt(x); i++)
            if(x % i == 0) {
                n++;
                break;
            }
        if(n == 0)
            num++;
    }
    cout << "There are " << num << " prime numbers" << endl;
    endTime = clock();  // Renamed to 'endTime'
    cout << "The program duration is: " << endTime - start << " milliseconds" << endl << endl;

    return 0;
}
