#include <iostream>
#include <stdlib.h>
#include <stack>
#include <vector>
 
using namespace std;

/* 
design a special stack that will
be able to return min value in O(1)

solution - use 2 stack, one to store
accual stack and second to store minimum values
*/

class Stack {
    private:
        static const int max = 100;
        int arr[max];
        int top;
    public:
        Stack() {
            top = -1;
        }

        bool isEmpty();
        bool isFull();
        int pop();
        void push(int x);
};

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull() {
    return top == max - 1;
}

void Stack::push(int x) {
    if (!isFull())
        arr[++top] = x;
    else {
        cout << "overflow" << endl;
        abort();
    }
}

int Stack::pop() {
    if (!isEmpty())
        return arr[top--];
    cout << "underfrow";
    abort();
}

class SpecialStack : public Stack {
    Stack min;

    public:
        int pop();
        void push(int x);
        int getMin();
};

void SpecialStack::push(int x)
{
    if (isEmpty()) {
        Stack::push(x);
        min.push(x);
    }
    else {
        Stack::push(x);
        int y = min.pop();
        min.push(y);
        if (x <= y)
            min.push(x);
    }
}

int SpecialStack::pop() {
    int x = Stack::pop();
    int y = min.pop();

    if (y != x) 
        min.push(y);
    return x;
}

int SpecialStack::getMin() {
    int x = min.pop();
    min.push(x);
    return x;
}

/*----------------------------------------------------------------*/
//optimalized version to work in O(1) space

class SpecialStack2
{
    // Sentinel value for min
    int min = -1; 
     
    // DEMO_VALUE - the algo will fail if we insert to stack 
    // its equivalent
    static const int demoVal = 9999;
    stack<int> st;
 
public:
 
    int getMin() {
        return min;
    }
 
    void push(int val) {
        // If stack is empty OR current element
        // is less than min, update min.
        if (st.empty() || val < min)
            min = val;
         
        // Encode the current value with
        // demoVal, combine with min and
        // insert into stack
        st.push(val * demoVal + min);
    }
 
    int pop() {   
        // if stack is empty return -1;
        if ( st.empty() ) {
          cout << "stack underflow" << endl ;
          abort();
        }
       
        int val = st.top();
        st.pop();
         
        // If stack is empty, there would
        // be no min value present, so
        // make min as -1
        if (!st.empty())
            min = st.top() % demoVal;
        else
            min = -1;
             
        // Decode actual value from
        // encoded value
        return val / demoVal;
    }
 
    int peek() {
        // Decode actual value
        // from encoded value
        return st.top() / demoVal;
    }
};

int main()
{
    SpecialStack2 s;
 
    vector<int> arr = { 3, 2, 6, 1, 8, 5, 5, 5, 5 };
 
    for(int i = 0; i < arr.size(); i++)
        s.push(arr[i]);
     
    for(int i = 0; i < arr.size(); i++) {
        s.pop();
        cout << s.getMin() << endl;
    }

    return 0;
}