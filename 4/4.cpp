/*
Roland Fong
2/13/12
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/
#include <iostream>
#include <cmath>
using namespace std;
//#define SHOW

int main()
{
	
	int in;
	int d[6]; // 0-4 is 5 digits, 0-5 is 6 digits; why is it d[6] even though there's 0??? to not corrupt the stack
	float divide;
	bool digits5;
	bool palindrome;

	//MAIN portion: Multiply three digit numbers
	int n = 500;
	int m = 500;
	int largest = 0;

	for (n < 999; n++;)
	{
		for (m < 999; m++;)
		{
			//Part 1: Input a number and count the digits
			in = n * m;
			cout << n << " * " << m << " = " << n * m << endl;
			divide = in / 100000.0;
			if (divide < 1)
			{
				digits5 = true;
#ifdef SHOW
				cout << "5 Digits" << endl;
#endif
			}
			else if (divide >=1)
			{
				digits5 = false;
#ifdef SHOW
				cout << "6 Digits" << endl;
#endif
			}

			//Part 2: Find the digits
			if (digits5 == true) // for five digit numbers
			{
				d[0] = in % 10;
#ifdef SHOW
				cout << d[0] << endl;
#endif
				for(int a = 1; a <= 4; ++a)
				{
					double power = pow (10.0, a+1);
					int power2 = (double) power;
					d[a] = (in % power2);
					for(int b = 1; b <= a; b++)
					{
						d[a] = d[a] - (d[b-1] * (pow (10.0 , b-1)));
					}
					d[a] = d[a] / (power2 / 10);
#ifdef SHOW
					cout << d[a] << endl;
#endif
				}
			}

			else if (digits5 == false) // for six digit numbers
			{
				d[0] = in % 10;
#ifdef SHOW
				cout << d[0] << endl;
#endif
				for(int a = 1; a <= 5; ++a)
				{
					double power = pow (10.0, a+1);
					int power2 = (double) power;
					d[a] = (in % power2);
					for(int b = 1; b <= a; b++)
					{
						d[a] = d[a] - (d[b-1] * (pow (10.0 , b-1)));
					}
					d[a] = d[a] / (power2 / 10);
#ifdef SHOW
					cout << d[a] << endl;
#endif
				}
			}
			//Part 3: Check if the number is a palindrome
			if (digits5 == true && d[0] == d[4] && d[1] == d[3])
			{
				palindrome = true;
			}
			else if (digits5 == false && d[0] == d[5] && d[1] == d[4] && d[2] == d[3])
				palindrome = true;
			else
				palindrome = false;
			if (palindrome == true)
			{
				cout << "Palindrome!" << endl;
				if ( in > largest)
					largest = in;
			}
			if (m > 998)
			{
				m = 100;
				break;
			}
		}
		if (n > 998)
		{
			n = 100;
			break;
		}
	}
	cout << "The largest palindrome that is a product of two three digit numbers is " << largest << endl;
	system("pause");
	return 0;
}