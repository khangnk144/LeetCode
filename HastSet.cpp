#include <iostream>
#include <vector>

using namespace std;

class MyHashSet {
public:
    const int n = 10000;
    vector<vector<int>> arr;

    MyHashSet() {
        arr.resize(n);
    }

    void add(int key) {
        int index = key % n;
        for (int x : arr[index]) {
            if (x == key) return; // Already exists
        }
        arr[index].push_back(key);
    }

    void remove(int key) {
        int index = key % n;
        auto& bucket = arr[index];
        for (auto it = bucket.begin(); it != bucket.end(); ++it) {
            if (*it == key) {
                bucket.erase(it);
                return;
            }
        }
    }

    bool contains(int key) {
        int index = key % n;
        for (int x : arr[index]) {
            if (x == key) return true;
        }
        return false;
    }
};

int main() {
    MyHashSet myHashSet;
    
    myHashSet.add(1);
    myHashSet.add(2);
    cout << myHashSet.contains(1) << endl; // true (1)
    cout << myHashSet.contains(3) << endl; // false (0)
    
    myHashSet.add(2);
    cout << myHashSet.contains(2) << endl; // true (1)
    
    myHashSet.remove(2);
    cout << myHashSet.contains(2) << endl; // false (0)

    return 0;
}
