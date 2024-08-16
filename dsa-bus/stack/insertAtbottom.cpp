/*
#include <bits/stdc++.h> 
  bool solve(stack<int>& myStack, int x){

 // base case
   if(myStack.empty()){
      myStack.push(x);
      return true;
  }

    int num = myStack.top();
    myStack.pop();

   solve(myStack,x);

   myStack.push(num);
   return false;
  }
  
 
stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
  solve(myStack,x);
return myStack;
}

*/