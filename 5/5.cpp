/*
Roland Fong
2/17/12
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/
#include <iostream>
using namespace std;

int main()
{
	int num = 11;
	int r5;
	int r7;
	int r9;
	int r11;
	int r13;
	int r16;
	int r17;
	int r19;

	while(true)
	{
		r5 = num % 5;
		r7 = num % 7;
		r9 = num % 9;
		r11 = num % 11;
		r13 = num % 13;
		r16 = num % 16;
		r17 = num % 17;
		r19 = num % 19;
		if(r5 == 0 && r7 == 0 && r9 == 0 && r11 == 0 && r13 == 0 && r16 == 0 && r17 == 0 && r19 == 0)
			break;
		num++;
		
	}
	cout << num << endl;
	system("pause");
	return 0;
}