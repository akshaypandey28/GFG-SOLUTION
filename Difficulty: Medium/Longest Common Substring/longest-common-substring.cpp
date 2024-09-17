//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    
    int longestCommonSubstr(string s1, string s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0)); 
        //solution is based on 0 based indexing
        //i can remove the condition str1[i-1]==str2[j-1] because either dp[i][j]=0 or some value
        //value represents common substring and 0 represents no common
        //so if dp[i-1][j-1] gets added with 1 , if it is 0 then no effect , if not then also no effect
        int ans = 0; // Initialize the answer variable
    int endIndex = 0; // To store the end index of the longest common substring

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(s1[i-1] == s2[j-1]){
                int val = 1 + dp[i-1][j-1]; // Characters match, increment substring length
                dp[i][j] = val; // Update the DP table
                // If this is the longest substring found so far
                    if (val > ans) {
                        ans = val; // Update the maximum substring length
                        endIndex = i - 1; // Mark the end index of this substring in `s1`
                    }
            }
            else
                dp[i][j] = 0; // Characters don't match, substring length becomes 0
        }
    }
    //cout<<s1.substr(endIndex - ans + 1, ans)<<endl;
    return ans; // Return the length of the Longest Common Substring
     //The actual longest common substring
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;
    }
}
// } Driver Code Ends