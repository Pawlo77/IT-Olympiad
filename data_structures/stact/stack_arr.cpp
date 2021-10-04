#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
    int arr[MAX]; // Maximum size of Stack
    int top;
 
public:
    Stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) {
    if (top + 1 > MAX - 1) return false; // overflow
    arr[++top] = x;
    return true;
}

int Stack::pop() {
    if (isEmpty()) return -1; // stack is empty
    return arr[top--];
}

int Stack::peek() {
    return isEmpty() ? -1 : arr[top];
}

bool Stack::isEmpty() {
    return top < 0;
}

void insert_at_bottom(Stack *stack, int x) {
    if (stack->isEmpty())
        stack->push(x);
    else {
        int a = stack->peek();
        stack->pop();
        insert_at_bottom(stack, x);
        stack->push(a) ;
    }
}

void sorted_insert(Stack *stack, int x) {
    if (stack->isEmpty() || x > stack->peek())
        stack->push(x);
    else {
        int temp = stack->peek();
        stack->pop();

        sorted_insert(stack, x);
        stack->push(temp);
    }
}

void sort(Stack *stack) {
    if (!stack->isEmpty()) {
        int temp = stack->peek();
        stack->pop();

        sort(stack);
        sorted_insert(stack, temp);
    }
}

void reverse(Stack *stack) {
    if (!stack->isEmpty()) {
        int x = stack->peek();
        stack->pop();

        reverse(stack);

        insert_at_bottom(stack, x);
    }
}

void print(Stack stack) {
    while (!stack.isEmpty()) {
        cout << stack.peek() << ' ';
        stack.pop();
    }
    cout << endl;
}

int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    print(s);
    reverse(&s);
    sort(&s);
    print(s);
 
    return 0;
}