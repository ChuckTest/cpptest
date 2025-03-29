#include <iostream>
#include <ctime>
#include <cmath>
using namespace std;

clock_t start, endTime; // Renamed 'end' to 'endTime'

int main()
{
	int x, i, n = 0;
	int num = 0;

	// Regular solution
	start = clock();
	for (x = 2; x <= 90000; x++)
	{
		n = 0;
		for (i = 1; i <= x; i++)
			if (x % i == 0)
				n++;
		if (n == 2)
			num++;
	}
	cout << "There are " << num << " prime numbers" << endl;
	endTime = clock(); // Renamed to 'endTime'
	cout << "The original program duration is: " << endTime - start << " milliseconds" << endl
		 << endl;

	// Optimization 1
	num = 0;
	start = clock();
	for (x = 2; x <= 90000; x++)
	{
		for (i = 2; i < x; i++)
			if (x % i == 0)
				break;
		if (i == x)
			num++;
	}
	cout << "There are " << num << " prime numbers" << endl;
	endTime = clock(); // Renamed to 'endTime'
	cout << "The program V1 duration is: " << endTime - start << " milliseconds" << endl
		 << endl;

	// Optimization 2
	num = 0;
	start = clock();
	for (x = 2; x <= 90000; x++)
	{
		n = 0;
		for (i = 2; i <= x / 2; i++)
			if (x % i == 0)
			{
				n++;
				break;
			}
		if (n == 0)
			num++;
	}
	cout << "There are " << num << " prime numbers" << endl;
	endTime = clock(); // Renamed to 'endTime'
	cout << "The program V2 duration is: " << endTime - start << " milliseconds" << endl
		 << endl;

	// Optimization 3
	num = 0;
	start = clock();
	for (x = 2; x <= 90000; x++)
	{
		int sqrtX = sqrt(x); // Precompute sqrt(x) to avoid repeated calls
		for (i = 2; i <= sqrtX; i++)
			if (x % i == 0)
			{
				n++;
				break;
			}
		if (n == 0)
			num++;
	}
	cout << "There are " << num << " prime numbers" << endl;
	endTime = clock(); // Renamed to 'endTime'
	cout << "The program V3 duration is: " << endTime - start << " milliseconds" << endl
		 << endl;

	num = 0;
	start = clock();

	for (x = 2; x <= 90000; x++)
	{
		if (x == 2)
		{
			num++; // 2 is prime, directly count it
			continue;
		}
		if (x % 2 == 0)
		{
			continue; // Skip even numbers
		}

		bool isPrime = true; // Assume x is prime unless proven otherwise
		int sqrtX = sqrt(x); // Precompute sqrt(x)

		// Check divisibility from 3 to sqrt(x), only for odd numbers
		for (i = 3; i <= sqrtX; i += 2)
		{
			if (x % i == 0)
			{
				isPrime = false; // Not prime if divisible by i
				break;
			}
		}

		if (isPrime)
		{
			num++; // Increment prime count
		}
	}

	cout << "There are " << num << " prime numbers" << endl;
	endTime = clock(); // Renamed to 'endTime'
	cout << "The program V4 duration is: " << endTime - start << " milliseconds" << endl
		 << endl;
	return 0;
}
