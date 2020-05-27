#include <iostream>
#include <stdio.h>

using namespace std;

#define ARRAYLENGTH 10
#define key 5

int partition(int arr[], int l, int r, int param);
int RSelect(int arr[], int l, int r, int k);
int DSelect(int arr[], int l, int r, int k);

int main()
{
    int arr[ARRAYLENGTH];

    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        arr[i] = rand() % 500000;
    }

    cout << "Median element is " << DSelect(arr, 0, ARRAYLENGTH - 1, key);
    return 0;
}

int partition(int arr[], int l, int r, int param)
{
    if (param == 0)
    {
        int pivot = rand() % (r - l + 1) + l;
        swap(arr[pivot], arr[l]);
    }
    else
    {
        int pivot = 0;
        for (int i = l; i <= r; i++)
        {
            if (arr[i] == param)
            {
                pivot = i;
                swap(arr[pivot], arr[l]);
                break;
            }
        }
    }

    int x = arr[l], i = l + 1;
    for (int j = l + 1; j <= r; j++)
    {
        if (arr[j] <= x)
        {
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i - 1], arr[l]);
    return i - 1;
}

int RSelect(int arr[], int l, int r, int k)
{
    if (k > 0 && k <= r - l + 1)
    {
        int index = partition(arr, l, r, 0);

        if (index - l == k - 1)
            return arr[index];

        if (index - l > k - 1)
            return RSelect(arr, l, index - 1, k);

        return RSelect(arr, index + 1, r, k - index + l - 1);
    }

    return INT_MAX;
}

int DSelect(int arr[], int l, int r, int k)
{
    if (l < r)
    {
        int h = (r - l + 1) / 5;
        int C[h];
        for (int i = 0; i < h; i++)
        {
            if (5 * i + 4 < ARRAYLENGTH)
            {
                C[i] = RSelect(arr, 5 * i, 5 * i + 4, 2);
            }
            else
            {
                C[i] = RSelect(arr, 5 * i, ARRAYLENGTH - 1, (ARRAYLENGTH - 1 - 5 * i) / 2);
            }
        }

        int pivot = DSelect(C, 0, h - 1, h / 2);
        int index = partition(arr, l, r, pivot);

        if (index - l == k - 1)
            return arr[index];

        if (index - l > k - 1)
            return DSelect(arr, l, index - 1, k);

        return DSelect(arr, index + 1, r, k - index + l - 1);
    }
    else
    {
        return arr[l];
    }
}