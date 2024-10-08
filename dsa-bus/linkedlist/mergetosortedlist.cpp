/*

#include <bits/stdc++.h>

/************************************************************

    Following is the linked list node structure.
    
    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
/*

Node<int>* solve(Node<int>* first, Node<int>* second) {

   // if only one node in first list
   if(first->next == NULL){
       first->next = second;
       return first;
   }

   Node<int>* curr = first;
   Node<int>* next1 = curr->next;
   Node<int>* curr2= second;

   while( next1 != NULL && curr2 != NULL )
   {
       if( (curr2->data >= curr->data) && (curr2->data <= next1->data))
       {
           // set the node
           curr->next = curr2;
           Node<int>* next2 = curr2->next;
           curr2->next = next1;

           // update the nodes
           curr =curr2;
           curr2 = next2;
       }
       else
       {
           curr = next1;
           next1=next1->next;

           if(next1 == NULL)
           {
                curr->next = curr2;
                return first;
           }
       }
   } 
   return first;
 }
   
Node<int>* sortTwoLists(Node<int>* first, Node<int>* second)
{
    if(first == NULL)
    return second;

    if(second == NULL)
    return first;

    if( first->data <= second->data )
    {
       return solve(first,second);
    }
    else
    {
        return solve(second,first);
    }
    return first;
}


*/