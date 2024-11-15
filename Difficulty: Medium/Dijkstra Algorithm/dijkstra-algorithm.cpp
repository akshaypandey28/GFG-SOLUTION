//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User Function Template

#define pp pair<int, int>
class Solution {
  public:
    vector<list<pp > > gr;
    
    unordered_map<int, int> djikstra(int src, int n) { // O(VlogV + ElogV) => O(V+E)logV
        priority_queue<pp, vector<pp> , greater<pp> > pq; // {wt, node}
        unordered_set<int> vis;
        vector<int> via(n+1);
        unordered_map<int, int> mp; //{node, wt} stores the shortest distance from source node to any node
        
        for(int i = 0; i < n; i++) mp[i] = INT_MAX;  // O(V)
            
        pq.push({0, src});
        mp[src] = 0;
        while(!pq.empty()) { // O((V+E)logV)
            pp curr = pq.top();
            if(vis.count(curr.second)) {
                pq.pop();
                continue;
            }
            pq.pop();//if pop operation performed then it means the best distance for this node from source is calculated
            vis.insert(curr.second);//on pop up from pq ,visited is marked , not on insertion in pq
    
            for(auto neighbour : gr[curr.second]) {
                if(!vis.count(neighbour.first) and mp[neighbour.first] > mp[curr.second] + neighbour.second) { //this line is relaxation algorithm
                    pq.push({mp[curr.second] + neighbour.second, neighbour.first});
                    via[neighbour.first] = curr.second;
                    mp[neighbour.first] = mp[curr.second] + neighbour.second;
                }
            }
        }
        return mp;
    }
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        // Code here
        int n=adj.size();
        gr.resize(n,list<pp>());
        for(int i=0; i<n; i++){
            for(int j=0; j<adj[i].size(); j++){
                gr[i].push_back({adj[i][j].first,adj[i][j].second});
            }
        }
        
        unordered_map<int, int> sp = djikstra(src, n);
        
        vector<int> ans(n);
        for(auto ele:sp) ans[ele.first]=sp[ele.first];
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<pair<int, int>>> adj(V);
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            pair<int, int> t1 = {v, w}, t2 = {u, w};
            adj[u].push_back(t1);
            adj[v].push_back(t2);
        }
        int src;
        cin >> src;
        cin.ignore();

        Solution obj;
        vector<int> res = obj.dijkstra(adj, src);

        for (int i = 0; i < V; i++)
            cout << res[i] << " ";
        cout << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends