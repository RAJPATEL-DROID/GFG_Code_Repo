//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        // DP
        long long total_water = 0;
        int lmax[n];
        int rmax[n];
        
        lmax[0] = arr[0];
        for(int i=1; i<= n-1; i++)
            lmax[i] = max(lmax[i-1],arr[i]);
            
        rmax[n-1] = arr[n-1];
        for(int i=n-2; i>=0; i--)
            rmax[i] = max(rmax[i+1],arr[i]);
            
        for(int i=1; i<n-1; i++)
        total_water = total_water + (min(lmax[i],rmax[i])-arr[i]);
        return total_water;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends