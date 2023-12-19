// Write a program to implement push and pop operations on a stack using linear 
// array. 
#include <iostream>
using namespace std;
#define MAX_SIZE 10  // Maximum size of the stack
class Stack {
private:
    int top;         // Index of the top element
    int stack[MAX_SIZE];  // Array to store elements

public:
    Stack() { top = -1; }  // Constructor to initialize the stack
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            cout << "Stack Overflow! Cannot push element " << value << endl;
            return;
        }
        stack[++top] = value;  // Increment top and add the element to the stack
        cout << "Element " << value << " pushed to the stack." << endl;
    }
    void pop() {
        if (top == -1) {
            cout << "Stack Underflow! Cannot pop from an empty stack." << endl;
            return;
        }
        cout << "Element " << stack[top--] << " popped from the stack." << endl;  // Remove the top element
    }
};
int main() {
    Stack myStack;
    myStack.push(10);
    myStack.push(20);
    myStack.pop();
    myStack.push(30);
    return 0;
}
