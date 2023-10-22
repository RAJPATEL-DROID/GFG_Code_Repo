//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  int mod = 1e9+7;
    long long int pathsHelper(int m, int n, vector<vector<int>> &lookupTable) {
    // Base condition.
        if(m == 1 || n == 1) {             
            return 1;
        }
    
        // Check for solved subproblems.
        if(lookupTable[m][n] != -1) {       
            return lookupTable[m][n]%mod;
        }
    
        // Recursive call.
        long long int temp = (pathsHelper(m - 1, n, lookupTable) + pathsHelper(m, n - 1, lookupTable)) %mod;  
        lookupTable[m][n] = temp;
        return temp;                     
    }
    long long int numberOfPaths(int m, int n){
        // code here
        vector<vector<int>> lookupTable(m+1,vector<int>(n+1,-1));
        
        return pathsHelper(m,n,lookupTable);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> m >> n;
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
    return 0;
}

// } Driver Code Ends