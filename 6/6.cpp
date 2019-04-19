/*
Roland Fong
2/17/12

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int in;
	int square;
	int sum1 = 0;
	int sum2 = 0;

	cin >> in;
	//sum of squares
	for (int n = 1; n < in + 1; n++)
	{
		square = pow(n,2.0);
		sum1 += square;
	}
	for (int m = 1; m < in + 1; m++)
	{
		sum2 += m;
	}
	sum2 = pow(sum2,2.0);

	cout << sum1 - sum2 << endl;

	system("pause");
	return 0;
}