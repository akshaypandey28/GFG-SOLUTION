//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<int> dp;
    vector<int> arr;
    vector<int> parent; // To store the previous index in the LIS

    // Recursive function to find the length of LIS ending at index i
    int f(int i) {
        if (dp[i] != -1) return dp[i];
        int maxi = INT_MIN;
        parent[i] = -1; // No previous index initially

        for (int j = 0; j <= i - 1; j++) {
            if (arr[j] < arr[i]) {
                int possibleLIS = f(j);
                if (possibleLIS > maxi) {
                    maxi = possibleLIS;
                    parent[i] = j; // Track the previous index
                }
            }
        }
        
        if (maxi == INT_MIN) return dp[i] = 1; // Base case: LIS length is 1
        return dp[i] = 1 + maxi; // Add 1 to include arr[i]
    }

    vector<int> longestIncreasingSubsequence(int n, vector<int>& nums) {
        arr = nums;
        dp.clear();
        parent.clear();
        dp.resize(n, -1);
        parent.resize(n, -1);

        int maxLength = 1, lastIndex = 0; // Track the LIS length and last element's index
        for (int i = 0; i < n; i++) {
            int length = f(i);
            if (length > maxLength) {
                maxLength = length;
                lastIndex = i; // Update the index of the last element of LIS
            }
        }

        // Reconstruct the LIS by backtracking using the parent array
        vector<int> lis;
        for (int i = lastIndex; i != -1; i = parent[i]) {
            lis.push_back(arr[i]);
        }

        reverse(lis.begin(), lis.end()); // Since we backtrack, reverse to get the correct order
        return lis; // Return the actual subsequence
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends