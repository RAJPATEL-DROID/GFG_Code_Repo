//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isPossible(int N, int arr[]) {
        // code here
        int digit, sum = 0;  
        for(int i=0;i<N;i++){
            int number=arr[i];
            while(number > 0)  {
               digit = number % 10;  
               sum = sum + digit;  
               number = number / 10;
           } 
        }
        if(sum%3==0){
            return 1;
        }
        else{
            return 0;
        }
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        int arr[N];
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution ob;
        cout << ob.isPossible(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends