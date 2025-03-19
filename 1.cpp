#include <iostream>
#include <stack>
using namespace std;

class QueueUsingStack {
    stack<int> s1, s2; 

public:
    
    void enqueue(int x) {
        s1.push(x);
    }

    // Dequeue operation
    int dequeue() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }

        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }

        int front = s2.top();
        s2.pop();
        return front;
    }

    // Check if queue is empty
    bool isEmpty() {
        return s1.empty() && s2.empty();
    }

    // Get the front element
    int front() {
        if (s1.empty() && s2.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        if (s2.empty()) {
            while (!s1.empty()) {
                s2.push(s1.top());
                s1.pop();
            }
        }
        return s2.top();
    }
};

int main() {
    QueueUsingStack q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl; 
    cout << "Dequeue: " << q.dequeue() << endl;    
    cout << "Dequeue: " << q.dequeue() << endl;    

    q.enqueue(40);
    cout << "Front element: " << q.front() << endl; 
    cout << "Dequeue: " << q.dequeue() << endl;    
    cout << "Dequeue: " << q.dequeue() << endl;    

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    return 0;
}
