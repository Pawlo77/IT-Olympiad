#include <iostream>
using namespace std;

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

struct node {
    public:
    int data;
      struct node *next;
      struct node *prev;
};

struct node *get_tail(node *head) {
    while(head && head->next) head = head->next;
    return head;
}

node *partition(node *l, node*h) {
    node *pivot = h;
    node *last = l->prev;

    for (node *current = l; current != pivot; current = current->next) {
        if (current->data <= pivot->data) {
            last = (last == NULL) ? l: last->next;

            swap(&(last->data), &(current->data));
        }
    }

    last = (last == NULL) ? l: last->next;
    swap(&(last->data), &(pivot->data));
    return last;
}

void quickSort(node *l, node *h) {
    if (h != NULL && l != h && l != h->next) {
        node *pivot = partition(l, h);

        quickSort(l, pivot->prev);
        quickSort(pivot->next, h);
    }
}

void sort(node *head) {
    quickSort(head, get_tail(head));
}

void printList(node *head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void push(node **headRef, int data) {
    node *new_node = new node;
    new_node->next = *headRef;
    new_node->prev = NULL;
    new_node->data = data;

    if (*headRef != NULL) {
        (*headRef)->prev = new_node;
    }

    *headRef = new_node;
}

int main()
{
    node *a = NULL;
    push(&a, 5);
    push(&a, 20);
    push(&a, 4);
    push(&a, 3);
    push(&a, 30);
 
    cout << "Linked List before sorting \n";
    printList(a);
 
    sort(a);
 
    cout << "Linked List after sorting \n";
    printList(a);
 
    return 0;
}