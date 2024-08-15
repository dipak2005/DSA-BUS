#include <iostream>

using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Stack class
class Stack {
private:
    Node* top; // Pointer to the top of the stack

public:
    Stack() {
        top = nullptr; // Initialize an empty stack
    }

    // Push an element onto the stack
    void push(int value) {
        Node* newNode = new Node; // Create a new node
        newNode->data = value;
        newNode->next = top; // Link the new node to the previous top
        top = newNode; // Update the top pointer
    }

    // Pop an element from the stack
    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1; // Error value
        }

        int value = top->data; // Get the value from the top node
        Node* temp = top; // Store the top node temporarily
        top = top->next; // Update the top pointer
        delete temp; // Delete the old top node

        return value;
    }

    // Peek at the top element without popping
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1; // Error value
        }

        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == nullptr;
    }

    // Display the stack contents
    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }

        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Stack stack;

    stack.push(10);
    stack.push(20);
    stack.push(30);

    stack.display();

    cout << "Popped element: " << stack.pop() << endl;

    stack.display();

    cout << "Top element: " << stack.peek() << endl;

    return 0;
}