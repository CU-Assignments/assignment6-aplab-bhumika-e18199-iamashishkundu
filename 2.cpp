#include <iostream>
#include <stack>
using namespace std;

class DequeUsingStack {
    stack<int> s1, s2;

public:
    void pushFront(int x) {
        s1.push(x);
    }

    void pushBack(int x) {
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }

    int popFront() {
        if (s1.empty()) return -1;
        int front = s1.top();
        s1.pop();
        return front;
    }

    int popBack() {
        if (s1.empty()) return -1;
        while (s1.size() > 1) {
            s2.push(s1.top());
            s1.pop();
        }
        int back = s1.top();
        s1.pop();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return back;
    }

    int front() {
        return s1.empty() ? -1 : s1.top();
    }

    int back() {
        if (s1.empty()) return -1;
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        int back = s2.top();
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
        return back;
    }
};

int main() {
    DequeUsingStack dq;

    dq.pushFront(10);
    dq.pushBack(20);
    dq.pushFront(5);
    dq.pushBack(25);

    cout << dq.front() << "\n"; 
    cout << dq.back() << "\n";  
    cout << dq.popFront() << "\n"; 
    cout << dq.popBack() << "\n";  

    return 0;
}
