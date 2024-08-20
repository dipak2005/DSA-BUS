#include <iostream>
#include <queue>
using namespace std;

class Stack {
    queue<int> q1, q2;  // Two queues to implement the stack

public:
    // Push an element onto the stack
    void push(int x) {
        // Push x to q2
        q2.push(x);

        // Move all elements from q1 to q2
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        // Swap the names of q1 and q2
        swap(q1, q2);
    }

    // Remove the element on top of the stack
    void pop() {
        if (q1.empty())
            return;
        q1.pop();
    }

    // Get the top element of the stack
    int top() {
        if (q1.empty())
            return -1;
        return q1.front();
    }

    // Check if the stack is empty
    bool empty() {
        return q1.empty();
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element: " << s.top() << endl; // Output: 30
    s.pop();
    cout << "Top element after pop: " << s.top() << endl; // Output: 20

    return 0;
}
