//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        // vector<int> dp(n,1),hash(n);
        // int maxi = 1;
        // int lastIndex = 0;
        // for(int i=0; i< n; i++){
        //     for(int prev =0; prev < i; prev++){
        //         if(arr[prev] < arr[i] && 1 + dp[prev] > dp[i]){
        //             dp[i] = 1 + dp[prev];
        //             hash[i] = prev;
        //         }
        //     }
        //     if(dp[i] > maxi){
        //         maxi = dp[i];
        //         lastIndex = i;
        //     }
        // }
        
        // vector<int> lis;
        // lis.push_back(arr[lastIndex]);
        // while(hash[lastIndex] != lastIndex){
        //     lastIndex = hash[lastIndex];
        //     lis.push_back(lastIndex);
        // }
        
        // reverse(lis.begin(),lis.end());
        // return lis;
        vector<int> dp(n, 1), hash(n); 
        int maxLISidx=0; // will store the index where LIS ends
        for(int i=0; i<n; i++){
            hash[i] = i; 
            for(int prev = 0; prev<i; prev++){
                if(arr[prev]<arr[i]){
                    if(dp[prev]+1>dp[i]){
                        dp[i] = 1 + dp[prev];
                        hash[i] = prev;
                    }
                }
            }
            maxLISidx = dp[i]>dp[maxLISidx]?i:maxLISidx;
        }
        int sz = dp[maxLISidx]; // length of the LIS
        vector<int> lis(sz);
        sz--;
        int j = maxLISidx; 
        while(hash[j]!=j){
            lis[sz--] = arr[j];
            j = hash[j];
        }
        lis[0] = arr[j];
        return lis;
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
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends