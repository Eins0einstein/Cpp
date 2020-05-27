#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

#define ARRAYLENGTH 1000000
#define K 10

void InsertionSort(int *nums, int arrayLength);

void MI_Mixed(int *nums, int p, int r, int k);

void Merge(int *nums0, int p, int r);

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
        MI_Mixed(arr, 0, ARRAYLENGTH - 1, K);
    }
    clock_t endTime = clock();

    cout << "\nThe running time is " << (endTime - startTime) / 50 << endl;

    return 0;
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

void MI_Mixed(int *numList, int p, int r, int k)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        int n1 = q - p + 1;
        int n2 = r - q;

        int *nums1 = (int *)malloc(sizeof(int) * (n1));
        int *nums2 = (int *)malloc(sizeof(int) * (n2));

        int i, j, l;

        for (i = 0; i < n1; i++)
        {
            nums1[i] = numList[p + i];
        }
        for (j = 0; j < n2; j++)
        {
            nums2[j] = numList[q + 1 + j];
        }

        if ((q - p + 1) > k)
        {
            MI_Mixed(numList, p, q, k);
        }
        else
        {
            InsertionSort(nums1, q - p + 1);
        }

        if ((r - q) > k)
        {
            MI_Mixed(numList, q + 1, r, k);
        }
        else
        {
            InsertionSort(nums2, r - q);
        }

        i = 0;
        j = 0;
        l = p;

        while (i < n1 && j < n2)
        {
            if (nums1[i] <= nums2[j])
            {
                numList[l] = nums1[i];
                i++;
            }
            else
            {
                numList[l] = nums2[j];
                j++;
            }
            l++;
        }

        while (i < n1)
        {
            numList[l] = nums1[i];
            i++;
            l++;
        }

        while (j < n2)
        {
            numList[l] = nums2[j];
            j++;
            l++;
        }
    }
}