//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the smallest window in the string s1 consisting
    // of all the characters of string s2.
    string smallestWindow(string &s1, string &s2) {
        // Your code here
        unordered_map<char,int> m;
        int minLen=INT_MAX;
        int count=0;
        for(int i=0; i<s2.size(); i++) m[s2[i]]++;
        int start_idx=-1;
        int l=0,r=0;
        while(r<s1.size()){
            if(m[s1[r]] > 0) count++;
            m[s1[r]]--;
            
            while(count==s2.size()){
                if(r-l+1 < minLen){
                    minLen=r-l+1;
                    start_idx=l;
                }
                
                m[s1[l]]++;
                if(m[s1[l]] > 0) count--;
                l++;
            }
            r++;
        }
        return start_idx==-1 ? "" : s1.substr(start_idx,minLen);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        cin >> s1;
        string s2;
        cin >> s2;
        Solution obj;
        string str = obj.smallestWindow(s1, s2);
        if (str.size() == 0) {
            cout << "\"\"" << endl;
        } else {
            cout << str << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends