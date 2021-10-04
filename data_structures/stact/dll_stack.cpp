#include <iostream>

#define MAX 100
using namespace std;

struct DLLNode {
    int data;
    DLLNode *prev;
    DLLNode *next;

    DLLNode(int x) {
        data = x;
        prev = next = NULL;
    }
};

class Stack {
    private:
        DLLNode *head;
        DLLNode *mid;
        int size;
    public:
        Stack () {
            head = mid = NULL;
            size = 0;
        }
        
        void push(int x);
        int pop();
        bool isEmpty();
        bool isFull();
        int peek();
        int peekMid();
        int popMid();

};

bool Stack::isEmpty() {
    return size == 0;
}

bool Stack::isFull() {
    return size == MAX;
}

void Stack::push(int x) {
    if (!isFull()) {
        if (head == NULL)
            head = new DLLNode(x);
        else {
            DLLNode *current = new DLLNode(x);
            current->next = head;
            head->prev = current;
            head = current;
        }
        size++;

        // update mid
        if (size == 1)
            mid = head;
        else if (size % 2 == 0) {
            mid = mid->prev;
        }   
    }
    else {
        cout << "overflow" << endl;
        abort();
    }
}

int Stack::pop() {
    if (!isEmpty()) {
        int t = head->data;
        if (size == 1) {
            head = NULL;
        }
        else {
            head = head->next;
            head->prev = NULL;
        }
        size--;

        // update mid
        if (size % 2 == 0)
            mid = mid->next;

        return t;
    }
    else {
        cout << "underflow" << endl;
        abort();
    }
}

int Stack::popMid() {
    if (!isEmpty()) {
        int t = mid->data;
        size--;
        if (size == 0) {
            // mid is head
            head = mid = NULL;
        }
        else {
            if (mid->prev != NULL)
                mid->prev->next = mid->next;
            if (mid->next != NULL)
                mid->next->prev = mid->prev;

            if (size % 2 == 0) 
                mid = mid->next;
            else 
                mid = mid->prev;
        }
        return t;
    }
    else {
        cout << "underflow" << endl;
        abort();
    }
}

int Stack::peek() {
    if (!isEmpty())
        return head->data;
    return -1;
}

int Stack::peekMid() {
    if (!isEmpty())
        return mid->data;
    return -1;
}

int main()
{
    /* Let us create a stack using push() operation*/
    Stack *st = new Stack();
    st->push(11);
    st->push(22);
    st->push(33);
    st->push(44);
    st->push(55);
    st->push(66);
    st->push(77);

 
    cout << "Item popped is " << st->pop() << endl;
    cout << "Item popped is " << st->pop() << endl;
    cout << "Item popped is " << st->pop() << endl;
    cout << "Current head is " << st->peek() << endl;
    cout << "Middle Element is " << st->peekMid() << endl;
    cout << "Deleted Middle Element is "<< st->popMid() <<endl;
    cout << "Deleted Middle Element is "<< st->popMid() <<endl;
    cout << "Deleted Middle Element is "<< st->popMid() <<endl;
    cout << "Deleted Middle Element is "<< st->popMid() <<endl;
    cout << "Middle Element is " << st->peekMid() << endl;
    return 0;
}
