#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void dfs(int start, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(start);

    while (!st.empty()) {
        int node = st.top();
        st.pop();

        if (!visited[node]) {
            cout << node << " ";
            visited[node] = true;
        }

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                st.push(neighbor);
            }
        }
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {3, 4};
    adj[2] = {5};

    vector<bool> visited(n, false);
    dfs(0, adj, visited);

    return 0;
}

