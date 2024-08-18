#include <iostream> 
using namespace std;
class Queue {

     int* arr;
        int qfront;
        int rear;
        int size;
public:
    Queue() {
        size= 1000;
        arr=new int[size];
        qfront=0;
        rear=0;

    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        
        if(qfront == rear) {
            return true;
        }
        else{
            return false;
        }
        
    }

// push operation
    void enqueue(int data) {
        
        if(rear == size-1) {
           
        }
        else{
            arr[rear]=data;
            rear++;
        }
    }
 
 // pop operation

    int dequeue() {
       
       if(qfront == rear) {
           
           return -1;
       }
       else{
            int ans=arr[qfront];
           arr[qfront]=-1;
           qfront++;
           if(qfront == rear){
               qfront=0;
               rear= 0;
           }
           return ans;
       }
    }

    int front() {
        if(isEmpty()){
            return -1;
        }
        else{
           return  arr[qfront];
        }
    }
};