#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

#define ARRAYLENGTH 1000000

void MergeSort(int *arr, int l, int r);

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
        MergeSort(arr, 0, ARRAYLENGTH - 1);
    }
    clock_t endTime = clock();

    cout << "\nThe running time is " << (endTime - startTime) / 50 << endl;

    return 0;
}

void MergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;

        MergeSort(arr, l, m);
        MergeSort(arr, m + 1, r);

        int i, j, k;
        int n1 = m - l + 1;
        int n2 = r - m;

        int L[n1], R[n2];

        for (i = 0; i < n1; i++)
            L[i] = arr[l + i];
        for (j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j];

        i = 0;
        j = 0;
        k = l;

        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
            }
            else
            {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
    }
}