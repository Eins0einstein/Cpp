#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void InsertionSort(int *nums, int arrayLength);

void MergeSort(int *nums, int p, int r);

void Merge(int *nums0, int p, int r);

int main(int argc, char *argv[])
{
	int ARRAYLENGTH;
	int *k_arr;
	int j = 0;

	for (ARRAYLENGTH = 5000; ARRAYLENGTH != 0; ARRAYLENGTH--)
	{
		int nums1[ARRAYLENGTH];

		for (int i = 0; i < ARRAYLENGTH; i++)
		{
			nums1[i] = rand() % 10000;
		}

		clock_t startTime1 = clock();
		InsertionSort(nums1, ARRAYLENGTH);
		clock_t endTime1 = clock();

		int time1 = (endTime1 - startTime1);

		for (int i = 0; i < ARRAYLENGTH; i++)
		{
			nums1[i] = rand() % 10000;
		}

		clock_t startTime2 = clock();
		MergeSort(nums1, 0, ARRAYLENGTH - 1);
		clock_t endTime2 = clock();

		int time2 = (endTime2 - startTime2);

		if ((time1 - time2) < 0)
		{
			k_arr[j] = ARRAYLENGTH;
			j++;
			cout << ARRAYLENGTH << endl;
		}
	}
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

void MergeSort(int *numList, int p, int r)
{
	if (p < r)
	{
		int q = p + (r - p) / 2;
		MergeSort(numList, p, q);
		MergeSort(numList, q + 1, r);

		Merge(numList, p, r);
	}
}

void Merge(int *nums0, int p, int r)
{
	int q = p + (r - p) / 2;
	int n1 = q - p + 1;
	int n2 = r - q;

	int *nums1 = (int *)malloc(sizeof(int) * (n1));
	int *nums2 = (int *)malloc(sizeof(int) * (n2));

	int i, j, k;

	for (i = 0; i < n1; i++)
	{
		nums1[i] = nums0[p + i];
	}
	for (j = 0; j < n2; j++)
	{
		nums2[j] = nums0[q + 1 + j];
	}

	i = 0;
	j = 0;
	k = p;

	while (i < n1 && j < n2)
	{
		if (nums1[i] <= nums2[j])
		{
			nums0[k] = nums1[i];
			i++;
		}
		else
		{
			nums0[k] = nums2[j];
			j++;
		}
		k++;
	}

	while (i < n1)
	{
		nums0[k] = nums1[i];
		i++;
		k++;
	}

	while (j < n2)
	{
		nums0[k] = nums2[j];
		j++;
		k++;
	}
}