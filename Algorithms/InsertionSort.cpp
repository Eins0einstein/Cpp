#include <iostream>
#include <stdio.h>

using namespace std;

#define ARRAYLENGTH 40

void InsertionSort(int *nums, int arrayLength);

int main(int argc, char *argv[])
{
	int nums1[ARRAYLENGTH];

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		nums1[i] = rand() % 500;
	}
	cout << "arraylength = " << ARRAYLENGTH << endl;
	cout << "Before Sorting" << endl;
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << "\t";
	}
	cout << endl;

	InsertionSort(nums1, ARRAYLENGTH);

	cout << "After Insertion Sorting" << endl;
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		cout << nums1[i] << "\t";
	}
	cout << endl;

	getchar();
}

void InsertionSort(int *numList, int arrayLength)
{
	int i, j;
	for (i = 1; i < arrayLength; i++)
	{
		int tmp = numList[i];
		for (j = i; j > 0 && numList[j - 1] > tmp; j--)
		{
			numList[j] = numList[j - 1];
		}
		numList[j] = tmp;
	}
}