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
/*

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

void loopHere(Node* head, Node* tail, int position) {
    if (position == 0)
        return;

    Node* walk = head;
    for (int i = 1; i < position; i++)
        walk = walk->next;
    tail->next = walk;
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }

*/
class Solution {
    
    
  public:
    // Function to check if the linked list has a loop.
    bool detectLoop(Node* head) {
       
    Node* slow = head;
    Node* fast = head->next;
    
    //  bool result = solve(slow,fast);
      while(fast != NULL && fast->next != NULL){
          slow=slow->next;
          fast=fast->next->next;
          
          if(fast == slow) {
              return true;
          }
      }
      
     return false;
    }
};
/* detect  the  loop in list

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        int pos;
        cin >> pos;
        cin.ignore();

        Node* head = nullptr;
        Node* tail = nullptr;

        if (!arr.empty()) {
            head = new Node(arr[0]);
            tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
            loopHere(head, tail, pos);
        }

        Solution ob;
        if (ob.detectLoop(head))
            cout << "true\n";
        else
            cout << "false\n";

        // Free the allocated memory
        unordered_set<Node*> visited;
        Node* current = head;
        while (current && visited.find(current) == visited.end()) {
            visited.insert(current);
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }

    return 0;
}

// } Driver Code Ends
*/