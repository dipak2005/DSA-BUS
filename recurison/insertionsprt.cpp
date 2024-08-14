#include <iostream>
using namespace std;

void insertion(int *arr, int n)
{

    // base case
    if (n == 0 || n == 1)
    {
        return;
    }

    // recursive call
    insertion(arr, n - 1);

    // processing

    int last = arr[n - 1];
    int j = n - 2;
    while (j >= 0 && arr[j] > last)
    {
        arr[j + 1] = arr[j];
        j--;
    }
    arr[j + 1] = last;
}

int main()
{

    int arr[5] = {3, 5, 4, 2, 1};

    insertion(arr, 5);
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] ;
    }
    
    return 0;
}