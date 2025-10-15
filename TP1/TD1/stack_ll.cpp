#include <iostream>
#include <memory>

using namespace std;

struct Node {
    int value;  
    unique_ptr<Node> next;  
};

struct StackLinked {  
    unique_ptr<Node> top;
};   

void StackInit(StackLinked& stack) {  
    stack.top = nullptr;
}

void push(StackLinked& stack, int value) {
    auto newNode = make_unique<Node>();
    newNode->value = value;  
    newNode->next = move(stack.top); 
    stack.top = move(newNode);        
}

int pop(StackLinked& stack) {  
    if (!stack.top) {
        cout << "Stack is empty" << endl;
        return -1; 
    } else {
        int value = stack.top->value;  
        stack.top = move(stack.top->next); 
        return value;
    }
}

int main() {
    StackLinked myStack;  
    StackInit(myStack);  
    
    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);
    
    cout << "Current top: " << myStack.top->value << endl;  
    
    cout << "Pop: " << pop(myStack) << endl;  
    cout << "Pop: " << pop(myStack) << endl;  
    
    cout << "Pop: " << pop(myStack) << endl;  
    pop(myStack); 
    
    for (int i = 1; i <= 100; i++) {
        push(myStack, i);
    }
    cout << "Pop after many Pushes: " << pop(myStack) << endl;  
    
    return 0;
}