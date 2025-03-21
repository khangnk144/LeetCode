#include <iostream>
#include <vector>
#include <string>

using namespace std;

class MyHashMap {
public:
    int n = 10000;
    vector<vector<int>> arr[10000];  // Mỗi phần tử là danh sách các cặp {key, value}

    MyHashMap() {
    }

    void put(int key, int value) {
        int idx = key % n;
        for (auto& x : arr[idx]) {
            if (x[0] == key) {
                x[1] = value;  // Cập nhật giá trị nếu key đã tồn tại
                return;
            }
        }
        arr[idx].push_back({key, value});  // Thêm key-value mới
    }

    int get(int key) {
        int idx = key % n;
        for (auto& x : arr[idx]) {
            if (x[0] == key) {
                return x[1];
            }
        }
        return -1;  // Không tìm thấy key
    }

    void remove(int key) {
        int idx = key % n;
        for (int i = 0; i < arr[idx].size(); i++) {
            if (arr[idx][i][0] == key) {
                arr[idx].erase(arr[idx].begin() + i);  // Xóa key nếu tìm thấy
                return;
            }
        }
    }
};

int main() {
    MyHashMap myHashMap;
    myHashMap.put(1, 1);  // The map is now [[1,1]]
    myHashMap.put(2, 2);  // The map is now [[1,1], [2,2]]
    cout << myHashMap.get(1) << endl; // return 1
    cout << myHashMap.get(3) << endl; // return -1 (not found)
    myHashMap.put(2, 1);  // The map is now [[1,1], [2,1]] (update value)
    cout << myHashMap.get(2) << endl; // return 1
    myHashMap.remove(2);  // The map is now [[1,1]]
    cout << myHashMap.get(2) << endl; // return -1 (not found)
    
    return 0;
}