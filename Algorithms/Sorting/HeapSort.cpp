#include <iostream>
#include <time.h>

using namespace std;

#define ARRAYLENGTH 1000

void maxHeapify(int arr[], int n, int i);
void maxHeapSort(int arr[], int n);

int main()
{
    int *arr = new int[ARRAYLENGTH];

    srand(time(NULL));
    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        arr[i] = rand() % 50000;
    }

    cout << "Before sorting, the array is: " << endl;
    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        cout << arr[i] << " ";
    }

    clock_t startTime = clock();
    maxHeapSort(arr, ARRAYLENGTH);
    clock_t endTime = clock();
    cout << "\nThe running time is " << (endTime - startTime) << endl;

    cout << "After sorting, the array is: " << endl;
    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

void maxHeapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if (l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if (r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        maxHeapify(arr, n, largest);
    }
}

void maxHeapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
    
    for (int i = n - 1; i > 0; i--)
    {
        swap(arr[0], arr[i]);

        maxHeapify(arr, i, 0);
    }
}
