//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int t[501][501];
    bool isPalindrome(string str,int i,int j){
        while(i < j){
            if(str[i] != str[j])return false;
            i++;
            j--;
        }
        return true;
    }
    int solve(string& str,int i,int j){
        if(i > j)return 0;
        if(isPalindrome(str,i,j))return 0;
        if(t[i][j] != -1)return t[i][j];
        
        int left = 0, right = 0;
        int ans= INT_MAX;
        for(int k=i; k <= j-1; k++){
            if(t[i][k] != -1){
                left = t[i][k];
            }else{
                left = solve(str,i,k);
                t[i][k] = left;
                
            }
            
            if(t[k+1][j] != -1){
                right  = t[k+1][j];
            }else{
                right = solve(str,k+1,j);
                t[k+1][j] = right;
            }
            
            int temp_ans = left + right + 1;
            ans = min(ans,temp_ans);
            
        }
    
        return ans;
    }
    int palindromicPartition(string str)
    {
        // code here
        memset(t,-1,sizeof(t));
        return solve(str,0,str.size()-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends