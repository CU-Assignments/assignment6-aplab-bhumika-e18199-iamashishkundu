#include <iostream>
using namespace std;

class TwoStacks {
    int* arr;
    int top1, top2, size;
public:
    TwoStacks(int n) {
        size = n;
        arr = new int[n];
        top1 = -1;
        top2 = n;
    }
    void push1(int x) {
        if (top1 < top2 - 1) arr[++top1] = x;
    }
    void push2(int x) {
        if (top1 < top2 - 1) arr[--top2] = x;
    }
    int pop1() {
        return (top1 >= 0) ? arr[top1--] : -1;
    }
    int pop2() {
        return (top2 < size) ? arr[top2++] : -1;
    }
};

class kStacks {
    int* arr, *top, *next;
    int n, k, free;
public:
    kStacks(int k, int n) {
        this->k = k;
        this->n = n;
        arr = new int[n];
        top = new int[k];
        next = new int[n];
        for (int i = 0; i < k; i++) top[i] = -1;
        for (int i = 0; i < n - 1; i++) next[i] = i + 1;
        next[n - 1] = -1;
        free = 0;
    }
    void push(int x, int sn) {
        if (free == -1) return;
        int i = free;
        free = next[i];
        arr[i] = x;
        next[i] = top[sn];
        top[sn] = i;
    }
    int pop(int sn) {
        if (top[sn] == -1) return -1;
        int i = top[sn];
        top[sn] = next[i];
        next[i] = free;
        free = i;
        return arr[i];
    }
};

class MinHeap {
    int* arr;
    int size, capacity;
public:
    MinHeap(int cap) {
        size = 0;
        capacity = cap;
        arr = new int[cap];
    }
    void insert(int x) {
        if (size == capacity) return;
        int i = size++;
        while (i > 0 && arr[(i - 1) / 2] > x) {
            arr[i] = arr[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        arr[i] = x;
    }
    int extractMin() {
        if (size == 0) return -1;
        int root = arr[0];
        arr[0] = arr[--size];
        minHeapify(0);
        return root;
    }
    void minHeapify(int i) {
        int l = 2 * i + 1, r = 2 * i + 2, smallest = i;
        if (l < size && arr[l] < arr[smallest]) smallest = l;
        if (r < size && arr[r] < arr[smallest]) smallest = r;
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
};

class MaxHeap {
    int* arr;
    int size, capacity;
public:
    MaxHeap(int cap) {
        size = 0;
        capacity = cap;
        arr = new int[cap];
    }
    void insert(int x) {
        if (size == capacity) return;
        int i = size++;
        while (i > 0 && arr[(i - 1) / 2] < x) {
            arr[i] = arr[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        arr[i] = x;
    }
    int extractMax() {
        if (size == 0) return -1;
        int root = arr[0];
        arr[0] = arr[--size];
        maxHeapify(0);
        return root;
    }
    void maxHeapify(int i) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if (l < size && arr[l] > arr[largest]) largest = l;
        if (r < size && arr[r] > arr[largest]) largest = r;
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
        }
    }
};

int main() {
    TwoStacks ts(5);
    ts.push1(5);
    ts.push2(10);
    cout << ts.pop1() << " " << ts.pop2() << endl;

    kStacks ks(3, 6);
    ks.push(15, 0);
    ks.push(45, 2);
    cout << ks.pop(0) << " " << ks.pop(2) << endl;

    MinHeap mh(5);
    mh.insert(3);
    mh.insert(2);
    cout << mh.extractMin() << endl;

    MaxHeap maxh(5);
    maxh.insert(3);
    maxh.insert(5);
    cout << maxh.extractMax() << endl;

    return 0;
}
