#include <iostream>
#include <vector>
using namespace std;

class Node
{

public:
    int data;
    Node *next;

    Node(int d)
    {
        this->data = d;
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

        cout << " data from the node with :" << endl;
    }
};

void insetAtTail(Node *&tail, int data)
{
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}
void print(Node *&tail)
{

    if (tail == NULL)
    {
        cout << "list is empyt " << endl;
    }

    Node *temp = tail;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

bool checkPalindrom(vector<int> &arr)
{

    int i = 0;
    int j = arr.size() - 1;
    while (i <= j)
    {
        if (arr[i] != arr[j])
        {
            return false;
        }
        i++;
        j--;
        return true;
    }
}
bool ispalindrom(Node *&tail)
{
    vector<int> arr;
    Node *temp = tail;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrom(arr);
}
int main()
{
    Node *n1 = new Node(4);

    Node *temp = n1;
    print(temp);
    insetAtTail(temp, 2);
    print(temp);
    insetAtTail(temp, 1);
    print(temp);

    
    cout << "palindrom or not :" <<ispalindrom(temp) << endl;
    return 0;
}
/*

//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
#include <cmath>
#include <cstdio>
#include <ios>
#include <iostream>
#include <random>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
// aproch : 2 optimized 
class Solution {
  private:
  
    Node* getmid(Node* &head)
    {
      Node* slow=head;
      Node* fast=head->next;
      
      while(fast != NULL && fast->next != NULL)
      {
          fast=fast->next->next;
          slow = slow->next;
      }
      return slow;
    }
    
    Node* reverse(Node* &head){
        
        Node* curr= head;
        Node* next = NULL;
        Node* prev= NULL;
        
        while(curr != NULL){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
  public:
    
    bool isPalindrome(Node *head) {
      
      // base case
      if(head->next ==NULL){
          return true;
      }
      
      Node* middle=getmid(head);
      
      Node* temp = middle->next;
      middle->next = reverse(temp);
      
      Node* head1 = head;
      Node* head2 = middle->next;
      
      while(head2 != NULL){
          
          if(head1->data != head2->data) {
              return false;
          }
          head1=head1->next;
          head2=head2->next;
          
      }
      // again revrse the reverse to original list
        // temp = middle->next;
        //  middle->next = reverse(temp);
      return true;
    }
};


//{ Driver Code Starts.

/* Function to print nodes in a given linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

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

        if (arr.empty()) {
            cout << "empty" << endl;
            continue;
        }

        struct Node *head = new Node(arr[0]);
        struct Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        Solution ob;
        if (ob.isPalindrome(head))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        // Clean up the remaining nodes to avoid memory leaks
        while (head != NULL) {
            struct Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    return 0;
}

// } Driver Code Ends
*/