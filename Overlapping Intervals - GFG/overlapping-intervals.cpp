//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    static bool cmp(vector<int> a ,vector<int> b){ //sorting acc to 0th index
        return a[0]<b[0];
    }
    vector<vector<int>> overlappedInterval(vector<vector<int>>& v) {
         // Code here
         vector<vector<int> > ans;
         sort(v.begin(),v.end(),cmp);
         vector<int> picked=v[0];
         for(int i=1; i<v.size(); i++){
             if(picked[1]>=v[i][0]){
                 picked[1]=max(picked[1],v[i][1]);
             }
             else{
                 ans.push_back(picked);
                 picked=v[i];
             }
         }
         ans.push_back(picked);
         return ans;
         
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>Intervals(n);
		for(int i = 0; i < n; i++){
			int x, y;
			cin >> x >> y;
			Intervals[i].push_back(x);
			Intervals[i].push_back(y);
		}
		Solution obj;
		vector<vector<int>> ans = obj.overlappedInterval(Intervals);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
		}
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends