// rotate array a of size n by d positions

void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// o(n) time, o(d) space solution
void rotate(int a[], int n, int d) {
    // to handle d >= n
    d = d % n;
    int temp[d];
    for (int i = 0; i < d; i++)
        temp[i] = a[i];
        
    for (int i = d; i < n; i++)
        a[i - d] = a[i];
    
    int idx = 0;
    for (int i = n - d; i < n; i++)
        a[i] = temp[idx++];
}

// o(n * d) time, o(1) space solution
void rotate2(int a[], int n, int d) {
    // to handle d >= n
    d = d % n;
    for (int i = 0; i < d; i++) {
	    int temp = a[0];
        for (int j = 0; j < n - 1; j++)
            a[j] = a[j + 1];
        a[n - 1] = temp;
    }
}

int gcd(int a, int b) {
    if (b == 0)
        return a;
        
    return gcd(b, a % b);
}

// o(n) time, o(1) space solution - juggling algorithm
void rotate3(int a[], int n, int d) {
    // to handle d >= n
    d = d % n;
    int size = gcd(d, n);
        
    for (int i = 0; i < size; i++) {
        int temp = a[i];
        int prev = i;
        
        while (1) {
            int next = prev + d;
            if (next >= n) next = next - n;
            if (next == i) break;
            
            a[prev] = a[next];
            prev = next;
        }
        
        a[prev] = temp;
    }
}

void reverse(int a[], int l, int r) {
    while (l < r) {
        swap(&a[l], &a[r]);
        l++; r--;
    }
}

// o(n) time, o(1) space solution
void rotate4(int a[], int n, int d) {
    // to handle d >= n
    d = d % n;
    
    reverse(a, 0, d - 1);
    reverse(a, d, n - 1);
    reverse(a, 0, n - 1);
}