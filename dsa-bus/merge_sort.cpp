#include <iostream>
#include <vector>
using namespace std;
vector<int> merge(vector<int> &num, int si, int ei, int mid)
{

    int i = si;
    int j = mid + 1;
    int k = 0;
    int size= ei-si+1;
    vector<int> temp(size);

    while (i <= mid && j >= ei)
    {
        if (num[i] < num[j])
        {
            temp[k++] = num[i++];
        }
        else
        {
            temp[k++] = num[j--];
        }
    }

    // left part
    while (i < mid)
    {
        temp[k++] = num[i++];
    }

    // right part

    while (j > mid)
    {
        temp[k++] = num[j--];
    }

    for (int k = 0, i = si; i < temp.size(); k++, i++)
    {
        num[i] = temp[k];
    }

    return num;
}

void mergeSort(vector<int> &num, int si, int ei)
{

    // base case
    if (si >= ei)
    {
        return;
    }

    int mid = si + (ei - si) / 2;
    // for left part
    mergeSort(num, si, mid);
    mergeSort(num, mid + 1, ei);

    // divided array merge here
    merge(num, si, ei, mid);
}

int main()
{

    vector<int> arr = {-1, 6, 5, 20, 3, 2, 1};

int n=arr.size();
    mergeSort(arr, 0, n);

    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}