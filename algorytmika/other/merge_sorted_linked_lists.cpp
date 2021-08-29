// { Driver Code Starts
//Initial Template for C
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <bits/stdc++.h>

using namespace std;

/* Link list node */
struct Node
{
	int data;
	struct Node* next;
};

/* join 2 sorted linked lists maintainig sorted order */
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
    struct Node* head;
    if (a == NULL && b == NULL) return NULL;
    else if (a == NULL) return b;
    else if (b == NULL) return a;

    if (a->data >= b->data) {
        head = b;
        b = b->next;
    }
    else {
        head = a;
        a = a->next;
    }
    
    struct Node* current = head;
    while (a != NULL && b != NULL) {
        if (a->data < b->data) {
            current->next = a;
            a = a->next;
        }
        else {
            current->next = b;
            b = b->next;
        }
        current = current->next;
    }
    
    // use remainings of a and b
    while (a != NULL) {
        current->next = a;
        current = a;
        a = a->next;
    }
    while (b != NULL) {
        current->next = b;
        current = b;
        b = b->next;
    }
    
    return head;
}
