//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    
cout << "~" << "\n";
}
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    // your code here
    if(s.size()&1) return -1; //odd size
    //try to remove the balanced part from the string and solve the remaining part
    int o_c=0,closing=0; //o_c means opening closing which balance each other
    for(int i=0; i<s.size(); i++){
        if(s[i]=='{') o_c++;
        else if(o_c>0) o_c--; //means it is a closing bracket
        else closing++;
    }
    //after the loop o_c is only opening bracket
    //because at lats after removing the balanced part from the string 
    //remaining string looks like ex => }}}{{{ or }}}{{ 
    //so for this solve the closing and o_c separately
    //ex=> }}} => {{} and {{{ => {}} so it will cost 2+2=4
    closing = (closing/2)+(closing%2);
    o_c = (o_c/2)+(o_c%2);
    return closing+o_c;
    
}