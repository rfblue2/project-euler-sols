/*
Roland Fong
6/14/12
Problem 9: 
There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include <iostream>
#include <cmath>
using namespace std;

bool checkInt(double num);

int main()
{
	double a, b, c;
	for(int i = 1; i < 10000; i++)
	{
		a = i;
		//cout << "a = " << a << ";";
		for(int j = 1; j < 10000; j++)
		{
			b = j;
			c = pow(a * a + b * b, 0.5);
			//cout << "b = " << b << endl;
			//cout << "c = " << c << endl;
			if(checkInt(c) == true)
			{
				if(a + b + c == 1000)
				{
					cout << "a = " << a << endl;
					cout << "b = " << b << endl;
					cout << "c = " << c << endl;
					cout << "SUM = " << a + b + c << endl;
					cout << "PRODUCT = " << a * b * c << endl;
					break;
				}
			}
		}
	}
	system("pause");
	return 0;
}

bool checkInt(double num)
{
	int num2 = num;
	double num3 = num2;

	if(num3 == num)
		return true;
	return false;
}