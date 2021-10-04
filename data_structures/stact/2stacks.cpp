#include <iostream>

using namespace std;

#define SIZE 200

/* efficient implementation of 
2 seperate stacks in one array */

class Stack {
    int arr[SIZE];
    int top1 = -1;
    int top2 = SIZE;
public:
    bool push1(int x) {
        if (top1 + 1 != top2)
            arr[++top1] = x;
            return true;
        return false;
    }
    bool push2(int x) {
        if (top1 + 1 != top2)
            arr[--top1] = x;
            return true;
        return false;
    }
    int pop1() {
        if (top1 > -1)
            return arr[top1--];
        return -1;
    }
    int pop2() {
        if (top2 < SIZE)
            return arr[top2++];
        return -1;
    }
};