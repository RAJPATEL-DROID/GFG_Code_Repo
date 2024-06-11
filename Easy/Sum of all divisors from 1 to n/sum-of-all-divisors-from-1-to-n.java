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
            int N=sc.nextInt();
            Solution ob = new Solution();
            long ans  = ob.sumOfDivisors(N);
            System.out.println(ans);
        }
    }
}

// } Driver Code Ends


//User function Template for Java
class Solution{
    // static long func(int x)
    // {
    //     long ans = 0L;
        
    //     for(int i=1; i*i <= x; i++)
    //     {
    //         if(x%i == 0)
    //         {
    //             ans += i;
    //             if(i*i != x)
    //             {
    //                 ans += x/i;
    //             }
    //         }
    //     }
        
    //     return ans;
    // }
    static long sumOfDivisors(int N){
        // code here
        long ans = 0L;
        
        // for(int i=1; i<= N; i++){
        //     ans += func(i);
        // }
        
        int i =1 ;
        while(i <= N ){
            int count = N/i;
            ans = ans + i * count;
            i++;
        }
        return ans;
                
    }
}