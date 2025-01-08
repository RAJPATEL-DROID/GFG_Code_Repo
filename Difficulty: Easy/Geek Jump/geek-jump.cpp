//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

/*
class Solution {
  public:
    
    int solve(int curr,vector<int> height, vector<int>& dp){
        if(curr == 0)return 0;
        
        if(dp[curr] != -1)return dp[curr];
        
        
        int step1 = solve(curr-1,height,dp) + abs(height[curr] - height[curr-1]);
        
        int step2 = INT_MAX;
        
        if(curr > 1){
            step2 = solve(curr-2,height,dp) + abs(height[curr] - height[curr-2]);
        }
        
        return dp[curr] = min(step1,step2);
    }
  
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        
        return solve(n-1,height,dp);
        
    
        
    }*/
// };

class Solution {
  public:
    
    int solve(vector<int>& heights, int n,vector<int>& dp){
        if(n == 0)return 0;
        
        if(dp[n] != -1)return dp[n];
    
        int oneStep = solve(heights,n-1,dp) + abs(heights[n] - heights[n-1]);
        int twoStep = INT_MAX;
        if(n > 1)twoStep = solve(heights,n-2,dp) + abs(heights[n] - heights[n-2]);
        return dp[n] = min(oneStep,twoStep);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int> dp(n+1,-1);
        return solve(height,n-1,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends