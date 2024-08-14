#include <iostream>
using namespace std;
void sort(int *arr, int n)
{

    if (n == 0 || n == 1)
    {
        return;
    }

    // processing

    for (int i = 0; i < n - 1; i++)
    {

        if (arr[i] > arr[i+1])
        {
            int temp = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = temp;
            // cout << "sorting :" << arr[i] << endl;
        }
    }
    // recursive call
    sort(arr, n - 1);
}

int main()
{

    int arr[5] = {3, 2, 4, 1, 5};

    sort(arr, 5);
     
     for (int i = 0; i < 5; i++)
     {
        cout <<  arr[i] ;
     }
     
    return 0;
}