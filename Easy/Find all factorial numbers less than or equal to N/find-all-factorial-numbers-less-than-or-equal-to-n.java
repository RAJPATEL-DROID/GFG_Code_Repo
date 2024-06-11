//{ Driver Code Starts
//Initial Template for Java
import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            long N=sc.nextLong();
			
            Solution ob = new Solution();
            ArrayList<Long> ans = ob.factorialNumbers(N);
            for(long num : ans){
                System.out.print(num+" ");
            }
            System.out.println();
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution{
    
   
   static Long fact(int N)
   {
       if(N <= 1)return 1L;
       
       return N* fact(N-1);
   }
   
   
    static ArrayList<Long> factorialNumbers(long N){
        // code here
        ArrayList<Long> solution = new ArrayList<Long>();
        int n = 1;
        while(fact(n) <= N)
        {
            solution.add(fact(n));
            n++;
        }
        
        
        return solution;
        
        
    }
}