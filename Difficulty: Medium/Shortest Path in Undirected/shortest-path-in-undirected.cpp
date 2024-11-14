//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


class Solution {
public:
    unordered_set<int> visited;

    void bfs(int src, vector<int> &dist, vector<vector<int>>& graph) { 
        int v = graph.size();
        queue<int> qu;
        visited.clear();
        dist.resize(v, INT_MAX);
        dist[src] = 0;
        visited.insert(src);
        qu.push(src);

        while (!qu.empty()) {
            int curr = qu.front();
            qu.pop();
            for (auto neighbour : graph[curr]) {
                if (!visited.count(neighbour)) { // only to that neighbour which is not counted till now
                    qu.push(neighbour);
                    visited.insert(neighbour);
                    dist[neighbour] = dist[curr] + 1; 
                    // source se curr ka distance and + 1
                    // means kisi bhi curr ke neighbour ko traverse krenge to curr se har ek neighbour ka distance 1 hi hoga and source to
                    // curr ka distance curr ke index pr hai to dist[curr] + 1
                }
            }
        }
    }

    vector<int> shortestPath(vector<vector<int>>& edges, int N, int M, int src) {
        vector<vector<int>> graph(N);
        for (auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]); // undirected graph
        }

        vector<int> dist;
        bfs(src, dist, graph);

        for (int i = 0; i < N; i++) {
            if (dist[i] == INT_MAX) {
                dist[i] = -1;
            }
        }

        return dist;
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    
cout << "~" << "\n";
}
}

// } Driver Code Ends