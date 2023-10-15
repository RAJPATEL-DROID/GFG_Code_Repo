//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node,vector<int> adj[],vector<int>& vis,int c,int d ){
	    vis[node] = true;
	    
	    for(auto nbr : adj[node]){
	        if(!vis[nbr] && (node != c | nbr != d)){
	            dfs(nbr,adj,vis,c,d);
	        }
	    }
	    
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        vector<int> visited(V,false);
        dfs(c,adj,visited,c,d);
        
        return !visited[d];
        
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}


// } Driver Code Ends