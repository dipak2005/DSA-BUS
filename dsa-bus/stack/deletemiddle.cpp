/*
#include <bits/stdc++.h> 

void solve(stack<int>&inputStack, int N,int count) {

 // base case

   if(count == N/2){
      inputStack.pop();
      return;
   }
   int num =inputStack.top();
    inputStack.pop();

   // recursive call lagayenge
   solve(inputStack,N,count+1);

   inputStack.push(num);
}
void deleteMiddle(stack<int>&inputStack, int N){
	
   int count = 0;
   solve(inputStack,N,count);
   
}
*/
/*


*/