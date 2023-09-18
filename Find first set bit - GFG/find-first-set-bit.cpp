//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find position of first set bit in the given number.
    unsigned int getFirstSetBit(int n)
    {
        // Your code here
        string s =bitset<32>(n).to_string();
        const auto loc1 = s.find('1');
        
        if(loc1 != string::npos) s=s.substr(loc1);
        
        for(int i=s.size()-1; i>=0; i--){
            if(s[i]=='1'){
                return s.size()-i;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.

// Driver code
int main()
{
    int t;
    cin>>t; // testcases
    while(t--)
    {
        int n;
        cin>>n; //input n
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n)); // function to get answer
    }
	return 0;
}

// } Driver Code Ends