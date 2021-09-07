#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node (int x) {
        data = x;
        next = NULL;
    }
};

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

/* Function to print nodes in a given Circular linked list */
void printList(Node* head) {
    Node* temp = head;
 
    // If linked list is not empty
    if (head != NULL) {
        // Print nodes till we reach first node again
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
    }
}

// splits circular list into two circular lists
// if number of elements is odd, first one is larger
void splitList(Node *head, Node **head1_ref, Node **head2_ref) {
    Node *slow = head, *fast = head;
    
    while (fast->next != head && fast->next->next != head) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // case when there are even elements in list
    if (fast->next->next == head) fast = fast->next;
    
    *head1_ref = head;
    *head2_ref = slow->next;
    
    slow->next = head;
    fast->next = *head2_ref;
}

// assumption: head node is the smallest node
Node *sortedInsert(Node* head, int data) {
    Node *new_node = new Node(data);
        
    // case whem list is empty
    if (head == NULL) {
        new_node->next = head;
        return new_node;
    }

    // insert before head
    if (data < head->data) {
        swap(&new_node->data, &head->data);
        new_node->next = head->next;
        head->next = new_node;
        return head;
    }

    Node *current = head;
    while (current->next->data < data && current->next != head) {
        current = current->next;
    }

    new_node->next = current->next;
    current->next = new_node;

    return head;
}