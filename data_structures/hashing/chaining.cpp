#include<bits/stdc++.h>
using namespace std;

class Hash {
    private:
        int BUCKET;
        list<int> *table;
    public:
        // constructor
        Hash(int x);

        // inserts a key into the hash table
        void insertItem(int x);

        // deletes a key from the hash table
        void deleteItem(int x);

        int hashFunction(int x) {
            return (x % BUCKET);
        }

        void displayHash();
};

Hash::Hash(int x) {
    BUCKET = x;
    table = new list<int>[BUCKET];
}

void Hash::insertItem(int x) {
    int index = hashFunction(x);
    table[index].push_back(x);
}

void Hash::deleteItem(int x) {
    int index = hashFunction(x);

    // find the hey in (index)th list
    list<int> :: iterator i;
    for (i = table[index].begin(); i != table[index].end(); i++)
        if (*i == x)
            break;

    if (i != table[index].end())
        table[index].erase(i);
}

void Hash::displayHash() {
    for (int i = 0; i < BUCKET; i++) {
        cout << i;
        for (auto x: table[i])
            cout << " --> " << x;
        cout << endl;
    }
}

int main()
{
  // array that contains keys to be mapped
  int a[] = {15, 11, 27, 8, 12};
  int n = sizeof(a)/sizeof(a[0]);
 
  // insert the keys into the hash table
  Hash h(7);   // 7 is count of buckets in
               // hash table
  for (int i = 0; i < n; i++)
    h.insertItem(a[i]); 
 
  // delete 12 from hash table
  h.deleteItem(12);
 
  // display the Hash table
  h.displayHash();
 
  return 0;
}