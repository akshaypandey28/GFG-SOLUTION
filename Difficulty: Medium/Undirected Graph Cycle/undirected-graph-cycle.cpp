//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int v;
    unordered_set<int> vis;
    queue<int> qu;
    bool bfs(vector<vector<int>> &adj,int node,vector<int> &par){
        qu.push(node);
        vis.insert(node);
        while(qu.empty()!=1){
            int curr=qu.front();
            qu.pop();
            for(auto neighbour:adj[curr]){
        //concept => if the neighbour of the source is visited (that is visited node) and the neighbour is not the parent of src node 
        //then cycle detected
                if(vis.count(neighbour) and par[curr]!=neighbour) return true;
                if(vis.count(neighbour)==0){
                    vis.insert(neighbour);
                    par[neighbour] = curr;
                    qu.push(neighbour);
                }
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int n=adj.size();
        v=n;
        vector<int> par(v, -1);
        for(int i=0; i<v; i++){
            if(vis.count(i)==0){
                bool result=bfs(adj,i,par);
                if(result==true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj(V);
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends