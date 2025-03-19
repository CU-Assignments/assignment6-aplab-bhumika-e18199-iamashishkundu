#include <iostream>
#include <stack>
using namespace std;

class MinStack {
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x <= s2.top()) s2.push(x);
    }

    void pop() {
        if (!s1.empty()) {
            if (s1.top() == s2.top()) s2.pop();
            s1.pop();
        }
    }

    int top() {
        return s1.empty() ? -1 : s1.top();
    }

    int getMin() {
        return s2.empty() ? -1 : s2.top();
    }
};

int main() {
    MinStack ms;

    ms.push(5);
    ms.push(3);
    ms.push(7);
    ms.push(2);

    cout << ms.getMin() << "\n";
    ms.pop();
    cout << ms.getMin() << "\n";
    ms.pop();
    cout << ms.getMin() << "\n";

    return 0;
}
