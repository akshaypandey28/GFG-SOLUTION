//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
     bool h(int arr[],int ind,int target,vector<vector<int>>&d)
    {
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        if(d[ind][target] != -1) return d[ind][target];
        
        bool take = false;
        
        if(arr[ind] <= target)
        take = h(arr,ind-1,target-arr[ind],d);
        
        bool nottake = false;
        nottake = h(arr,ind-1,target,d);
        return d[ind][target] = (take or nottake);
    }
    int equalPartition(int n, int arr[])
    {
       int sum = 0;
        for(int i=0;i<n;i++) sum += arr[i];
        if(sum%2) return 0;
        int target = sum/2;
        vector<vector<int>>d(n+1,vector<int>(target+1,-1));
        return h(arr,n-1,target,d);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends