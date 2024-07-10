//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxSquare(int n, int m, vector<vector<int>> mat) {
        // code here
         int ans = 0;  // Initialize the maximum size of the square

        // Traverse the entire matrix
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (i == 0 || j == 0) {
                    // If we are at the first row or first column, take the value as it is
                    ans = max(ans, mat[i][j]);
                } else if (mat[i][j] != 0) {
                    // If the current cell is not zero, update it with the size of the square it can form
                    mat[i][j] += min(mat[i-1][j], min(mat[i-1][j-1], mat[i][j-1]));
                    ans = max(ans, mat[i][j]);  // Update the answer with the maximum size found
                }
            }
        }
        return ans;  // Return the maximum size of the square
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n * m; i++)
            cin >> mat[i / m][i % m];

        Solution ob;
        cout << ob.maxSquare(n, m, mat) << "\n";
    }
    return 0;
}
// } Driver Code Ends