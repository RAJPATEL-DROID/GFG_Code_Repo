//{ Driver Code Starts


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int findCoverage(vector<vector<int>>& matrix) {
        // Code here
           int rows = matrix.size();
    int cols = matrix[0].size();
    int totalCoverage = 0;

    // Directions arrays for up, down, left, and right movements
    int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
    for(int  i=0; i < rows; i++){
        for(int j= 0; j < cols; j++){
            
            if (matrix[i][j] == 0) {
                int coverage = 0;
                // Check all four possible directions
                for (int d = 0; d < 4; ++d) {
                    int newRow = i + directions[d][0];
                    int newCol = j + directions[d][1];
                    // Check if the new position is within bounds
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols) 
                    {
                        if (matrix[newRow][newCol] == 1) 
                        {
                            coverage++;
                        }
                    }
                }
                totalCoverage += coverage;
            }
        }
    }
    
    return totalCoverage;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        int ans = obj.findCoverage(matrix);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends