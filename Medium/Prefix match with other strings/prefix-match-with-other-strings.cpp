//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    int klengthpref(string arr[], int n, int k, string str){    
        int count =0;
        
        // Traverse through Array 
        for(int i=0; i < n; i++){
            int j=0;
            // for each element of string check if the prefixes matches
            for(j=0;j< k;j++){
                if(str[j] != arr[i][j]){
                    break;
                }
            }    
            if(j == k){
                // cout<<arr[i]<<"\n";
                count++;
                
            }
        }
        
        return count;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for(int i=0;i<n;i++)
        {
            string s;
            cin>>arr[i];
            
        }
        int k;
        cin>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout << ob.klengthpref(arr, n, k, str) << endl;
    }
    return 0; 
} 

// } Driver Code Ends