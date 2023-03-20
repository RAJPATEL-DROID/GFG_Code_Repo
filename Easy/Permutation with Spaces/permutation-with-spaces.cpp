//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    void generateString(string s,string op,vector<string>& ans){
        if(s.size() == 0){
            ans.push_back(op);
            return;
        }
        
        string temp1 = op;
        string temp2 = op;
        temp1.push_back(' ');
        temp1.push_back(s[0]);
        temp2.push_back(s[0]);
        s.erase(s.begin() + 0);
        generateString(s,temp1,ans);
        generateString(s,temp2,ans);
    };
    vector<string> permutation(string S){
        // Code Heres
        string op = "";
        op.push_back(S[0]);
        S.erase(S.begin()+0);
        vector<string>ans;
        generateString(S,op,ans);
        return ans;
    }
};

//{ Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}

// } Driver Code Ends