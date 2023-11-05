//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod= 1e9 +7;
    int solve(int n,int m,vector<vector<int>>& grid,vector<vector<int>>& dp){
        if(n == 0 && m == 0){
            if(grid[n][m] == 0)return dp[n][m]=1;
            return dp[n][m] = 0;
        }
        if(dp[n][m] != -1)return dp[n][m];
        int left=0,up=0;
        if(n > 0){
            if(grid[n-1][m] != 1){
                left = solve(n-1,m,grid,dp)%mod;
            }
        }
        if(m> 0){
            if(grid[n][m-1] != 1){
                up = solve(n,m-1,grid,dp)%mod;
            }
        }   
        
        return dp[n][m] = (left + up)%mod;
    }
    int totalWays(int n, int m, vector<vector<int>>& grid) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1,m-1,grid,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int i = 0; i < m; ++i) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.totalWays(n, m, grid) << "\n";
    }
    return 0;
}
// } Driver Code Ends