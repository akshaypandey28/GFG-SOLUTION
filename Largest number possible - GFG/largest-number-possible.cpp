//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    string findLargest(int n, int s){
        // code here
        if(9*n <s || (s==0 && n!=1) )return "-1";
        if(n==1) return to_string(s);
        string a="";
        int count=0;
        for(int i=1; i<=n; i++){
            if(s>=9){
              a.push_back('9');
              s-=9;
              //cout<<"akshay";
            }
            else{
                break; 
            }
            count++;
            //cout<<count<<endl;
            
        }
        //cout<<count<<endl;
        if(count<n){
            string b=to_string(s);
            a.push_back(b[0]);
            for(int i=1; i<n-count; i++) a.push_back('0');
        }
        
        return a;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends