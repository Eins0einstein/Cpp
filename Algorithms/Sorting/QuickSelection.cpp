#include <iostream>
#include <stdio.h>

using namespace std;

#define ARRAYLENGTH 1000000
#define key 50000

int partition(int arr[], int l, int r);
int RSelect(int arr[], int l, int r, int k);

int main()
{
    int *arr = new int[ARRAYLENGTH];

    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        arr[i] = rand() % 5000000;
    }

    cout << "Median element is " << RSelect(arr, 0, ARRAYLENGTH - 1, key);
    return 0;
}

int partition(int arr[], int l, int r)
{
    int pivot = rand() % (r - l + 1) + l;
    swap(arr[pivot], arr[l]);

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
        int index = partition(arr, l, r);

        if (index - l == k - 1)
            return arr[index];

        if (index - l > k - 1)
            return RSelect(arr, l, index - 1, k);

        return RSelect(arr, index + 1, r, k - index + l - 1);
    }

    return INT_MAX;
}
