//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int solve(int *arr,int curr,vector<int>& dp){
        if(curr == 0)return dp[0] = arr[0];
        if(curr < 0)return 0;
        
        if(dp[curr] != -1){
            return dp[curr];
        }
        
        int left = solve(arr,curr-2,dp) + arr[curr];
        
        int right = solve(arr,curr-1,dp);
        
        return dp[curr] = max(left,right);
 
    }
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *arr, int n) {
	    // code here
	    vector<int> dp(n,-1);
	    return solve(arr,n-1,dp);
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends