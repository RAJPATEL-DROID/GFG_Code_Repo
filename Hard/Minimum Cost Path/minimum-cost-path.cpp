//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
   
    //Function to return the minimum cost to react at bottom
	//right cell from top left cell.
    int minimumCostPath(vector<vector<int>>& grid) 
    {
        // Code here
        int n = grid.size();
        
        vector<vector<int>> distance(n,vector<int>(n,1e9));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>> q;
        
        distance[0][0] =grid[0][0];
        q.push({grid[0][0],{0,0}});
        
        int dir[5] = {-1,0,1,0,-1};
        
        while(!q.empty()){
            int cost = q.top().first;
            int r = q.top().second.first;
            int c = q.top().second.second;
            q.pop();
            
            for(int i=0;i < 4; i++){
                int nr = r + dir[i];
                int nc = c + dir[i+1];
                
                if(nr >= 0 && nr < n && nc >= 0 && nc < n){
                    if(cost +grid[nr][nc] < distance[nr][nc]){
                        distance[nr][nc]  = cost + grid[nr][nc];
                        q.push({distance[nr][nc],{nr,nc}});
                    }
                }
            }
        }
        
        return distance[n-1][n-1];
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.minimumCostPath(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends