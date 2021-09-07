#include<iostream>
#include <cinttypes>
using namespace std;

struct Node {
    int data;
    Node *xnode;

    Node (int x) {
        data = x;
        xnode = NULL;
    }
};

// return XORed vaule of the node addresses
Node *XOR(Node *x, Node *y) {
    return reinterpret_cast<Node *>(reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y));
}

void insert(Node **headRef, int data) {
    Node *new_node = new Node(data);
    
    // new node is inserted at the start,/
    // so its xnode will be XOR of *headRef and NULL
    new_node->xnode = *headRef;

    // if linked list is not empty, then
    // update xnode of *headRef to be XOR 
    // of new_node and current xnode
    if (*headRef != NULL) {
        (*headRef)->xnode = XOR(new_node, (*headRef)->xnode);
    } 

    // update headRef
    *headRef = new_node;
}

void printList(Node *head) {
    Node *current = head;
    Node *prev = NULL;
    Node *next;

    while (current != NULL) {
        cout << current->data << " ";
        next = XOR(prev, current->xnode);
        prev = current;
        current = next;
    }
    cout << endl;
}

int main()
{
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 100);
    insert(&head, 1000);
    insert(&head, 10000);
 
    // Printing the created list
    printList(head);
 
    return (0);
}