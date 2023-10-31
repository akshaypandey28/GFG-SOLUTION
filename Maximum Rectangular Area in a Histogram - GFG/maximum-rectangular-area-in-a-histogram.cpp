//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    //#define long long ll
    public:
    
    //Function to find largest rectangular area possible in a given histogram.
    // long long area(long long arr[],int n){
    //     stack<long long> st;
    //     int ans=INT16_MIN;
    //     st.push(0);
    //     for(long long i=1; i<n; i++){
    //         while(st.empty()!=1 && arr[i] < arr[st.top()]){
    //             long long ele=arr[st.top()];
    //             st.pop();
    //             long long nsi=i;
    //             long long psi=(st.empty()) ? 0:st.top();
    //             ans=max(ans,ele*(nsi-psi-1));
    //         }
    //         st.push(i);
    //     }
    //     while(st.empty()!=1){  //stack me kuch element bache honge
    //     long long ele=arr[st.top()];
    //     long long nsi=n;
    //     st.pop();
    //     long long psi=(st.empty())? 0 : st.top();
    //     ans=max(ans,ele*(nsi-psi-1));    }
    //     return ans;    
    // }
    long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        stack<long long> st;
        long long ans=INT16_MIN;
        st.push(0);
        for(long long i=1; i<n; i++){
            while(st.empty()!=1 && arr[i] < arr[st.top()]){
                long long ele=arr[st.top()];
                st.pop();
                long long nsi=i;
                long long psi=(st.empty()) ? -1:st.top();
                ans=max(ans,ele*(nsi-psi-1));
            }
            st.push(i);
        }
        while(st.empty()!=1){  //stack me kuch element bache honge
        long long ele=arr[st.top()];
        long long nsi=n;
        st.pop();
        long long psi=(st.empty())? -1 : st.top();
        ans=max(ans,ele*(nsi-psi-1));    }
        return ans; 
        //return area(arr,n);
        
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends