//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function
    void solve(int n,int from,int to,int aux,long long& count){
        if(n ==0){
            return;
        }
        solve(n - 1, from, aux, to,count);
        count++;
        cout<<"move disk " <<n<<" from rod "<<from<<" to rod " << to<<"\n";
        solve(n - 1, aux, to, from, count);

    }
    // avoid space at the starting of the string in "move disk....."
    long long toh(int N, int from, int to, int aux) {
        // Your code here
        long long count=0;
        solve(N,from,to,aux,count);
        return count;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}


//Position this line where user code will be pasted.
// } Driver Code Ends