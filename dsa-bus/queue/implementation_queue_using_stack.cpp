#include<iostream>
#include<stack>
using namespace std;
class Queue {
 
    stack<int> s1,s2;

    public:
    
    void push(int x) {
     
       s1.push(x);
       
       while (!s1.empty())
       {
          s2.push(s1.top());
       }
       
    }

};

int main () {

    Queue q;

    
    return 0;
}