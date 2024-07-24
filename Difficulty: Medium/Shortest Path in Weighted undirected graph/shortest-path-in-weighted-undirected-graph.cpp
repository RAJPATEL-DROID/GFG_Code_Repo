//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        
        for(auto it:edges){
             adj[it[0]].push_back({it[1],it[2]});
             adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int> > > pq;
        
        pq.push({0,1});
        
        vector<int> dist(n+1,INT_MAX);
        
        dist[1] =0;
        
        vector<int> parent(n+1,-1);
        
        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            if(d > dist[node])continue;
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                if(dist[adjNode] > d + wt){
                    dist[adjNode] = d + wt;
                    parent[adjNode] = node;
                    pq.push({d + wt, adjNode});
                }
            }
        }
        if(dist[n] == INT_MAX)return {-1};
        
        vector<int> ans;
        int node =n;
        while(node != -1){
            // cout << node << dist[node]<<"\n";
            ans.push_back(node);
            node = parent[node];
        }
        ans.push_back(dist[n]);
        reverse(ans.begin(),ans.end());
        return ans;
    
        
    }
};


//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        map<pair<int, int>, int> mp;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
            mp[{edges.back()[0], edges.back()[1]}] = edges.back()[2];
            mp[{edges.back()[1], edges.back()[0]}] = edges.back()[2];
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        int ans = 0;
        for (int i = 2; i < res.size(); i++) {
            ans += mp[{res[i], res[i - 1]}];
        }
        if (ans == res[0]) {

        } else if (res.size() == 1 && res[0] == -1)
            ans = res[0];
        else
            ans = -2;
        cout << ans << endl;
    }
}

// } Driver Code Ends