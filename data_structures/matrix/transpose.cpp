#include <bits/stdc++.h>
#define HASH_SIZE 128

using namespace std;

void swap(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void print(int a[], int r, int c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++)
            printf("%4d", a[i * c + j]);
        cout << endl;
    }
    cout << endl;
}

// function to matrix inplace transpose
void MatrixInplaceTranspose(int a[], int r, int c)  {
    int size = r * c - 1;

    int temp, next, cycleBegin;
    bitset<HASH_SIZE> map;
    map.reset();
    map[0] = map[size] = 1;

    int i = 1;
    while (i < size) {
        cycleBegin = i;
        temp = a[i];

        do {
            next = (i * r) % size;
            swap(&a[next], &temp);
            map[i] = 1;
            i = next;
        }
        while (i != cycleBegin);

        for (i = 1; i < size && map[i]; i++) ;
    }
}

int main() { 
    int r = 5, c = 6;
    int a[r * c];

    for (int i = 0; i < r * c; i++) 
        a[i] = i + 1;

    print(a, r, c);
    MatrixInplaceTranspose(a, r, c);
    print(a, c, r);


    return 0;
}