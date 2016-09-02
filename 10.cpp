/*
Roland Fong
7/28/12
Find the sum of all the primes under two million
*/

#include <iostream>
#include <cmath>

using namespace std;

#define lint long long unsigned int

bool isPrime(lint num);

int main()
{
	lint sum = 0;

	for(lint i = 0; i < 2000000; i++)
	{
		if(isPrime(i))
		{
			sum += i;
			//cout << "i = " << i << endl;
			//cout << "sum = " << sum << endl;
		}
	}
	cout << "SUM: " << sum << endl;
	system("pause");
	return 0;
}

bool isPrime(lint num)
{
	if(num < 2)
		return false;

	else if(num == 2)
		return true;

	for(lint i = 2; i <= (lint)pow(num, 0.5); i++)
	{
		if(num % i == 0)
			return false;
	}

	return true;
}