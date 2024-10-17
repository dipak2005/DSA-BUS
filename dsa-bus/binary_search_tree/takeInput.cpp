#include<iostream>
using namespace std;

class Node {

 public:
   int data;
   Node* left; // small as compare to root node
   Node* right; // big as compare to root node

   // initialization 
   Node(int data) {
  
   this->data = data;
   this->left=NULL;
   this->right = NULL;
   }
};
void insertIntoBst (Node* &root,int data) {
  
  // base case 
  if (root == NULL)
  {
    root = new Node(data);
    return;
  }

  if(data > root->data) {
    // right part
    insertIntoBst(root->right,data);
  }
  else{
    insertIntoBst(root->left,data);
  }
  
   
}
// 1 8 11 6 9 -1 13 5 7 -1 -1 12 -1

void printnode (Node* root) {

  while (root != NULL)
  {
     cout << root->data ;
  }
  
}
 void takeInput (Node* root) {

int data;
cin >> data;
  
 
    while (data != -1)
    {
      insertIntoBst(root , data);
      cin >> data;
    }
    
 }

int main () {
 
 Node* root = NULL;
  cout << "Enter data" ;
  takeInput(root);
  printnode(root);

  return 0;
}

