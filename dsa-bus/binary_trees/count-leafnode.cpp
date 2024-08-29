/**********************************************************

    Following is the Binary Tree Node class structure:

    template <typename T>
    class BinaryTreeNode {
      public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
        }
    };
    
***********************************************************/
void postorder(BinaryTreeNode<int> *root,int &count) {

  if(root == nullptr){
      return; 
  }

   // first for left part
   postorder(root->left,count);

   //second for right part
   postorder(root->right,count);

   // check
   if(root->left == NULL && root->right ==NULL) {
       count++;
   }
   
}
int noOfLeafNodes(BinaryTreeNode<int> *root){
    
    int count = 0;
    postorder(root,count);
    return count;
}