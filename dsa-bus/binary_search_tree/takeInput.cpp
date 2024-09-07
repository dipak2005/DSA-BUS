#include <iostream>
#include <queue>
using namespace std;

class Node
{

public:
  int data;
  Node *left;
  Node *right;

  // constructor
  Node(int d)
  {
    this->data = d;
    this->left = NULL;
    this->right = NULL;
  }
};
Node *minValue(Node *&root)
{

  if (root == NULL)
  {
    return root;
  }

  Node *temp = root;

  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp;
}
Node* deletefromBst(Node *root, int val)
{

  // base case
  if (root == NULL)
  {
    return root;
  }

  if (root->data == val)
  {
    // 0 child
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }
    // 1 child
    // left part exists
    if (root->left != NULL && root->right == NULL)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // right part exists
    if (root->right != NULL && root->left == NULL)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    if (root->left != NULL && root->right != NULL)
    {
     Node* mini = minValue(root->right);
     int minival=mini->data;
      root->data = minival;

      root->right = deletefromBst(root->right, minival);
      return root;
    }
  }
  else if (root->data > val)
  {
    root->left = deletefromBst(root->left, val);
    return root;
  }
  else
  {
    root->right = deletefromBst(root->right, val);
    return root;
  }
}
Node *successer(Node *root, Node *node)
{

  if (node->right)
  {
    Node *currenet = node->right;
    while (currenet->left)
    {
      currenet = currenet->left;
    }
    return currenet;
  }

  Node *predecesser = NULL;
  Node *current = root;
  while (current)
  {
    if (node->data > current->data)
    {
      predecesser = current;
      current = current->right;
    }
    else if (node->data < current->data)
    {
      current = current->left;
    }
    else
    {
      break;
    }
  }
  return predecesser;
}
Node *predesser(Node *root, Node *node)
{

  if (node->left)
  {
    Node *currenet = node->left;
    while (currenet->right)
    {
      currenet = currenet->right;
    }
    return currenet;
  }

  Node *predecesser = NULL;
  Node *current = root;
  while (current)
  {
    if (node->data > current->data)
    {
      predecesser = current;
      current = current->right;
    }
    else if (node->data < current->data)
    {
      current = current->left;
    }
    else
    {
      break;
    }
  }
  return predecesser;
}

int successer(Node *&root, int data)
{

  if (root->data == -1)
  {
    return -1;
  }

  Node *temp = root;

  while (temp->data != data)
  {
    if (data < temp->data)
    {
      temp = temp->left;
    }
    temp = temp->right;
  }
  return temp->data;
}

Node *maxValue(Node *&root)
{

  if (root == NULL)
  {
    return root;
  }
  Node *temp = root;
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp;
}


void inOrder(Node *root)
{

  if (root == NULL)
  {
    return;
  }

  // lnr
  inOrder(root->left);
  cout << root->data << " ";
  inOrder(root->right);
}

void preOrder(Node *root)
{
  if (root == NULL)
  {
    return;
  }

  // nlr
  cout << root->data << " ";
  preOrder(root->left);
  preOrder(root->right);
}

void postOrder(Node *root)
{

  if (root == NULL)
  {
    return;
  }
  // lrn
  postOrder(root->left);
  postOrder(root->right);
  cout << root->data << " ";
}

void levelOrderTraversal(Node *&root)
{

  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  while (!q.empty())
  {
    Node *node = q.front();
    q.pop();

    if (node == NULL)
    {
      cout << endl;

      if (!q.empty())
      {
        q.push(NULL);
      }
    }
    else
    {
      cout << node->data << " ";
      if (node->left)
      {
        q.push(node->left);
      }

      if (node->right)
      {
        q.push(node->right);
      }
    }
  }
}
void insertIntoBSt(Node *&root, int d)
{

  if (root == NULL)
  {
    root = new Node(d);
    return;
  }

  if (d > root->data)
  {
    // root->right=
    insertIntoBSt(root->right, d);
  }
  else
  {
    // root->left=
    insertIntoBSt(root->left, d);
  }
  // return root;
}

void takeInput(Node *&root)
{

  int data;
  cin >> data;
  while (data != -1)
  {
    //  root =
    insertIntoBSt(root, data);
    cin >> data;
  }
}

int main()
{

  Node *root = NULL;
  takeInput(root);

  cout << "print" << endl;
  levelOrderTraversal(root);

  cout << "print inorder" << endl;
  inOrder(root);

  cout << "print preOrder" << endl;
  preOrder(root);

  cout << "print postrder" << endl;
  postOrder(root);

  Node *minvalue = minValue(root);
  cout << "min value of tree : " << minvalue->data << endl;
  Node *maxvalue = maxValue(root);
  cout << "max value of tree : " << maxvalue->data << endl;

  cout << endl;
  Node *predeser = predesser(root, root->left);
  cout << "predeser value of tree : " << predeser->data << endl;

  Node *succeser = successer(root, root->right);
  cout << "succeser value of tree : " << succeser->data << endl;

// deletion
 root= deletefromBst(root, 21);

 cout << "print" << endl;
  levelOrderTraversal(root);

  cout << "print inorder" << endl;
  inOrder(root);

  cout << "print preOrder" << endl;
  preOrder(root);

  cout << "print postrder" << endl;
  postOrder(root);

  

}
