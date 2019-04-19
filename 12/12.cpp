/*
Roland Fong
2/13/14
What is the value of the first triangle number to have over five hundred divisors?
*/

#include <iostream>
#include <vector>

using namespace std;

#define lint long long unsigned int

int main()
{
	lint tri = 1;
	int fact = 0;//factors
	vector<lint> primes;

	primes.push_back(2);//first prime is 2
	primes.push_back(3);//second prime is 3

	for(lint i = 2; fact < 500; i++)
	{
		tri += i;//next triangular number
		fact = 0;

		//algorithm 1 - cycle through finding factors
		/*for(int i = 1; i <= tri / 2 + 1; i++)
			if(tri % i == 0)//factor!
				fact++;

		fact++;//include # itself*/

		//algorithm 2 - use prime factorization (faster)
		lint temp = tri;
		lint count;
		lint product = 1;
		for(lint j = 0; temp != 1; j++)
		{
			count = 0;
			if(j >= primes.size())
			{
				primes.push_back(temp);//temp is the new prime
				cout << "NEW PRIME: " << temp << endl;
			}

			while(temp % primes.at(j) == 0)//while you can divide out that prime
			{
				temp /= primes.at(j);
				count++;
			}
			product *= (count + 1);
		}

		fact = product;

		cout << tri << ": " << fact << endl;
	}

	cout << "ANSWER: " << tri << endl;
}