#include <iostream>
#include <time.h>
#include <stdio.h>

using namespace std;

#define ARRAYLENGTH 1000000

int ChoosePivot(int l, int r);
void Swap(int *a, int *b);
int Partition(int arr[], int l, int r);
int Randomized_Partition(int arr[], int l, int r);
void Randomized_QuickSort(int arr[], int l, int r);

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
        Randomized_QuickSort(arr, 0, ARRAYLENGTH - 1);
    }
    clock_t endTime = clock();

    cout << "\nThe running time is " << (endTime - startTime) / 50 << endl;

    return 0;
}

int ChoosePivot(int l, int r)
{
    srand(time(NULL));
    int p = (rand() % (r - l + 1)) + l;
    return p;
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

int Randomized_Partition(int arr[], int l, int r)
{
    int i = ChoosePivot(l, r);
    Swap(&arr[i], &arr[l]);

    int j = Partition(arr, l, r);
    return j;
}

void Randomized_QuickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int j = Randomized_Partition(arr, l, r);

        Randomized_QuickSort(arr, l, j - 1);
        Randomized_QuickSort(arr, j + 1, r);
    }
}