/*
Roland Fong
7/29/12
Given 20x20 grid, find greatest product of four adjacent numbers, vertical, horizontal, or diagonal
*/

#include <iostream>
#include <fstream>

using namespace std;

#define uint unsigned int

void input(ifstream &grid, uint nums[][20]);//inputs grid nums into array
uint rowSum(uint nums[][20]);//find largest rowsum
uint colSum(uint nums[][20]);//find largest colsum
uint diagSum(uint nums[][20]);//find largest diagsum

int main()
{
	ifstream grid;
	grid.open("Grid.txt");

	uint nums[20][20];
	
	input(grid, nums);

	grid.close();
	
	cout << "ROWSUM: " << rowSum(nums) << endl;
	cout << "COLSUM: " << colSum(nums) << endl;
	cout << "DIAGSUM: " << diagSum(nums) << endl;

	system("pause");
	return 0;
}

void input(ifstream &grid, uint nums[][20])
{
	for(int r = 0; r < 20; r++)
		for(int c = 0; c < 20; c++)
			grid >> nums[r][c];
}
uint rowSum(uint nums[][20])
{
	uint final = 0;
	uint prod = 0;

	for(int r = 0; r < 20; r++)
	{
		for(int c = 0; c < 20 - 3; c++)
		{
			prod = nums[r][c] * nums[r][c + 1] * nums[r][c + 2] * nums[r][c + 3];
			if(prod > final)
				final = prod;
		}
	}
	return final;
}
uint colSum(uint nums[][20])
{
	uint final = 0;
	uint prod = 0;

	for(int c = 0; c < 20; c++)
	{
		for(int r = 0; r < 20 - 3; r++)
		{
			prod = nums[r][c] * nums[r + 1][c] * nums[r + 2][c] * nums[r + 3][c];
			if(prod > final)
				final = prod;
		}
	}
	return final;
}
uint diagSum(uint nums[][20])
{
	uint final = 0;
	uint prod = 0;

	//from upper left to lower right
	for(int r = 0; r < 20 - 3; r++)
	{
		for(int c = 0; c < 20 - 3; c++)
		{
			prod = nums[r][c] * nums[r + 1][c + 1] * nums[r + 2][c + 2] * nums[r + 3][c + 3];
			if(prod > final)
				final = prod;
		}
	}
	
	for(int r = 0; r < 20 - 3; r++)
	{
		for(int c = 3; c < 20; c++)
		{
			prod = nums[r][c] * nums[r + 1][c - 1] * nums[r + 2][c - 2] * nums[r + 3][c - 3];
			if(prod > final)
				final = prod;
		}
	}
	return final;
}
