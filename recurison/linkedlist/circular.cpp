#include <iostream>
#include<map>
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
bool isCircular (Node* &head) {

    if (head == NULL)
    {
        return true;
    }


Node* temp = head->next;
    while (temp == NULL && temp != head)
    {
        temp=temp->next;
    }

    if (temp == head)
    {
        return true;
    }
    return false;
    
}

void insertNode(Node* &tail, int element, int data)
{

    // list is empty so
    if (tail == NULL)
    {
        Node *temp = new Node(data);
        tail = temp;
        temp->next = temp;
    }
    else
    {
     // list is not empty 

        Node *curr = tail;

        while (curr->data != element)
        {

            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}


void print(Node* &tail)
{
Node* temp = tail;
       if (tail == NULL)
       {
        cout << "list is empty";
       }
       


    do{
        cout << tail->data << " ";
        tail=tail->next;

    } while (tail != temp);
    cout << endl;
}
int main()
{
    Node *tail = NULL;


    // insertNode(tail, 1, 10);
    // print(tail);

    // insertNode(tail, 2, 20);
    // print(tail);

    // deleteNode(tail,10);
    // print(tail);
    return 0;
}