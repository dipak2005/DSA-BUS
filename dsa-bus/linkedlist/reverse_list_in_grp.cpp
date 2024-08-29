
class Solution {
  public:
    void inserAtTail (struct node *head, int data) {
        struct node* newnode = new node(data);
        
        if(head == NULL) {
            head = newnode;
        }
          head->next= newnode;
          head = newnode;
    }
  
    struct node *reverseIt(struct node *head, int k) {
          
    struct node* curr= head;
    struct node* prev= NULL;
    struct node* next = NULL;
    int count =0;
    
    
   
    
    while(curr != NULL && count <k) {
        next = curr->next;
        curr->next = prev;
        prev= curr;
        curr=next;
        count++;
    }
    
    if(next != NULL)
    {
        head->next = reverseIt(next,k);
    }
    return prev;
    }
};