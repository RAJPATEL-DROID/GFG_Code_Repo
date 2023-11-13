//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    int lcs(string& x,string& y,int i,int j,vector<vector<int>>& memo){
        if(i <= 0 || j <= 0){
            return 0;
        }
  
        if(memo[i][j] != -1)return memo[i][j];
        if(i >= 1 && j >= 1 && x[i-1] == y[j-1]){
            return memo[i][j] = 1 + lcs(x,y,i-1,j-1,memo);
        }
        
        int a,b;
        a =b = 1e9;
        if(i >= 1)a = lcs(x,y,i-1,j,memo);
        
        if(j >= 1) b= lcs(x,y,i,j-1,memo);
        
        return memo[i][j] = max(a,b);
    }
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        //code here
        vector<vector<int>> memo(m+1 ,vector<int>(n+1,-1));
        int LCS =  lcs(x,y,m,n,memo);
        return m + n - LCS;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends