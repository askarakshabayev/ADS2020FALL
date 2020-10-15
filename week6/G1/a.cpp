#include <iostream>
#include <vector>

using namespace std;


class MinHeap {
    vector<int> a;

    int parent(int i) {
        return (i - 1) / 2;
    }

    int left(int i) {
        return 2 * i + 1;
    }

    int right(int i) {
        return 2 * i + 2;
    }

    int getMin() {
        return a[0];
    }

    void insert(int k) {
        a.push_back(k);
        int i = a.size() - 1;
        while (i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void heapify(int i) {
        if (left(i) > a.size() - 1)
            return;
        int j = left(i);
        if (right(i) < a.size() && a[left(i)] > a[right(i)])
            j = right(i);
        if (a[i] > a[j]) {
            swap(a[i], a[j]);
            heapify(j);
        }
    }

    void decreaseKey(int i, int new_value) {
        a[i] = new_value;
        while (i > 0 && a[parent(i)] > a[i]) {
            swap(a[parent(i)], a[i]);
            i = parent(i);
        }
    }

    void increaseKey(int i, int new_value) {
        a[i] = new_value;
        heapify(i);
    }

    int extractMin() {
        int root = a[0];
        swap(a[0], a[a.size() - 1]);
        a.pop_back();
        heapify(0);
        return root;
    }

}




int main() {
    return 0;
}