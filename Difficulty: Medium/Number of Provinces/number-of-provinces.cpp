//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  void bfs(vector<vector<int>> adj,vector<int>& vis,int curr){
      queue<int> q;
      q.push(curr);
      vis[curr] = 1;
      
      while(!q.empty()){
          curr = q.front();
          q.pop();
          
          for(int i =0 ; i < adj.size(); i++){
            if(adj[curr][i]== 1 && vis[i] == 0){
                q.push(i);
                vis[i] = 1;
            }
          }
      }
      
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int cnt =0;
        vector<int> visited(V,0);
        
        for(int i=0; i< V; i++)
        {
            if(!visited[i]){
                cnt++;
                
                bfs(adj,visited,i);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends