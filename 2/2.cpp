/*
Roland Fong
2/11/12
Each new term in the Fibonacci sequence is generated by adding the previous two terms. By starting with 1 and 2, the first 10 terms will be:

1, 2, 3, 5, 8, 13, 21, 34, 55, 89, ...

By considering the terms in the Fibonacci sequence whose values do not exceed four million, find the sum of the even-valued terms.
*/

#include <iostream>
using namespace std;

int main()
{
	int fib = 1;
	int pfib = 1;
	int ppfib = 1;
	int sum = 0;
	int n = 1;
	int r = 1;

	while ( fib <= 4000000)
	{
		if (r == 0)
		{
			sum = sum + fib;
		}
		else
		{
			sum = sum;
		}
		fib = pfib + ppfib;
		ppfib = pfib;
		pfib = fib;
		n = n + 1;
		r = fib % 2;
	}
	cout << sum << endl;
	system ("pause");
	return 0;
}