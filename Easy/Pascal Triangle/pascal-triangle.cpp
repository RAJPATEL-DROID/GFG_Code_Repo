//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
    int mod = 1e9 + 7;
    vector<long long> nthRowOfPascalTriangle(int rowIndex) {
        // code here
        vector<long long> ansRow(rowIndex,0);
        ansRow[0] =1;

        for(int i=1;i< rowIndex;i++){
            for(int j=i;j >=1; j--){
                ansRow[j] = (ansRow[j] + ansRow[j-1])%mod;
            }
        }
        return ansRow;
    }
};


//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends