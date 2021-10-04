string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> map;
    
    // put both tables in m
    for (int i = 0; i < n; i++)
        map[a1[i]] = 1;
    for (int i = 0; i < m; i++)
        if (map[a2[i]] != 1)
            return "No";
    return "Yes";
}

Node* findIntersection(Node* head1, Node* head2) {
    unordered_map<int, int> m;
    
    Node *head = head1;
    while (head1 != NULL) {
        m[head1->data] = 1;
        head1 = head1->next;
    }
    
    Node *result = NULL, *current;
    while (head2 != NULL) {
        m[head2->data] = m[head2->data] == 1 ? 2: 1;
        head2 = head2->next;
    }
    
    while (head != NULL) {
        if (m[head->data] > 1) {
            if (result == NULL) {
                result = head;
                current = result;
            }
            else {
                current->next = head;
                current = current->next;
            }
        }
        head = head->next;
    }
    current->next = NULL;
    
    return result;
}

// Function to check if array has 2 elements
// whose sum is equal to the given value
bool hasArrayTwoCandidates(int arr[], int n, int x) {
    unordered_map<int, bool> m;
    
    for (int i = 0; i < n; i++) {
        if (m[x - arr[i]] == 1) return 1;
        m[arr[i]] = 1;
    }
    return 0;
}

bool checkDuplicatesWithinK(int arr[], int n, int k) {
    // Creates an empty hashset
    unordered_set<int> myset;
 
    // Traverse the input array
    for (int i = 0; i < n; i++)
    {
        // If already present n hash, then we found
        // a duplicate within k distance
        if (myset.find(arr[i]) != myset.end())
            return true;
 
        // Add this item to hashset
        myset.insert(arr[i]);
 
        // Remove the k+1 distant item
        if (i >= k)
            myset.erase(arr[i-k]);
    }
    return false;
}