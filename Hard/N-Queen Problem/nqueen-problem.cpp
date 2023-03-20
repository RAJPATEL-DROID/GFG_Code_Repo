//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    void solve(int col,int n,vector<vector<int>> &ans,vector<int> &temp,vector<int> &leftRow,
    vector<int> &upDiagonal,vector<int> &dwDiagonal){
        if(col==n){
            ans.push_back(temp);
            return;
        }

        for(int row=0;row<n;row++){
            if(leftRow[row]==0 && upDiagonal[n-1+col-row]==0 && dwDiagonal[col+row]==0){
                leftRow[row]=1;
                upDiagonal[n-1+col-row]=1;
                dwDiagonal[col+row]=1;
                temp.push_back(row+1);
                solve(col+1,n,ans,temp,leftRow,upDiagonal,dwDiagonal);
                temp.pop_back();
                leftRow[row]=0;
                upDiagonal[n-1+col-row]=0;
                dwDiagonal[col+row]=0;
            }
        }
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> leftRow(n,0),uP(2 * n - 1,0),dW(2 * n - 1,0);
        solve(0,n,ans,temp,leftRow,uP,dW);
        return ans;
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends