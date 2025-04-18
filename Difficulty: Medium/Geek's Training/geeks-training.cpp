//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int solve(int day,int last,vector<vector<int>>& arr,vector<vector<int>>& dp)
    {
        if(dp[day][last] != -1){
            return dp[day][last];
        }
        
        if(day == 0){
            int maxi =0;
            for(int i=0; i< 3; i++){
                if(i != last){
                    maxi = max(maxi,arr[0][i]);
                }
            }
            return dp[day][last]  = maxi;
        }
        
        
        
        int maxi =0;
        
        for(int i=0; i< 3; i++){
            if(i != last ){
                int cost = arr[day][i] + solve(day-1,i,arr,dp);
                maxi = max(cost,maxi);
            }
        }
        
        return dp[day][last] = maxi;
    
    }  
    int maximumPoints(vector<vector<int>>& arr) {
        // Code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int> (4,-1));
        return solve(n-1,3,arr,dp);

        // dp[n-1][0] = max(arr[n-1][1],arr[n-1][2]);
        
        // dp[n-1][1] = max(arr[n-1][0],arr[n-1][2]);
        // dp[n-1][2] = max(arr[n-1][0],arr[n-1][1]);
        // dp[n-1][3] = max(arr[n-1][0],max(arr[n-1][1],arr[n-1][2]));
        
        
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends