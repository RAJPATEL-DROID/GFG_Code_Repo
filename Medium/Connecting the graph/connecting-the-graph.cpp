//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Disjointset{
    public:
    vector<int> parent,size;
    
    Disjointset(int n){
        size.resize(n+1,1);
        parent.resize(n+1,1);
        
        for(int i=0;i <=n; i++){
            parent[i] = i;
        }
    }
    
    int findUPar(int node){
        if(parent[node] == node)return node;
        return parent[node] = findUPar(parent[node]);
    }
    
    void unionBySize(int u,int v){
        int ulp_u = findUPar(u);
		int ulp_v = findUPar(v);

		if(ulp_u == ulp_v)return;

		if(size[ulp_v] < size[ulp_u]){
			parent[ulp_v] = ulp_u;
			size[ulp_u] += size[ulp_v];
		}else{
			parent[ulp_u] = ulp_v;
			size[ulp_v] += ulp_u;
		}
    }
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        Disjointset ds(n);
        int cntExtraEdges = 0;
        for(auto it: edge){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                cntExtraEdges++; 
            }else{
                ds.unionBySize(u,v);
            }
        }
        int cmp=0;
        for(int i=0; i< n;i++){
            if(ds.parent[i] == i)cmp++;
        }
        int ans = cmp -1;
        if(cntExtraEdges >= ans)return ans;
        return -1;
    }
        
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends