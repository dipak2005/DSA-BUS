#include<iostream>
#include<queue>
#include<stack>
// User function Template for C++

class Solution
{
    public:
    
    // Function to reverse first k elements of a queue.
    queue<int> modifyQueue(queue<int> q, int k) {
       
       
       stack<int> s;
       
       int i=0;
       while(i<k)
       {
           int ans = q.front();
           q.pop();
           s.push(ans);
           i++;
       }
       
       
       while(!s.empty()) {
           int ans = s.top();
           s.pop();
           q.push(ans);
           i++;
       }
       
       int last = q.size()-k;
       while(last--)
       {
           int ans = q.front();
           q.pop();
           q.push(ans);
       }
       return q;
    }
};