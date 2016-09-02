/*
Roland Fong
2/11/12
Structure should be improved.
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/
#include <iostream>
#include <cstdint>
#include <algorithm>
using namespace std;

#define Show
#define Code1

#ifdef Code1
int main()
{
	int64_t num1;
	int64_t n = 2;
	int64_t factor = 1;
	int64_t pfactor = 1;
	int64_t r;
	int64_t root;

	cin >> num1;
	root = pow(num1,0.5);
	while (n < root)
	{
		r = num1 % n; //to use to check if num1 is even or not
#ifdef Show
		cout << "r = " << r << endl;
#endif
		if (r == 0) // it is even
		{
			if (n == 2 || n == 3) // if it is 2 or 3 it is prime
			{
				pfactor = n;
#ifdef Show
				cout << "First factor is " << pfactor << endl;
#endif
			}
			else
			{
				int64_t num2 = 2;
				int64_t remain = 1;
				while(num2 < n)
				{

					remain = n % num2;
					if (remain == 0)
					{
						n = n;
						break;
					}
					num2 = num2 + 1;
				}
				if (remain != 0)
				{
					pfactor = n;
				}
			}
		}
		else //don't worry if it isn't even
			n = n;
		if (pfactor > factor) // is it larger than the existing largest factor?
		{
			factor = pfactor;
#ifdef Show
			cout << "New factor is " << factor << endl;
#endif
		}
		n = n + 1;
#ifdef Show
		cout << "n is now " << n << endl;
#endif
	}
	cout << "The largest prime factor of " << num1 << " is " << factor << endl;
	system ("pause");
	return 0;
}
#endif

#ifndef Code1
bool prime;
class PrimeCheck
{
public:
void ifprime(int q)
{
	int64_t count1 = 2;
	int64_t remainder = 1;
	//bool prime;
	while (count1 < q)
	{
		remainder = q % count1;
		if (remainder == 0)
			prime = false;
			cout << "Not prime!" << endl;
		count1 = count1 + 1;
	}
	if (remainder != 0)
		prime = true;
		cout << "Prime!" << endl;
	return;
}
};

int main()
{
	int64_t in;
	int64_t count = 2;
	int64_t pfactor = 1;
	int64_t factor = 1;
	int64_t r;
	int64_t root;
	
	cin >> in;
	PrimeCheck isitprime;
	root = pow(in,0.5);
	while (count < root)
	{
		isitprime.ifprime(count);
		if (prime == true)
		{
			r = in % count;
			cout << "r is " << r << endl;
			if (r == 0)
			{
				pfactor = count;
				factor = max(factor, pfactor);
				cout << "New factor " << factor << endl;
			}
		}
		count = count + 1;
		cout << "Count is " << count << endl;
	}
	cout << "The largest prime factor is " << factor << endl;
	system("pause");
	return 0;
}
#endif