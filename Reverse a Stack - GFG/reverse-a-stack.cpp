//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insertAtBottom(stack<int> &st1,int val){
        stack<int> temp;
        while(st1.empty()==0){ //not st1.empty()
        int curr=st1.top();
        st1.pop();
        temp.push(curr);  }
        st1.push(val);
        while(not temp.empty()){
        int curr=temp.top();
        temp.pop();
        st1.push(curr);   }
    }
    void reverseStackusingCallStack(stack<int> &st){
        if(st.empty()){
            return ;   }
        int curr=st.top();
        st.pop();
        reverseStackusingCallStack(st);
        insertAtBottom(st,curr);    
    }
    void Reverse(stack<int> &st){
        reverseStackusingCallStack(st);
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends