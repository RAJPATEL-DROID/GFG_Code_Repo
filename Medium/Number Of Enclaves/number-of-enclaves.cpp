//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void dfs(int i,int j, vector<vector<int>>& grid,vector<vector<bool>>& vis){
        vis[i][j] = true;
        
        vector<int> dir = {-1,0,1,0,-1};
        
        for(int k=0; k < 4; k++){
            int x = i + dir[k];
            int y = j + dir[k+1];
            
            if(x >=0 && y >=0 && x < grid.size() && y < grid[0].size() && grid[x][y] == 1 && !vis[x][y]){
                dfs(x,y,grid,vis);
            }
            
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        
        for(int i=0; i< n; i++){
            if(grid[i][0] == 1){
                dfs(i,0,grid,vis);
            }
            if(grid[i][m-1] == 1){
                dfs(i,m-1,grid,vis);
            }
        }
        
        for(int j= 0; j < m; j++){
            if(grid[0][j] == 1){
                dfs(0,j,grid,vis);
            }
            if(grid[n-1][j] == 1){
                dfs(n-1,j,grid,vis);
            }
        }
        int cnt = 0;
        for(int i= 1; i< n-1; i++){
            for(int j= 1; j< m-1;j++){
                if(vis[i][j] != true && grid[i][j] == 1){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends