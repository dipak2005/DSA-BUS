#include <iostream>
#include <map>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }

    // destructor
    ~Node()
    {
        int val = this->data;
        while (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "data from the node : " << this->data << endl;
    }
};

Node* floaidCycle(Node* head){

    Node* slow=head;
    Node* fast=head;

    if (head == NULL)
    {
        return NULL;
    }
    

    while (slow != NULL && fast != NULL)
    {
        fast=fast->next;
        if (fast != NULL)
        {
           fast =  fast->next;
        }
        slow=slow->next;
    }

    if (slow == fast)
    {
        return slow;
    }
    
    
}

Node* loopBegining(Node* head) {

    // base case
    if (head == NULL)
    {
        return NULL;
    }

    Node* intersection = floaidCycle(head);
    if(intersection == NULL)
    return NULL;
    Node* slow= head;
    while (slow != intersection)
    {
        slow=slow->next;
        intersection = intersection->next;
    }
    
    return slow;

}

void removeLoop(Node* head) {

if (head == NULL)
{
    return;
}

  Node* meetpoint=loopBegining(head);
  if (meetpoint == NULL)
  {
      return;
  }
  
  Node* temp = meetpoint;
  while (temp->next != meetpoint)
  { 
      temp=temp->next;
  }
  temp->next=NULL;
  

}
bool isCycle(Node *&head)
{

    Node *temp = head;
    map<Node *, bool> visited;

    // base case
    if (head == NULL)
    {
        cout << "list is empty " << endl;
        return false;
    }

    while (temp != NULL)
    {
        if (visited[temp] == true)
        {
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}
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
        cout << "list is empty " << endl;
        return;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{

    Node *n1 = new Node(10);

    Node *head = n1;
    Node *tail = n1;
    insertAtHead(head, 5);
    print(head);

    insertAtTail(tail, 15);
    print(head);

    isCycle(head);
    print(head);
    return 0;
}