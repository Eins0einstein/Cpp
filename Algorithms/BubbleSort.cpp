#include <iostream>
#include <stdio.h>
#include <time.h>

using namespace std;

#define ARRAYLENGTH 10000

void BubbleSort(int *arr, int length);

int main(int argc, char *argv[])
{
    int nums1[ARRAYLENGTH];

    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        nums1[i] = rand() % 500;
    }
    cout << "arraylength = " << ARRAYLENGTH << endl;
    cout << "Before Sorting" << endl;
    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        cout << nums1[i] << "\t";
    }
    cout << endl;

    clock_t startTime2 = clock();
    BubbleSort(nums1, ARRAYLENGTH);
    clock_t endTime2 = clock();

    cout << "After Bubble Sorting" << endl;
    for (int i = 0; i < ARRAYLENGTH; i++)
    {
        cout << nums1[i] << "\t";
    }
    cout << endl;

    cout << "Running Time for Merge Sort is " << (endTime2 - startTime2) << endl;

    getchar();
}

void BubbleSort(int arr[], int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
