//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int sum(int n){
        int ans=0;
        while(n>0){
            ans+=pow(n%10,2);
            n=n/10;
        }
        return ans;
    }
    int isHappy(int N){
        // code here
        unordered_set<int> visited;
        visited.insert(N);
        int n=N;
        while(n!=1){
            int ans=sum(n);
            
            if(ans==1){
                return 1;
            }
            else if(visited.count(ans)==1) return 0;
            else{
                n=ans;
                visited.insert(n);
            }
        }
        return 1;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.isHappy(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends