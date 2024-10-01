//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int arr[])
    {
       // your code here
       vector<int> temp;
        temp.push_back(arr[0]);
    
        int len = 1;
    
        for (int i = 1; i < n; i++) {
            if (arr[i] > temp.back()) {
                // If arr[i] is greater than the last element of temp, extend the subsequence
                temp.push_back(arr[i]);
                len++;
            } else {
                // If arr[i] is not greater, replace the element in temp with arr[i]
                int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
                temp[ind] = arr[i];
            }
        }
    
        return len;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends