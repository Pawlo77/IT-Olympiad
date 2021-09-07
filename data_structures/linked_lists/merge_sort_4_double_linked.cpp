struct Node
{
	int data;
	struct Node *next, *prev;
	
	Node (int x){
	    data = x;
	    next = NULL;
	    prev = NULL;
	}
};

void insert(struct Node **head, int data)
{
	struct Node *temp = new Node (data);
	if (!(*head))
		(*head) = temp;
	else
	{
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

struct Node *split(struct Node *head) {
    struct Node *slow = head;
    struct Node *fast = head;
    
    while (fast->next && fast->next->next) {
        fast = fast->next->next;
        slow = slow->next;
    }
    
    struct Node *temp = slow->next;
    slow->next = NULL;
    return temp;
}

struct Node *merge(struct Node *head, struct Node *mid) {
    if (!head)
        return mid;
    if (!mid)
        return head;
        
    if (head->data < mid->data) {
        head->next = merge(head->next, mid);
        head->next->prev = head;
        head->prev = NULL;
        return head;
    }
    mid->next = merge(head, mid->next);
    mid->next->prev = mid;
    mid->prev = NULL;
    return mid;
}

//Function to sort the given doubly linked list using Merge Sort.
struct Node *sortDoubly(struct Node *head)
{
    if (!head || !head->next)
        return head;
        
    struct Node *mid = split(head);
	head = sortDoubly(head);
	mid = sortDoubly(mid);
	
	return merge(head, mid);
}