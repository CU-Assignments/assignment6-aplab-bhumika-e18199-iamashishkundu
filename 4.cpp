#include <iostream>
#include <stack>
using namespace std;

class MaxStack {
    stack<int> s1, s2;

public:
    void push(int x) {
        s1.push(x);
        if (s2.empty() || x >= s2.top()) s2.push(x);
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

    int getMax() {
        return s2.empty() ? -1 : s2.top();
    }
};

int main() {
    MaxStack ms;

    ms.push(5);
    ms.push(8);
    ms.push(3);
    ms.push(10);

    cout << ms.getMax() << "\n";
    ms.pop();
    cout << ms.getMax() << "\n";
    ms.pop();
    cout << ms.getMax() << "\n";

    return 0;
}
