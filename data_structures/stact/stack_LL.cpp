#include <iostream>
using namespace std;

#define MAX 1000

struct StackNode {
    int data;
    StackNode *next;

    StackNode(int x) { data = x; next = NULL; }
};

class Stack {
    StackNode *root;
    int size;
public:
    Stack() { root = NULL; size = 0; }
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

bool Stack::push(int x) { 
    if (size + 1 > MAX) return false; // overflow

    if (isEmpty())
        root = new StackNode(x);
    else {
        StackNode *newNode = new StackNode(x);
        newNode->next = root;
        root = newNode;
    }
    size++;
    return true;
}
int Stack::pop() { 
    if (isEmpty()) return -1; // stack is empty
    int out = root->data;
    root = root->next;
    size--;
    return out;
}

int Stack::peek() {
    return isEmpty() ? -1 : root->data;
}

bool Stack::isEmpty() {
    return size <= 0;
}

int main()
{
    class Stack s;
 
    s.push(10);
    s.push(20);
    s.push(30);
 
    cout << s.pop() << " popped from stack\n";
 
    cout << "Top element is " << s.peek() << endl;
     
    cout<<"Elements present in stack : ";
     //print all elements in stack :
    while(!s.isEmpty())
    {
        // print top element in stack
        cout<<s.peek()<<" ";
        // remove top element in stack
        s.pop();
    }
 
    return 0;
}