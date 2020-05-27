#include <iostream>

using namespace std;

int main()
{
    constexpr size_t sz = 5;
    int arr[sz] = {1, 2, 3, 4, 5};
    /*auto en = end(arr);
    auto beg = begin(arr);*/
    auto *ptr = &arr[4];
    auto n = end(arr) - ptr;

    for (auto rr : arr)
    {
        rr = rr + 1;
    }
    for (auto r : arr)
    {
        cout << r << endl;
    }
}