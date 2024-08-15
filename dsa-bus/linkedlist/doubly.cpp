#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *prev;
    Node *next;
   
    // contructor
    Node(int d)
    {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
    // destructor
    ~Node() {
        int val = this->data ;
        if (next != NULL)
        {
            
            delete next;
            next = NULL;
        }
        cout << " memory is free from node with data : " <<  val << endl;
    }
};


void insertAtTail(Node *&tail, int d)
{
    if (tail == NULL)
    {
        Node *temp = new Node(d);
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail=temp;
    }
}
void insertAtHead(Node *&head, int d)
{
    if (head == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
    }
    else
    {

        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}void insertAtPosition(Node *&tail, Node *&head, int pos, int d)
{

    if (pos == 1)
    {
        insertAtHead(head, d);
        return;
    }

    Node *temp = head;
    int count = 1;

    while (count < pos)
    {
        temp = temp->next;
        count++;
    }
    

    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }

    Node *newNode = new Node(d);
    newNode->next = temp->next;
    temp->next->prev = newNode;
    newNode->prev = temp;
}

void deleteNode(Node* &head , Node* &tail ,int pos ){

 if (pos == 1)
 {
    Node* temp = head;
    temp->next->prev = NULL;
    head = temp->next;

    cout << temp->data << endl;
    temp->next= NULL;
    delete temp;
 }

 else {
    Node* curr= head;
    Node* prev=head;

    int count =1;
    while (count < pos)
    {
        prev = curr;
        curr =curr->next;
        count++;
    }

    
    if(curr->next == NULL){
        tail= prev;
    }
    curr->prev=NULL;
    prev->next = curr->next;
    curr->next=NULL;
    delete curr;


    
 }
   
}
int getlength(Node *head)
{

    Node *temp = head;

    int length = 0;
    while (temp != NULL)
    {
        length++;
        temp = temp->next;
    }
    return length;
}
void print(Node* &head,Node* &tail)
{

    Node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    cout << "head : "<< head->data  << endl;
    cout << "tail : "<< tail->data << endl;
}
int main()
{
    Node *node = new Node(10);

    Node *head = node;
    Node *tail = node;

    // cout <<  "length :  " <<getlength(node) << endl ;

    insertAtHead(head, 20);
    print(head, tail);

    insertAtHead(head, 30);
    print(head,tail);

    insertAtHead(head, 40);
    print(head,tail);

    insertAtTail(tail, 15);
    print(head , tail);

    insertAtPosition(tail,head,1,101);
    print(head,tail);

    deleteNode(head,tail,6);
    print(head,tail);
    return 0;
}