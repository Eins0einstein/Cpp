#include<iostream>
#include<stdio.h>
#include<time.h>

using namespace std;


#define ARRAYLENGTH 1000000

#define SIMULATIONCOUNT 100


void InsertionSort(int* numList, int start, int arrayLength);
void MergeSort(int* nums, int p, int r);
void Merge(int* numsList, int p, int q, int r);
void NewSort(int* nums, int p, int r, int d);


int main()
{
    int *arr = new int[ARRAYLENGTH];

    clock_t startTime = clock();
    for (int count = 0; count < 50; count++)
    {
        for (int i = 0; i < ARRAYLENGTH; i++)
        {
            arr[i] = rand() % 500000;
        }
        NewSort(arr, 1, ARRAYLENGTH, 10);
    }
    clock_t endTime = clock();

    cout << "\nThe running time is " << (endTime - startTime) / 50 << endl;

    return 0;
}

void Merge(int* numList, int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int* nums1 = (int*)malloc(sizeof(int) * (n1 + 1));
	int* nums2 = (int*)malloc(sizeof(int) * (n2 + 1));
	for (int i = 0; i < n1; i++)
		nums1[i] = numList[p + i - 1];
	for (int i = 0; i < n2; i++)
		nums2[i] = numList[q + i];
	nums1[n1] = 10000;
	nums2[n2] = 10000;
	int i = 0, j = 0, k = 0;
	while (i < n1 && j < n2)
	{
		if (nums1[i] <= nums2[j])
			numList[k++] = nums1[i++];
		else numList[k++] = nums2[j++];
	}
	while (i < n1) numList[k++] = nums1[i++];
	while (j < n2) numList[k++] = nums2[j++];

	free(nums1);
	free(nums2);
}

void MergeSort(int* numList, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(numList, p, q);
		MergeSort(numList, q + 1, r);
		Merge(numList, p, q, r);
	}
}
void InsertionSort(int* numList, int start, int arrayLength)
{
	int i, j, k;
	for (i = start; i < arrayLength; i++)
	{
		if (numList[i] < numList[i - 1])
		{
			k = numList[i];
			for (j = i - 1; j >= 0 && numList[j] > k; j--)
				numList[j + 1] = numList[j];
			numList[j + 1] = k;
		}
	}
}
void NewSort(int* numList, int p, int r, int d)
{
	if (r - p < d) {
		InsertionSort(numList, p, r);
	}

	else if (p < r)
	{
		int q = (p + r) / 2;
		NewSort(numList, p, q, d);
		NewSort(numList, q + 1, r, d);
		Merge(numList, p, q, r);
	}
}
