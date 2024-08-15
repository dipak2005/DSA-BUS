/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};
*/
// aproch : 1
#include<iostream>
using namespace std;
class Node
{

public:
    int data;
    Node *next;
    

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
       
    }

    ~Node()
    {
        int val = this->data;

        if (this->next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << " memory is free form node with data : " << this->data << endl;
    }
};

Node* sortList(Node *head){
   
  
   int zeroCount=0;
   int oneCount=0;
   int twoCount=0;

   Node* curr = head;

   while(curr != NULL)
   {
       if(curr->data == 0)
         zeroCount++;
         else if (curr->data == 1)
         oneCount++;
         else if (curr->data == 2)
         twoCount++;
         curr= curr->next;
   }

   curr = head;
   while(curr != NULL)
   {
       if(zeroCount != 0){
           curr->data=0;
           zeroCount--;
       }
       else if (oneCount != 0){
           curr->data = 1;
           oneCount--;
       }else if (twoCount != 0){
           curr->data = 2;
           twoCount--;
       }
       curr=curr->next;
   }
   return head;
}