

#include <iostream>
using namespace std; 
class Deque  
{  
    int* arr;  
    int size;  
    int qfront;  
    int rear;  

public:  
    
    Deque(int n)  
    {  
        size = n;  
        arr = new int[size];  
        qfront = -1;  
        rear = -1;  
    }  

    ~Deque() {  
        delete[] arr;  
    }  

    bool pushFront(int x)  
    {  
        if(isFull())  
        {  
            return false;  
        }  
        else if(isEmpty())  
        {  
            qfront = rear = 0;  
        }  
        else if (qfront == 0 && rear != size - 1) // Fixed comparison  
        {  
            qfront = size - 1;  
        }  
        else  
        {  
            qfront--;  
        }  
        arr[qfront] = x;  
        return true;  
    }  

    bool pushRear(int x)  
    {  
        if(isFull())  
        {  
            return false;  
        }  
        else if(isEmpty())  
        {  
            qfront = rear = 0;  
        }  
        else if(rear == size - 1 && qfront != 0)  
        {  
            rear = 0;  
        }  
        else  
        {  
            rear++;  
        }  
        arr[rear] = x;  
        return true;  
    }  

    int popFront()  
    {  
        if(isEmpty())  
        {  
            return -1;  
        }  
        int ans = arr[qfront];  
        arr[qfront] = -1;  

        // single element  
        if(qfront == rear)  
        {  
            qfront = rear = -1;  
        }  
        else if (qfront == size - 1)  
        {  
            qfront = 0; // to maintain cyclic nature  
        }  
        else  
        {  
            qfront++;  
        }  
        return ans;  
    }  

    int popRear()  
    {  
        if(isEmpty())  
        {  
            return -1;  
        }  
        int ans = arr[rear];  
        arr[rear] = -1;  

        // single element  
        if(qfront == rear)  
        {  
            qfront = rear = -1;  
        }  
        else if (rear == 0)  
        {  
            rear = size - 1; // to maintain cyclic nature  
        }  
        else  
        {  
            rear--;  
        }  
        return ans;  
    }  

    int getFront()  
    {  
        if(isEmpty())  
        {  
            return -1;  
        }  
        return arr[qfront];  
    }  

    int getRear()  
    {  
        if(isEmpty())  
        {  
            return -1;  
        }  
        return arr[rear];  
    }  

    bool isEmpty()  
    {  
        return qfront == -1;  
    }  

    bool isFull()  
    {  
        return (qfront == 0 && rear == size - 1) || (qfront != 0 && (rear + 1) % size == qfront);  
    }  
};
int main () {
    Deque d(10);
    d.pushFront(5);
    d.pushRear(20);

cout<< "front" << d.getFront() << endl;
    d.pushFront(-4);
    d.pushRear(25);
cout << "back" << d.getRear() << endl; 
    d.popFront();
    d.popRear();

 cout<< "front" << d.getFront() << endl;
cout << "back" << d.getRear() << endl;   
    return 0;
}