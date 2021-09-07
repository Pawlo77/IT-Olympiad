#include<iostream>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node (int x) {
        data = x;
        next = NULL;
    }
};

void swap(Node*& a, Node*& b) {
    Node* temp = a;
    a = b;
    b = temp;
}

void print(Node *head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

void push(Node **headRef, int x) {
    Node *created = new Node(x);

    if (*headRef == NULL)
        *headRef = created;
    else {
        created->next = *headRef;
        *headRef = created;
    }
}

void deleteNodeByKey(Node **headRef, int key) {
    Node *head = *headRef;
    Node *prev = NULL;

    // if key is in head
    if (head != NULL && head->data == key) {
        *headRef = head->next;
        delete head;
        return;
    }

    while (head != NULL && head->data != key) {
        prev = head;
        head = head->next;
    }

    // key wasn't present
    if (head == NULL) return;

    prev->next = head->next;
    delete head;
}

void deleteNodeByIdx(Node **headRef, int idx) {
    if (!(*headRef)) return; // empty list

    Node *temp = *headRef;
    if (idx == 0) {
        *headRef = (*headRef)->next;
        free(temp);
        return;
    }
    
    for (int i = 0; temp != NULL && i < idx - 1; i++) 
        temp = temp->next;

    if (temp == NULL || temp->next == NULL) return; // out of range

    Node *next = temp->next->next;
    free(temp->next);
    temp->next = next;
}

void swapNodesByKeys(Node **headRef, int x, int y) {
    if (x == y or !(*headRef)) return;

    Node **a = NULL, **b = NULL;

    while (*headRef && (a == NULL || b == NULL)) {
        if ((*headRef)->data == x)
            a = headRef;
        else if ((*headRef)->data == y)
            b = headRef;
        headRef = &((*headRef)->next);
    }

    if (a && b) {
        swap(*a, *b);
        swap(((*a)->next), ((*b)->next));
    }
}

void reverse(Node **headRef) {
    if (*headRef == NULL || (*headRef)->next == NULL) return;
        
        Node *prev = NULL, *current = *headRef, *next = NULL;
        
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        
        *headRef = prev;
}

void move(Node **dest, Node **source) {
    if (*source == NULL) return;
    
    Node *new_node = *source;
    *source = new_node->next;
    new_node->next = *dest;
    *dest = new_node;
}

//Function to merge two sorted linked list.
Node* mergeSorted(Node* head1, Node* head2)  
{  
    Node *result = NULL;
    Node **lastNode = &result;
    
    while (1) {
        if (head1 == NULL) {
            *lastNode = head2;
            break;
        }
        else if (head2 == NULL) {
            *lastNode = head1;
            break;
        }
        
        if (head1->data <= head2->data)
            move(lastNode, &head1);
        else
            move(lastNode, &head2);
            
        lastNode = &((*lastNode)->next);
    }
    
    return result;
}  

Node *reverse (struct Node *head, int k) { 
    if (!head) return NULL;
    
    Node *current = head;
    Node *prev = NULL, *next = NULL;
    int count = 0;
    
    while (current != NULL && count < k) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        count++;
    }
    
    if (next != NULL) 
        head->next = reverse(next, k);
        
    return prev;
}

Node *detectLoop(Node *head) {
        Node *slow = head, *fast = head;
        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) return slow;
        }
        return NULL;
    }
    
//Function to remove a loop in the linked list.
void removeLoop(Node* head) {
    Node *p1 = detectLoop(head);
    if (p1 == NULL) return;

    Node *p2 = p1;
    int i = 1;
    while (p2->next != p1) {
        i++;
        p2 = p2->next;
    }

    p1 = head; p2 = head;
    for (int j = 0; j < i; j++)
        p2 = p2->next;
        
    while (p1 != p2) {
        p1 = p1->next;
        p2 = p2->next;
    }

    while (p2->next != p1) 
        p2 = p2->next;
    p2->next = NULL;
}

void removeLoopOptimalized(Node *head) {
    if (head == NULL || head->next == NULL) return;
        
    Node *slow = head->next, *fast = head->next->next;
    while (fast && fast->next) {
        if (slow == fast) break;
        slow = slow->next;
        fast = fast->next->next;
    }
    
    if (slow == fast) {
        slow = head;
        
        // case when both meet at head    
        if (slow == fast) 
            while (fast->next != slow)
                fast = fast->next;
        else 
            while (fast->next != slow->next) {
                fast = fast->next;
                slow = slow->next;
            }
            
        fast->next = NULL;
    }
}

//Function to sum 2 numbers represented by linked lists
// using stactks in O(n)
Node *addTwoNumbers(Node *head1, Node *head2) {
    stack<Node *> s1, s2, s3;
    // fill s1 with elements from first list
    while (head1 != NULL) {
        s1.push(head1);
        head1 = head1->next;
    }
    // fill s2 with elements from second list
    while (head2 != NULL) {
        s2.push(head2);
        head2 = head2->next;
    }

    int carry = 0;
    while (!s1.empty() && !s2.empty()) {
        int sum = carry + s1.top()->data + s2.top()->data;

        s3.push(new Node(sum % 10));
        carry = sum > 9 ? 1 : 0;
        s1.pop();
        s2.pop();
    }
    while (!s1.empty()) {
        int sum = carry + s1.top()->data;

        s3.push(new Node(sum % 10));
        carry = sum > 9 ? 1 : 0;
        s1.pop();
    }
    while (!s2.empty()) {
        int sum = carry + s2.top()->data;

        s3.push(new Node(sum % 10));
        carry = sum > 9 ? 1 : 0;
        s2.pop();
    }

    if (carry) s3.push(new Node(carry));

    Node *head3 = NULL;
    if (!s3.empty())
        head3 = s3.top();
    while (!s3.empty()) {
        Node *temp = s3.top();
        s3.pop();
        if (!s3.empty()) 
            temp->next = s3.top();
    }
    return head3;

}

//Function to rotate a linked list.
// 0 <= k <= n
Node* rotate(Node *head, int k) {
    if (k == 0) return head;
    
    // find k - 1 node
    Node *current = head;
    for (int i = 0; i < k - 1; i++) {
        current = current->next;
    }
    
    // cese when k == n
    if (current->next == NULL) return head;
    
    Node *newHead = current->next;
    Node *end = newHead;
    current->next = NULL;
    
    while (end->next != NULL) end = end->next;
    end->next = head;
    
    return newHead;
}

int main() {
    Node *head = NULL;
    push(&head, 2);
    push(&head, 3);
    push(&head, 0);
    push(&head, 7);
    push(&head, 7);

    Node *head2 = NULL;
    push(&head2, 0);
    push(&head2, 6);
    push(&head2, 6);
    push(&head2, 9);
    push(&head2, 2);

    Node *result = addTwoNumbers(head, head2);

    print(result);

    return 0;
}