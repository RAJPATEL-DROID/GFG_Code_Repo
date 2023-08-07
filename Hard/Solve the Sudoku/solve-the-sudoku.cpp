//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int row,int col,int k,int grid[N][N]){
        
        for(int i=0;i< 9 ;i++){
            if(grid[i][col] == k)return false;
            if(grid[row][i] == k)return false;
            if(grid[3*(row/3) + i/3 ][3*(col/3) + i%3] == k)return false;
        }
        
        return true;
    }
    
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        
        for(int i=0;i< 9;i++){
            for(int j=0;j< 9; j++){
                if(grid[i][j] == 0){
                    for(int k=1;k<=9; k++){
                        if(isValid(i,j,k,grid)){
                            grid[i][j] = k;
                            
                            if(SolveSudoku(grid))return true;
                            
                            grid[i][j] = 0;
                            
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<9;i++){
            for(int j=0;j<9; j++){
                cout<<grid[i][j]<<" ";
            }
            // cout<<"\n";
        }
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends