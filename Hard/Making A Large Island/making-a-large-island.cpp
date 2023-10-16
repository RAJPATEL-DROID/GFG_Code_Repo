//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
public:
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        int n = grid.size();
        DisjointSet ds(n*n);
        int dir[5] = {-1,0,1,0,-1};
        // Step 1 : Connect the 1s and make initial islands
        
        for(int i=0;i < n;i++){
            for(int j=0;j < n; j++){
                if(grid[i][j] == 1){
                    
                    for(int k =0;k < 4; k++){
                        int nr =i + dir[k];
                        int nc = j + dir[k+1];
                        
                        if(nr >=0 && nc >=0 && nr < n && nc < n && grid[nr][nc]){
                            ds.unionBySize(i*n + j, nr*n + nc);
                        }
                    }
                }
            }
        }
        
        int mx =0;
        
        for(int i=0;i < n; i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 0){
                    set<int> components;
                    for(int k=0;k < 4;k++){
                        int nr = i + dir[k];
                        int nc = j + dir[k+1];
                        if(nr >=0 && nc >= 0 && nr < n && nc < n && grid[nr][nc]){
                            components.insert(ds.findUPar(nr*n +  nc));
                        }
                    }
                    
                    int totalSize =0;
                    for(auto it : components){
                        totalSize += ds.size[it];
                    }
                    mx = max(mx,totalSize+1);
                }
            }
        }
        
        for(int cell =0; cell < n*n ; cell++){
            mx = max(mx,ds.size[ds.findUPar(cell)]);
        }
        return mx;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends