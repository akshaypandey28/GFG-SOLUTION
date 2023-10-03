//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &s) {
        // code here
        vector<int>v;
        int num = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='I') v.push_back(1);
            if(s[i]=='V') v.push_back(5);
            if(s[i]=='X') v.push_back(10);
            if(s[i]=='L') v.push_back(50);
            if(s[i]=='C') v.push_back(100);
            if(s[i]=='D') v.push_back(500);
            if(s[i]=='M') v.push_back(1000);
        }
        if(v.size()==1){
            return v[0];
        }
        for(int i=0; i<v.size()-1; i++){
            if(v[i]<v[i+1]){
                num=num+v[i+1]-v[i];
                i++;
            }
            else{
                num=num+v[i];
            }
        }
        if(v[v.size()-2] >= v[v.size()-1]) num = num + v[v.size()-1];

        return num;

    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.romanToDecimal(s) << endl;
    }
}
// } Driver Code Ends