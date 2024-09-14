//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
public:
    vector<vector<int>> dp;

    int f(vector<vector<int>>& arr, int n, int i, int prev) {
        if (i >= n) return 0;
        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int maxi = 0;
        for (int j = 0; j < 3; j++) {
            if (j != prev) {
                maxi = max(maxi, arr[i][j] + f(arr, n, i + 1, j));
            }
        }

        return dp[i][prev + 1] = maxi;
    }

    int maximumPoints(vector<vector<int>>& arr, int n) {
        dp.clear();
        dp.resize(n, vector<int>(4, -1)); // DP array for each day with 4 possible 'prev' values (-1, 0, 1, 2)
        return f(arr, n, 0, -1); // Start from day 0 with no previous activity (indicated by -1)
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends