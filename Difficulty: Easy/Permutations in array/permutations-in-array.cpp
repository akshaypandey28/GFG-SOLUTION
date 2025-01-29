//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool isPossible(int k, vector<int> &a, vector<int> &b) {
        // Your code goes here
        // Sort the array a[] in increasing order.
        int n=a.size();
        sort(a.begin(),a.end());
    
        // Sort the array b[] in decreasing order.
        sort(b.begin(),b.end(), greater<int>());
    
        // Checking condition on each index.
        for (int i = 0; i < n; i++)
            if (a[i] + b[i] < k) return false;
    
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> arr1, arr2;
        int num;
        while (ss >> num) {
            arr1.push_back(num);
        }
        getline(cin, s);
        ss.clear();
        ss.str(s);
        while (ss >> num) {
            arr2.push_back(num);
        }
        Solution ob;
        bool ans = ob.isPossible(k, arr1, arr2);
        if (ans) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends