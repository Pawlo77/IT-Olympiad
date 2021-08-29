#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
};

Node *getTail(Node *head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

Node *partition(Node *head, Node *tail, Node **newHead, Node **newTail) {
    Node *pivot = tail;
    Node *prev = NULL, *current = head;

    while (current != pivot) {
        if (current->data < pivot->data) {
            // first node with value smaller than pivot becomes the head
            if (*newHead == NULL) 
                *newHead = current;
            prev = current;
            current = current->next;
        }
        else {
            // move current to the tail

            if (prev)
                // cover the whole it leaves
                prev->next = current->next;
            
            Node *temp = current->next;
            current->next = NULL;
            tail->next = current;
            tail = tail->next;
            current = temp;
        }
    }

    // if pivot is the smallest, it becomes the head
    if (*newHead == NULL)
        *newHead = pivot;
    *newTail = tail;

    return pivot;
}

Node *quickSort(Node *head, Node *tail) {
    if (head == NULL || head == tail)
        return head;

    Node *newHead = NULL, *newTail = NULL;
    Node *pivot = partition(head, tail, &newHead, &newTail);

    if (newHead != pivot) {
        // if pivot is not the smallest, recurr for left part
        Node *temp = newHead;

        while (temp->next != pivot)
            temp = temp->next;
        temp->next = NULL;

        newHead = quickSort(newHead, temp);

        temp = getTail(newHead);
        temp->next = pivot;
    }
    // recurr for right part
    pivot->next = quickSort(pivot->next, newTail);

    return newHead;
}

void sort(Node **NodeRef) {
    Node *head = *NodeRef;

    *NodeRef = quickSort(head, getTail(head));
}

/* A utility functions */
void
push(struct Node **head_ref, int new_data) {
    /* allocate node */
    struct Node *new_node = new Node;

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}
void
printList(struct Node *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

// Driver code
int main()
{
    struct Node* a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
    push(&a, 330);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    sort(&a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}