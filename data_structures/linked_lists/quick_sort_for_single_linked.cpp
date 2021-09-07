#include <iostream>
using namespace std;

/* a node of the singly linked list */
struct node {
  int data;
  struct node *next;

  node(int x) {
    data = x;
    next = NULL;
  }
};

struct node *partition(struct node *head, struct node *tail, 
                        struct node **newHead, struct node **newTail) {
    struct node *pivot = tail;
    struct node *prev = NULL;

    while (head != pivot) {
        if (head->data < pivot->data) {
            
            // if head doesn't exist, set it
            if (*newHead == NULL) {
                *newHead = head;
            }
            prev = head;
            head = head->next;
        }
        else {
            if (prev) {
                prev->next = head->next;
            }
            struct node *temp = head->next;
            head->next = NULL;
            tail->next = head;
            tail = tail->next;
            
            head = temp;
        }
    }
    
    if (*newHead == NULL) {
        *newHead = pivot;
    }
    *newTail = tail;
    return pivot;
}

struct node *get_tail(struct node *head) {
    while (head != NULL && head->next != NULL) {
        head = head->next;
    }
    return head;
}

struct node *sort(struct node *head, struct node *tail) {
    if (!head || head == tail) {
        return head;
    }
    
    struct node *newHead = NULL, *newTail = NULL;
    struct node *pivot = partition(head, tail, &newHead, &newTail);
    
    // if pivot is smallest - no nodes on left - no need to recurr
    if (pivot != newHead) {
        struct node *temp = newHead;
        while (temp->next != pivot) {
            temp = temp->next;
        }
        temp->next = NULL; // unlink 
        
        // recurr
        newHead = sort(newHead, temp);
        
        temp = get_tail(newHead);
        temp->next = pivot; // link back
    }
    
    pivot->next = sort(pivot->next, newTail);
    
    return newHead;
}

//you have to complete this function
void quickSort(struct node **headRef) {
    *headRef = sort(*headRef, get_tail(*headRef));
}
