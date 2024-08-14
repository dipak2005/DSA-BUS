#include <iostream>
using namespace std;
void selection(int *arr, int n)
{

    // base case
    if (n == 0 || n == 1)
    {
        return;
    }

    for (int i = 0; i < n - 1; i++)
    {
        int minval = i;
        if (arr[i + 1] < arr[minval])
        {
            int temp = arr[i + 1];
            arr[i + 1] = arr[i];
            arr[i] = temp;
        }
    }
    selection(arr, n - 1);
}

int main()
{

    int arr[5] = {3, 5, 4, 2, 1};

    selection(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout <<  arr[i];
    }
    return 0;
}