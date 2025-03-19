#include <iostream>
using namespace std;

class QueueUsingArray {
    int* arr;
    int frontIndex, rearIndex, capacity, count;

public:
    QueueUsingArray(int size) : capacity(size), frontIndex(0), rearIndex(-1), count(0) {
        arr = new int[capacity];
    }

    void enqueue(int x) {
        if (count < capacity) {
            rearIndex = (rearIndex + 1) % capacity;
            arr[rearIndex] = x;
            count++;
        }
    }

    void dequeue() {
        if (count > 0) {
            frontIndex = (frontIndex + 1) % capacity;
            count--;
        }
    }

    int front() {
        return (count > 0) ? arr[frontIndex] : -1;
    }

    int rear() {
        return (count > 0) ? arr[rearIndex] : -1;
    }

    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == capacity;
    }
};

int main() {
    QueueUsingArray q(5);

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";

    q.enqueue(4);
    cout << q.rear() << "\n";

    return 0;
}
