//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& A, int key) {
        // complete the function here
        int l =0,h = A.size()-1;
        while(l <= h)
        {
            int mid = (l + h)/2;
            
            if(A[mid] == key)
                return mid;
            
            if(A[l] <= A[mid]) // left half sorted
            {
                if(key >= A[l] && key < A[mid])
                    h = mid -1;
                else 
                    l = mid +1;
            }
            
            else 
            {
                if(key <= A[h] && key > A[mid])
                    l = mid +1;
                else 
                    h = mid -1;
            }
            
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends