//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  int mod = 1e9 + 7;
  long long int solve(int i,vector<long long int>& dp){
      if(i <= 1)return i;

      if(dp[i] != -1)return dp[i]%mod;
        dp[i] = (solve(i-1,dp) + solve(i-2,dp))%mod;
        // cout<<i<<" "<< dp[i]<<"\n";
      return dp[i];
  };
    long long int topDown(int n) {
        // code here
        vector<long long int> dp(n+1,-1);
        return  solve(n,dp);
        return ans;
    }
    
    long long int bottomUp(int n) {
            // code here
        vector<long long int> dp(n+1,-1);
        dp[0] = 0,dp[1] =1;
        for(int i=2;i <= n;i++){
            dp[i] = (dp[i-1] + dp[i-2])%mod;
        }
        
        return dp[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;
        long long int topDownans = obj.topDown(n);
        long long int bottomUpans = obj.bottomUp(n);
        if (topDownans != bottomUpans) cout << -1 << "\n";
        cout << topDownans << "\n";
    }
}
// } Driver Code Ends