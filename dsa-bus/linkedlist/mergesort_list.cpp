/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };
    
********************************************************************/


node* findMid(node* head){

   node* slow=head;
   node* fast = head->next;

  while(fast != NULL && fast->next != NULL){
      slow=slow->next;
      fast=fast->next->next;
  }
  return slow;
}
node* solve(node* left,node* right){

  // right part will be null
  if(right == NULL)
    return left;

  // left part will be null
  if(left == NULL)
    return right;    

  // create dummy node
  node* ans=new node(-1);
  node* temp = ans;

  // merge the sorted linkedlist
  while( left != NULL && right != NULL)
  {
      if(left->data < right->data)
      {
          temp->next = left;
          temp = left;
          left= left->next;
      }else
      {
          temp->next = right;
          temp=right;
          right=right->next;
      }

  }

  // right part will be null
  while(left!= NULL)
  {
       temp->next = left;
       temp = left;
       left= left->next;
  }

// left part will be null
  while(right !=NULL)
  {
       temp->next = right;
          temp = right;
          right= right->next;
  }

  ans= ans->next;
  return ans;
}
node* mergeSort(node *head) {

  // base case
  if(head == NULL || head->next == NULL)
     return head;
     

  // find the mid
  node* mid=findMid(head);

  node* left=head;
  node* right=mid->next;

  mid->next=NULL;

  // for leftpart 
  left = mergeSort(left);

  // for right part
 right = mergeSort(right);

  // merge the sorted linkedlist
  node* result = solve(left,right);

   return result;
}
