//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Disjointset {
	vector<int> rank,parent,size;
public:
		Disjointset(int n){
			rank.resize(n+1, 0);
			parent.resize(n+1);
			size.resize(n+1);

			for(int i=0; i <= n; i++){
				parent[i] = i;
				size[i] = 1;
			}
		}

		int findParent(int node){
			if(parent[node] == node){
				return node;
			}
			return parent[node] = findParent(parent[node]);
		}

		void unionByRank(int u, int v){
			int ulp_u = findParent(u);
			int ulp_v = findParent(v);
			if(ulp_u == ulp_v)return;
			if(rank[ulp_u] < rank[ulp_v]){
				parent[ulp_u] = ulp_v;
			}
			else if(rank[ulp_v] < rank[ulp_u]){
				parent[ulp_v] = ulp_u;
			}
			else{
				parent[ulp_v] = ulp_u;
				rank[ulp_u]++;
			}
		}

		void unionBySize(int u,int v){
			int ulp_u = findParent(u);
			int ulp_v = findParent(v);

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

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
       // PRIM'S ALGORITHM
       
        // priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // vector<int> vis(V,0);
        
        // pq.push({0,V-1});
        // int sum = 0;
        // while(!pq.empty()){
        //     auto it = pq.top();
        //     pq.pop();
            
        //     int node = it.second;
        //     if(vis[node] == 1)continue;
            
        //     vis[node] = 1;
        //     int wt = it.first;
            
        //     sum += wt;
            
        //     for(auto itr: adj[node]){
        //         int adjNode = itr[0];
        //         int edWt = itr[1];
                
        //         if(!vis[adjNode]){
        //             pq.push({edWt,adjNode});
        //         }
        //     }
        // }
        
        // return sum;
        
        
        // KRUSKAL'S ALGRORITHM
        
        vector<pair<int,pair<int,int>>> edges;
        for(int i=0; i< V; i++){
            for(auto it: adj[i]){
                int adjNode = it[0];
                int wt = it[1];
                int node = i;
                
                edges.push_back({wt,{node,adjNode}});
            }    
        }
        
        Disjointset ds(V);
        
        sort(edges.begin(),edges.end());
        
        int mstWt = 0;
        
        for(auto it : edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            
            if(ds.findParent(u) != ds.findParent(v)){
                mstWt += wt;
                ds.unionBySize(u,v);
            }
        }
        
        return mstWt;
        
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
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends