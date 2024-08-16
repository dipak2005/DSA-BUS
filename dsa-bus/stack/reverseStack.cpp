/*
bool solve(stack<int> &stack,int element ){

 //base case
    if(stack.empty()){
     stack.push(element);
     return true;
 }
   
   int num= stack.top();
   stack.pop();

    solve(stack, element);
   stack.push(num);
   return false;
}

void reverseStack(stack<int> &stack) {

if(stack.empty()){
    return;
}

   int num= stack.top();
    stack.pop();

   
   reverseStack(stack);
   
    solve(stack,num);
}
*/