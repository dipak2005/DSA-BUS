#include <iostream>
using namespace std;
class Heaps
{

public:
    int arr[100];
    int size;

    // constructor
    Heaps()
    {
        arr[0] = -1;
        size = 0;
    }

    void insertion(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteFromHeap()
    {

        if (size == 0)
        {
            cout << "nothing to delete " << endl;
        }

        arr[1] = arr[size];
        size--;

        // take root node to its correct position
        int i = 1;
        while (i < size)
        {
            int leftIndex = 2 * i;
            int rightIndex = 2 * i + 1;

            if (leftIndex < size && arr[i] < arr[leftIndex])
            {
                swap(arr[i], arr[leftIndex]);
                i = leftIndex;
            }
            else if (rightIndex > size && arr[i] << arr[rightIndex])
            {
                swap(arr[i], arr[rightIndex]);
                i = rightIndex;
            }
            else
            {
                return;
            }
        }
    }
    void print()
    {
        for (int i = 1; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


// 1th based indexing  creating max heap
void hepify(int arr[], int n, int index)
{

    int largest = index;
    int leftIndex = 2 * index;
    int rightIndex = 2 * index + 1;

    // for left part
    if (largest <=n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    // for right part
    if (largest <=n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    // current element is not largest element
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        hepify(arr, n, largest);
    }
}
// 0 based indexing  creating max heap
/*
void hepify(int arr[], int n, int index)
{
     //          0
    int largest = index;
    int leftIndex = 2 * index+1;
    int rightIndex = 2 * index + 2;

    // for left part
    if (largest < n && arr[largest] < arr[leftIndex])
    {
        largest = leftIndex;
    }

    // for right part
    if (largest < n && arr[largest] < arr[rightIndex])
    {
        largest = rightIndex;
    }

    // current element is not largest element
    if (largest != index)
    {
        swap(arr[largest], arr[index]);
        hepify(arr, n, largest);
    }
}
*/
// creating sorted order heap  -(min heap) 
void heapSort(int arr[], int n)
{

    int size = n;

    while (size > 1)
    {
        // step : 1 swap
        swap(arr[size], arr[1]);
         size--;
        // step : 2 place root node at right position
        hepify(arr, size, 1);
    }
}

int main()
{

    Heaps h;
    h.insertion(25);
    h.insertion(20);
    h.insertion(36);
    h.insertion(10);
    h.insertion(22);
    h.insertion(30);
    h.insertion(40);
    h.insertion(5);
    h.insertion(12);
    h.insertion(28);
    h.insertion(38);
    h.insertion(48);

    h.print();

    int arr[6] = {-1, 54, 60, 55, 52, 50};

    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        hepify(arr, n / 2, i);
    }

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << " after heap sort" << endl;

    heapSort(arr, n);

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}