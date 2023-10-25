//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int dp[1001][1001];
    int solve(int n,int w,int val[],int wt[]){
        if(n == 0 || w==0)return 0;
        if(dp[n][w] != -1)return dp[n][w];
        int withCurrWt = 0;
        int withoutCurrWt =0;
        
        withoutCurrWt = solve(n-1,w,val,wt);
        if(w >= wt[n-1]){
            return dp[n][w] =max(withoutCurrWt, val[n-1] + solve(n,w-wt[n-1],val,wt));
        }
        return dp[n][w] = withoutCurrWt;
    };
    
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        memset(dp,-1,sizeof(dp));
        return solve(N,W,val,wt);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends