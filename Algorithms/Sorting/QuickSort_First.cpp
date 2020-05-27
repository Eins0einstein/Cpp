#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

#define ARRAYLENGTH 1000000

void Swap(int *a, int *b);
int Partition(int arr[], int l, int r);
void QuickSort(int arr[], int l, int r);

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
        QuickSort(arr, 0, ARRAYLENGTH - 1);
    }
    clock_t endTime = clock();

    cout << "\nThe running time is " << (endTime - startTime) / 50 << endl;

    return 0;
}

void Swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int Partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int i = l + 1;
    int j;

    for (j = l + 1; j <= r; j++)
    {
        if (arr[j] < pivot)
        {
            Swap(&arr[i], &arr[j]);
            i++;
        }
    }
    Swap(&arr[l], &arr[i - 1]);
    return (i - 1);
}

void QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int j = Partition(arr, l, r);

        QuickSort(arr, l, j - 1);
        QuickSort(arr, j + 1, r);
    }
}