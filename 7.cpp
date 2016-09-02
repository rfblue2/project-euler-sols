/*
Roland Fong
2/17/12
What is the 10 001st prime number?
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int r;
	int n;
	double root;
	int a = 4;
	int b = 2;
	int prime;

	cin >> n;

	while(true)
	{
		root = pow(a,0.5);
		//cout << "The sqrt is " << root << endl;
		while (b <= root)
		{
			r = a % b;
			//cout << "r = " << r << endl;
			if (r == 0)
			{
				n++;
				//cout << "Not Prime!" << endl;
				break;
			}
			b++;
			//cout << "b = " << b << endl;
		}
		if(r != 0)
		{
			//cout << "Prime!" << endl;
			prime = a;
		}
		n--;
		a++;
		b = 2;
		cout << n << endl; // n only
		//cout << a << endl;
		if (n == 2)
			break;
	}

	cout << "The 10001st prime is " << prime << endl;

	system("pause");
	return 0;
}