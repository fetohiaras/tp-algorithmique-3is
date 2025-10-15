#include <iostream>

using namespace std;

const int MAX = 100;

struct StackArray {
    int data[MAX + 1];  
    int top;            
};

void stackInit(StackArray& stack) {
    stack.top = 0;
}

void push(StackArray& stack, int value) {
    if (stack.top == MAX) {
        cout << "Stack is full" << endl;
    } else {
        stack.top++;
        stack.data[stack.top] = value;
    }
}

int pop(StackArray& stack) {
    if (stack.top == 0) {
        cout << "Stack is empty" << endl;
        return 0;  
    } else {
        int value = stack.data[stack.top];
        stack.top--;
        return value;
    }
}

int main() {
    StackArray myStack;
    stackInit(myStack);
    
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    
    cout << "Current sum: " << myStack.data[myStack.top] << endl;  
    
    cout << "Pop: " << pop(myStack) << endl;  
    cout << "Pop: " << pop(myStack) << endl; 
    
    cout << "Pop: " << pop(myStack) << endl;  
    pop(myStack);  
    
    for (int i = 1; i <= MAX + 1; i++) {
        push(myStack, i);
    }  
    
    return 0;
}