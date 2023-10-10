//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(vector<int> adj[],int u,int parent,bool vis[],int tim[],int low[],int isAP[],int& timer){
        int children =0;
        vis[u] = true;
        tim[u] = low[u] = ++timer;
        
        for(auto v: adj[u]){
            
            if(!vis[v]){
               
                dfs(adj,v,u,vis,tim,low,isAP,timer);
                
                low[u] = min(low[u],low[v]);
                
                if(parent != -1 && low[v] >= tim[u]){
                    isAP[u] = true;
                    
                }
                children++;
            }
            else if(v != parent){
                low[u] = min(low[u],tim[v]);
            }
        }
        
        if(parent == -1 && children > 1){
            isAP[u] = 1;
        }
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        int timer =0;
        int tim[V] ={0};
        int low[V];
        bool vis[V] ={false};
        int isAP[V] ={0};
        
        for(int i=0;i < V; i++){
            if(!vis[i]){
                dfs(adj,i,-1,vis,tim,low,isAP,timer);
            }
        }
        vector<int> ans;
        for(int i=0;i < V; i++){
            if(isAP[i] != 0){
                ans.push_back(i);
            }
        }
        if(ans.size() == 0)return {-1};
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends