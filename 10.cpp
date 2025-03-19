#include <iostream>
#include <queue>
using namespace std;

class DequeUsingQueue {
    queue<int> q1, q2;

public:
    void pushFront(int x) {
        q2.push(x);
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        swap(q1, q2);
    }

    void pushBack(int x) {
        q1.push(x);
    }

    void popFront() {
        if (!q1.empty()) q1.pop();
    }

    void popBack() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        swap(q1, q2);
    }

    int front() {
        return q1.empty() ? -1 : q1.front();
    }

    int back() {
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }
        int last = q1.front();
        q2.push(last);
        q1.pop();
        swap(q1, q2);
        return last;
    }
};

int main() {
    DequeUsingQueue dq;

    dq.pushFront(3);
    dq.pushBack(5);
    dq.pushFront(1);

    cout << dq.front() << "\n";
    cout << dq.back() << "\n";
    dq.popBack();
    cout << dq.back() << "\n";

    return 0;
}
