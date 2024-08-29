#include <iostream>
#include <queue>
using namespace std;
class node
{
public:
    node *left;
    node *right;
    int data;

    // constructer
    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};
node *buildTree(node *&root)
{

    cout << "Enter data :" << endl; 
    // 1 3 7 -1 -1 6 -1 -1  5 8 -1 -1 9 -1 -1
    int data;
    cin >> data;
    root = new node(data);

    node *temp = root;
    if (root->data == -1)
    {
        return NULL;
    }

    cout << "Enter data for left node:" << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data for right node :" << data << endl;
    root->right = buildTree(root->right);
    return root;
}

queue<node*> levelOrderTraversal(node* &root)
{

    queue<node*> q;

    q.push(root);
    q.push(NULL);
    

  while (!q.empty())
  {
    node* temp = q.front();
    q.pop();
       if (temp == NULL)
    {
        cout << endl;

        if (!q.empty())
        {
            // queue is not empty
            q.push(NULL);
        }
    }
    else
    {

        cout << temp->data << " ";

        // for left part
        if (temp->left)
        {
            q.push(temp->left);
        }

        if ((temp->right))
        {
            q.push(temp->right);
        }
    }
  }
 return q; 
}

void inorder (node* root) {

    if(root == NULL) {
        return;
    }

    //lnr
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void pretorder (node* root) {

    if(root == NULL) {
        return;
    }

    //nlr
    cout << root->data << " ";
    pretorder(root->left);
    
    pretorder(root->right);
}
void postorder (node* root) {

    if(root == NULL) {
        return;
    }

    //nlr
    cout << root->data << " ";
    postorder(root->left);
    
    postorder(root->right);
}

int main()
{

    node *root = NULL;

    root = buildTree(root);
     queue<node*> q=levelOrderTraversal(root);
     vector<node*> temp;
     for(int i = 0; i<q.size() ; i--) {
       temp[i]=q.back();
     }

     reverse(temp.begin(),temp.end());
    // cout << "after" << endl;
//    inorder(root); cout<< endl;
//   pretorder(root);cout<< endl;
//   postorder(root);  

    return 0;
}