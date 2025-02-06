//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
    int f(int i,int j1,int j2,int n,int m,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp) {
        
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m){
            return -1e8;
        }
        
        if(i == n-1){
            if(j1 == j2)return grid[i][j1];
            else{
                return grid[i][j2] + grid[i][j1];
            }
        }
        
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        int maxi=-1e8;
        for(int delta1 = -1 ; delta1 < 2; delta1++){
            for(int delta2=-1; delta2 < 2; delta2++){
                int val =0;
                if( j1 == j2)val =grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];
                
                val += f(i+1,j1 + delta1,j2 + delta2,n,m,grid,dp);
                maxi = max(maxi,val);
            }
        }
        return dp[i][j1][j2] =maxi;        
    }
    int solve(int n, int m, vector<vector<int>>& grid) {
        // code here
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m,-1)));
        
        return f(0,0,m-1,n,m,grid,dp);
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
        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j < m; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            grid.push_back(temp);
        }

        Solution obj;
        cout << obj.solve(n, m, grid) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends