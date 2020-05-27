#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

void InsertionSort(int *nums, int arrayLength);

void MergeSort(int *nums, int p, int r, int k);

void Merge(int *nums0, int p, int r);

int main(int argc, char *argv[])
{
    int k;
    int j = 0;
    int ARRAYLENGTH;

    for (ARRAYLENGTH = 1000; ARRAYLENGTH <= 10000; ARRAYLENGTH = ARRAYLENGTH + 1000)
    {
        int nums1[ARRAYLENGTH];

        for (int i = 0; i < ARRAYLENGTH; i++)
        {
            nums1[i] = rand() % 10000;
        }

        int time[ARRAYLENGTH];
        int time2[ARRAYLENGTH];

        for (k = 0; k < ARRAYLENGTH; k++)
        {
            clock_t startTime2 = clock();
            MergeSort(nums1, 0, ARRAYLENGTH - 1, k);
            clock_t endTime2 = clock();
            time[k] = endTime2 - startTime2;
            time2[k] = time[k];
        }

        MergeSort(time, 0, ARRAYLENGTH - 1, 0);

        for (int i = 0; i < ARRAYLENGTH; i++)
        {
            if (time2[i] == time[0])
            {
                j = i;
                break;
            }
        }

        cout << "Given the array length " << ARRAYLENGTH
             << ", the best k is: " << j << endl;
    }

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

void MergeSort(int *numList, int p, int r, int k)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;
        int n1 = q - p + 1;
        int n2 = r - q;

        int *nums1 = (int *)malloc(sizeof(int) * (n1));
        int *nums2 = (int *)malloc(sizeof(int) * (n2));

        int i, j;

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
            MergeSort(numList, p, q, k);
        }
        else
        {
            InsertionSort(nums1, q - p + 1);
        }

        if ((r - q) > k)
        {
            MergeSort(numList, q + 1, r, k);
        }
        else
        {
            InsertionSort(nums2, r - q);
        }

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