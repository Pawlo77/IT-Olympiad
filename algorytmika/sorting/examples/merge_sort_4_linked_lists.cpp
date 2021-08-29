#include<iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node *next;
};

Node *
merge(Node *head, Node *mid) {
    Node *merged = new Node;
    Node *temp = new Node;

    merged = temp;
    while (head != NULL && mid != NULL) {
        if (head->data <= mid->data) {
            temp->next = head;
            head = head->next;
        }
        else {
            temp->next = mid;
            mid = mid->next;
        }
        temp = temp->next;
    }

    while (head != NULL) {
        temp->next = head;
        head = head->next;
        temp = temp->next;
    }
    while (mid != NULL) {
        temp->next = mid;
        mid = mid->next;
        temp = temp->next;
    }

    // return head of the sorted list
    return merged->next;
}

Node *
get_mid(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while (slow->next != NULL && (fast != NULL && fast->next != NULL)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *
sort(Node *head) {
    if (head->next == NULL)
        return head;

    Node *mid = new Node;
    mid = get_mid(head);

    Node *head2 = new Node;
    head2 = mid->next; // begining of second sublist

    mid->next = NULL; // unlink both sublists

    Node *final = merge(sort(head), sort(head2));
    return final;
}

/* Utility functions */
void
insert(int x, Node **head) {
    if (*head == NULL) {
        *head = new Node;
        (*head)->data = x;
        (*head)->next = NULL;
        return;
    }
    Node *temp = new Node;
    temp->data = (*head)->data;
    temp->next = (*head)->next;
    (*head)->data = x;
    (*head)->next = temp;
}
void
print(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int
main() {
    Node *head = NULL;
    int n[] = {7, 10, 5, 20, 3, 2};
    for (int i = 0; i < 6; i++) {
        insert(n[i], &head); // inserting in the list
    }
    cout << "\nSorted Linked List is: \n";
    print(sort(head)); // printing the sorted list returned by sort()
    return 0;
}