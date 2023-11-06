//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int i,int j, vector<vector<int>>& mat,  vector<vector<int>>& dp){
        // if(i == mat.size()-1){
        //     return mat[i][j];
        // }
        
        // if(dp[i][j] != -1)return dp[i][j];
        
        // int downLeft = INT_MIN;
        // if(j > 0)downLeft = mat[i][j] + solve(i+1,j-1,mat,dp);
        // int down = mat[i][j] + solve(i+1,j,mat,dp);
        // int downRight = INT_MIN;
        // if(j < mat[0].size()-1)downRight = mat[i][j] + solve(i+1,j+1,mat,dp);
        
        // return dp[i][j] = max(down,max(downLeft,downRight));
        
        if(j < 0 || j >= mat.size())return -1e9;
        
        if(i == 0)return mat[0][j];
        
        if(dp[i][j] != -1)return dp[i][j];
        
        int up = mat[i][j] + solve(i-1,j,mat,dp);
        int upLeft = mat[i][j] + solve(i-1,j-1,mat,dp);
        int upRight = mat[i][j] + solve(i-1,j+1,mat,dp);
        
        return dp[i][j] = max(up,max(upRight,upLeft));
    }
    int maximumPath(int N, vector<vector<int>> matrix)
    {
        // code here
        int maxi = 0;    
        vector<vector<int>> dp(N,vector<int>(N,-1));
        for(int i=0; i< N; i++){
            int temp = solve(N-1,i,matrix,dp);
            maxi = max(maxi, temp);
        }
        return maxi;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}
// } Driver Code Ends