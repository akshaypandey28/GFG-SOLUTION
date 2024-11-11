//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int LongestBitonicSequence(int n, vector<int> &nums) {
        // code here
        vector<int> dp(n,1),dp1(n,1);
        for(int i=0; i<n; i++){ //LIS from forward 
            for(int j=0; j<=i-1;j++){
                if(nums[j]<nums[i] and dp[i]<1+dp[j]) dp[i]=1+dp[j];
            }
        }

        for(int i=n-1; i>=0; i--){ //LIS from backward
            for(int j=n-1; j>i; j--){
                if(nums[j]<nums[i] and dp1[i]<1+dp1[j]) dp1[i]=1+dp1[j];
            }
        }
        int ans=0;
        for(int i=0; i<n; i++){
            if(dp[i]!=1 and dp1[i]!=1) ans=max(ans,dp[i]+dp1[i]-1); //-1 such that nums[i] can't be included two times
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> nums(n);
        Array::input(nums, n);

        Solution obj;
        int res = obj.LongestBitonicSequence(n, nums);

        cout << res << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends