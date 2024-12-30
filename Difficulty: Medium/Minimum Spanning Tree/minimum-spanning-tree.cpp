//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    
    static bool cmp(vector<int> &v1,vector<int> &v2){
        return v1[2]<v2[2];
    }
    
    int find(vector<int> &parent,int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent,parent[x]);
    }
    
    void Union(vector<int> &parent,vector<int> &rank,int a,int b){
        a=find(parent,a);
        b=find(parent,b);
        
        if(rank[a]>=rank[b]){
            rank[a]++;
            parent[b]=a;
        }
        else{
            rank[b]++;
            parent[a]=b;
        }
    }
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> edges[]) {
        // code here
        vector<vector<int>> adj; // Flat list of edges

        // Extract edges from adjacency list
        for (int i = 0; i < V; i++) {
            for (auto& neighbor : edges[i]) {
                int u = i;
                int v = neighbor[0];
                int weight = neighbor[1];
                adj.push_back({u, v, weight});
            }
        }
        
        
        vector<int> parent(V);
        iota(parent.begin(),parent.end(),0);
        vector<int> rank(V,1);
        
        sort(adj.begin(),adj.end(),cmp);
        int edgeCount=0; 
        //n vertices then no. of edges = n-1
        int i=0;
        
        int ans=0;
        
        while(edgeCount<V-1 and i < adj.size()){
            vector<int> curr=adj[i];
            int src=curr[0];
            int dest=curr[1];
            int edgeWt=curr[2];
            
            int srcPar=find(parent,src);
            int destPar=find(parent,dest);
            
            if(srcPar!=destPar) {
                Union(parent,rank,src,dest);
                edgeCount++;
                ans+=edgeWt;
            }
            i++;
        }
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
        vector<vector<int>> adj[V];
        int i = 0;
        while (i++ < E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1, t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }

        Solution obj;
        cout << obj.spanningTree(V, adj) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends