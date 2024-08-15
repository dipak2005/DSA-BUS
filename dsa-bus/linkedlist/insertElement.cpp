#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int value = this->data;

        // free memory
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node *&head)
{
    if (head == NULL)
    {
        cout << "List is empty " << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtPosition(Node *&head, Node *&tail, int pos, int data)
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos - 1)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(tail, data);
        return;
    }

    // to put the data in node
    Node *node = new Node(data);

    // point the pointer left to right ->
    node->next = temp->next;

    // point the pointer new node left to right ->
    temp->next = node;
}

void deleteNode(int pos,  Node *&head, Node* &tail)
{

    // deleting first node
    if (pos == 1)
    {

        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        Node* current = head;
        Node* previous = NULL;

        int count = 1 ;

        while (count < pos)
        {
            previous = current;
            current = current->next;
            count++;
            
        }
       
        
        if (current->next == NULL)
        {
            tail =previous;
        }

        previous->next= current->next;
        current->next = NULL;
        delete current;  
    }
}

int main()
{
    Node *n1 = new Node(10);

    Node *head = n1;
    Node *tail = n1;

    insertAtTail(tail, 12);
    insertAtTail(tail, 15);
    print(head);

    insertAtPosition(head, tail, 4, 22);
    print(head);

    deleteNode(4,head,tail);
    print(head);

    cout << "head : " << head->data << " ";
    cout << "tail : " << tail->data << " ";

    // Clean up memory (optional, but recommended)
    // delete head;

    return 0;
}
/*

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
void insertAtTail(Node* &tail,Node* &curr){
        tail->next=curr;
        tail=curr;
    }
    


Node* sortList(Node *head){
     
     Node* zeroHead= new Node(-1);
     Node* zeroTail=zeroHead;

     Node* oneHead = new Node(-1);
     Node* oneTail = oneHead;

     Node* twoHead = new Node(-1);
     Node* twoTail = twoHead;

     Node* curr=head;

     while( curr != NULL){

         int val = curr->data;

         if(val == 0)
         {
            insertAtTail(zeroTail, curr);
         }
         else if (val ==1)
         {
             insertAtTail(oneTail, curr);
         }
         else if (val==2)
         {
             insertAtTail(twoTail, curr);
         } 
         curr=curr->next;
     }
     
     if(oneHead->next != NULL)
     {
         zeroTail->next = oneHead->next;
     }
     else
     {
         // one tail list is empty
         zeroTail->next = twoHead->next;
        
     }
     
     oneTail->next = twoHead->next;
     twoTail->next=NULL;

       head=zeroHead->next;

       delete zeroHead;
       delete oneHead;
       delete twoHead;

       return head;
     
}

*/