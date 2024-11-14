//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    vector<list<pair<int, int>>> graph;

    void topoSort(int node, int vis[], stack<int> &st) {
        vis[node] = 1;
        for (auto it : graph[node]) {
            int v = it.first;
            if (!vis[v]) {
                topoSort(v, vis, st);
            }
        }
        st.push(node);
    }

    vector<int> shortestPath(int V, int E, vector<vector<int>> &edges) {
        // Construct the adjacency list for the graph
        graph.resize(V);
        for (int i = 0; i < E; i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u].push_back({v, wt});
        }

        int vis[V] = {0};

        // Now, we perform topo sort using DFS technique and store the result in the stack
        stack<int> st;
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                topoSort(i, vis, st);
            }
        }

        vector<int> dist(V);
        for (int i = 0; i < V; i++) {
            dist[i] = 1e9;
        }

        dist[0] = 0;
        while (!st.empty()) {
            int node = st.top();
            st.pop();

            for (auto it : graph[node]) {
                int v = it.first;
                int wt = it.second;

                if (dist[node] + wt < dist[v]) {
                    dist[v] = wt + dist[node];
                }
            }
        }

        for (int i = 0; i < V; i++) {
            if (dist[i] == 1e9) dist[i] = -1;
        }
        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends