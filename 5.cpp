#include <iostream>
#include <stack>
using namespace std;

class PriorityQueue {
    stack<int> s1, s2;

public:
    void push(int x) {
        while (!s1.empty() && s1.top() < x) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int pop() {
        if (s1.empty()) return -1;
        int top = s1.top();
        s1.pop();
        return top;
    }

    int top() {
        return s1.empty() ? -1 : s1.top();
    }

    bool empty() {
        return s1.empty();
    }
};

int main() {
    PriorityQueue pq;

    pq.push(3);
    pq.push(5);
    pq.push(1);
    pq.push(4);

    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";
    pq.pop();
    cout << pq.top() << "\n";

    return 0;
}
