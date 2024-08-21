#include<iostream>
using namespace std;

class KQueue {

   
   int n;// n size for front array
   int k;// k size for rear array
   int freespot;//detect the next empty block
   int *front;
   int *rear;
   int *next;// final array
   int *arr;

   public:
   KQueue(int n ,int k) {
    this->n = n;
    this->k = k;
    front = new int [k];
    rear = new int [k];
   
    for (int i = 0; i < k; i++)
    {
        front[i] = -1;
        rear[i] = -1;
    }
    next = new int [n];

    for (int i = 0; i < n; i++)
    {
        next[i] = i+1;
    }
    
    next[n-1] = -1;
    arr = new int[n];
    freespot =0; 
    
   }

   void push(int data,int qn) {

    // overflow
   }
};

int main() {

    return 0;
}