//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool lemonadeChange(int n, vector<int> &bills) {
        // code here
        int fives =0,tens =0;
        
        for(int i=0;i < n;i++){
            if(bills[i] == 5){
                fives++;
            }else if(bills[i] == 10){
                tens++;
                if(fives > 0){
                    fives--;
                }else{
                    return false;
                }
            }else if(bills[i] == 20){
                // cout<<fives<<" "<<tens<<" ";
                if(fives > 0){
                    if(tens>0){
                        fives--;
                        tens--;
                    }else if(fives >= 3){
                        fives -= 3;
                    }else{
                        return false;
                    }
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> bills(N);
        for (int i = 0; i < N; i++) cin >> bills[i];

        Solution obj;
        int ans = obj.lemonadeChange(N, bills);
        if (ans)
            cout << "True" << endl;
        else
            cout << "False" << endl;
    }
    return 0;
}
// } Driver Code Ends