#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;

    Node (int x) {
        data = x;
        prev = next = NULL;
    }
};

void push (Node **headRef, int data) {
    Node *new_node = new Node(data);

    if (*headRef != NULL) {
        (*headRef)->prev = new_node;
        new_node->next = *headRef;
    }
    *headRef = new_node;
}

void append(Node **headRef, int data) {
    Node *new_node = new Node(data);

    if (*headRef == NULL) {
        *headRef = new_node;
        return;
    }

    Node *current = *headRef;
    while (current->next != NULL) current = current->next;
    current->next = new_node;
    new_node->prev = current;
}

// insert after given Node choosen
void insertAfter(Node *choosen, int data) {
    if (choosen == NULL) return; // choosen cannot be NULL

    Node* new_node = new Node(data);
    new_node->next = choosen->next;
    choosen->next = new_node;
    new_node->prev = choosen;
    
    if (new_node->next != NULL) new_node->next->prev = new_node;
}

// insert before given Node choosen
void insertBefore(Node **headRef, Node *choosen, int data) {
    if (choosen == NULL) return; // head cannot be NULL

    Node *new_node = new Node(data);
    new_node->next = choosen;
    new_node->prev = choosen->prev;
    choosen->prev = new_node;
    
    if (new_node->prev != NULL) new_node->prev->next = new_node;
    else *headRef = new_node; // we have new head
}   

// add node after the given position pos (indexing from 0)
// 0 <= pos < length of linked list
void insertOnIdx(Node *head, int pos, int data)
{
    Node *new_node = new Node(data);

    for (int i = 0; i < pos; i++) head = head->next;
    
    new_node->prev = head;
    new_node->next = head->next;
    
    if (head->next != NULL) head->next->prev = new_node;
    
    head->next = new_node;
}

void deleteNode(Node **headRef, Node *del) {
    if (*headRef == NULL || del == NULL) return;

    if (*headRef == del) *headRef = del->next;

    if (del->next != NULL) del->next->prev = del->prev;
    if (del->prev != NULL) del->prev->next = del->next;
    free(del);
}

Node *reverse(Node *head) {
    Node *temp = NULL;
    Node *current = head;
    
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;            
        current = current->prev;
    }
     
    return (temp == NULL) ? head: temp->prev;
}