#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<int> heap;

    void initializeHeap() {
        heap.clear();
    }

    void insert(int x) {
        heap.push_back(x);
        int index = heap.size() - 1;
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index] > heap[parent]) {
                swap(heap[index], heap[parent]);
                index = parent;
            } else {
                break;
            }
        }
    }

    int getMax() {
        if (heap.empty()) return -1;  // Return -1 or throw exception
        return heap[0];
    }

    void exctractMax() {
        if (heap.empty()) return;
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapifyDown(0);
    }

    int heapSize() {
        return heap.size();
    }

    bool isEmpty() {
        return heap.empty();
    }

    void changeKey(int ind, int val) {
        if (ind < 0 || ind >= heap.size()) return;
        int old_val = heap[ind];
        heap[ind] = val;
        if (val > old_val) {
            // Bubble up
            while (ind > 0) {
                int parent = (ind - 1) / 2;
                if (heap[ind] > heap[parent]) {
                    swap(heap[ind], heap[parent]);
                    ind = parent;
                } else {
                    break;
                }
            }
        } else {
            // Heapify down
            heapifyDown(ind);
        }
    }

private:
    void heapifyDown(int i) {
        int size = heap.size();
        while (i < size) {
            int largest = i;
            int left = 2 * i + 1;
            int right = 2 * i + 2;

            if (left < size && heap[left] > heap[largest]) largest = left;
            if (right < size && heap[right] > heap[largest]) largest = right;

            if (largest != i) {
                swap(heap[i], heap[largest]);
                i = largest;
            } else {
                break;
            }
        }
    }
};

int main() {
    Solution h;

    // Sample input
    vector<string> ops = {
        "initializeHeap", "insert", "insert", "insert", "getMax",
        "heapSize", "isEmpty", "exctractMax", "changeKey", "getMax"
    };

    vector<vector<int>> nums = {
        {}, {4}, {1}, {10}, {}, {}, {}, {}, {0, 16}, {}
    };

    vector<string> result;

    int j = 0;
    for (int i = 0; i < ops.size(); ++i) {
        if (ops[i] == "initializeHeap") {
            h.initializeHeap();
            result.push_back("null");
        } else if (ops[i] == "insert") {
            h.insert(nums[j][0]);
            j++;
            result.push_back("null");
        } else if (ops[i] == "getMax") {
            result.push_back(to_string(h.getMax()));
        } else if (ops[i] == "exctractMax") {
            h.exctractMax();
            result.push_back("null");
        } else if (ops[i] == "heapSize") {
            result.push_back(to_string(h.heapSize()));
        } else if (ops[i] == "isEmpty") {
            result.push_back(h.isEmpty() ? "1" : "0");
        } else if (ops[i] == "changeKey") {
            h.changeKey(nums[j][0], nums[j][1]);
            j++;
            result.push_back("null");
        }
    }

    // Print output
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i != result.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
