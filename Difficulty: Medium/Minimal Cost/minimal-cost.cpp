//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int curr,int k,vector<int>& height,vector<int>& dp){
        if(curr ==0 ){
            return 0;
        }
        if(dp[curr] != -1)return dp[curr];
        int mini=INT_MAX;
        
        for(int i=1; i<=k ; i++){
            int energy=0;
            if(curr-i >= 0){
                energy = solve(curr-i,k,height,dp) + abs(height[curr] - height[curr-i]);
                // cout<< energy<< " " << curr-i <<" " << curr<<"\n";
            }else{
                break;
            }
            mini = min(mini,energy);
        }
        return dp[curr] = mini;
    }
  
    int minimizeCost(int k, vector<int>& arr) {
        // Code here
        // int mini = INT_MAX;
        // for(int i=arr.size()-1; i >= arr.size()- k; i--){
            // mini = min(mini,solve(i,k,arr));    
        // }
        vector<int> dp(arr.size(),-1);
        return solve(arr.size()-1,k,arr,dp);
    }
};

//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minimizeCost(k, arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends