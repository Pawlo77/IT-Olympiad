#include <iostream>
using namespace std;

struct Node {
    struct Node *next;
    int data;
};

void Insert(Node **head, Node *new_node) {
    if (*head == NULL || (*head)->data >= new_node->data) {
        new_node->next = *head;
        *head = new_node;
    }
    else {
        Node *current = *head;
        while (current->next != NULL && current->next->data < new_node->data)
            current = current->next;

        new_node->next = current->next;
        current->next = new_node;
    }
}

Node *insertion_sort(Node *head) {
    Node *sorted = NULL;
    Node *current = head;

    while (current != NULL) {
        Node *next = current->next;
        Insert(&sorted, current);
        current = next;
    }

    return sorted;
}

/* Utility functions */
void push(Node **head, int data) {
    if (*head == NULL) {
        *head = new Node;
        (*head)->data = data;
        (*head)->next = NULL;
        return;
    }
    Node *temp = new Node;
    temp->data = (*head)->data;
    temp->next = (*head)->next;
    (*head)->next = temp;
    (*head)->data = data;
}

void print(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node *head = NULL;
    push(&head, 5);
    push(&head, 20);
    push(&head, 4);
    push(&head, 3);
    push(&head, 30);

    cout << "Before: ";
    print(head);
    head = insertion_sort(head);
    cout << "After: ";
    print(head);


    return 0;
}