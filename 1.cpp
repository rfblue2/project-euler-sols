/*
Roland Fong
2/11/12
If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.

Find the sum of all the multiples of 3 or 5 below 1000.
*/

#include <iostream>
using namespace std;

int main()
{
	int sum = 0;
	int five = 5;
	int three = 3;
	int fifteen = 15;
	int r1;
	int r2;
	int r3;
	for(int c = 1; c < 1000; c++ )
	{
		r1 = c % 3;
		r2 = c % 5;
		r3 = c % 15;
		if (r1 == 0)
		{
			sum = sum + three;
			three = three + 3;
		}
		else
			sum = sum;
		if (r2 == 0)
		{
			sum = sum + five;
			five = five + 5;
		}
		else
			sum = sum;
		if (r3 == 0)
		{
			sum = sum - fifteen;
			fifteen = fifteen + 15;
		}
		
	}
	cout << sum << endl;
	system("pause");
	return 0;
}