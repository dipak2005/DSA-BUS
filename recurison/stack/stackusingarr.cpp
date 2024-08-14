#include <iostream>
using namespace std;

class Stack
{

public:
    int *arr;
    int top;
    int size;

    // constructor
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        this->top = -1;
    }

    void push(int element)
    {

        if (size - top > 1)
        {
            top++;
            arr[top] = element;
        }
        else
        {
            cout << "stack is overflow" << endl;
        }
    }

    void pop()
    {

        if (top >= 0)
        {
            top--;
        }
        else
        {
            cout << "stack is under flow" << endl;
        }
    }

    int peek()
    {
        if (top >= 0)
        {
            return arr[top];
        }
        else
        {
            cout << "stack is empty" << endl;
            return -1;
        }
    }

    bool empty()
    {
        if (top == -1)
        {
            cout << "stack is empty " << endl;
            return true;
        }

        cout << " stack is not empty " << endl;
        return false;
    }
};

int main()
{

Stack st(5);

st.push(1);
cout<< st.peek()  <<  endl;
st.push(2);
cout<< st.peek()  << endl;

st.push(3);
cout<< st.peek()  << endl;

st.push(4);
cout<< st.peek()  << endl;


cout<< "last element" << st.peek()  << endl;
cout << "after pop opreation" << endl;
st.pop();
cout<< st.peek()  << endl;
    return 0;
}