//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends



class Solution{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n){ 
        
        int dp[n+1][W+1];
        
        memset(dp , 0 , sizeof(dp));
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=W ; j++){
                
                if(wt[i-1] <= j)  dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                else  dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][W];
    }
    
}; 
    
 // //Function to return max value that can be put in knapsack of capacity W.
    // int dp[1001][1001];
    // //Function to return max value that can be put in knapsack of capacity W.
    // int knapSack(int W, int wt[], int val[], int n){
    //     if(n==0 || W==0) return 0;
    //     if(dp[W][n]!=-1)
    //     return dp[W][n];
    //     if(W>=wt[n-1]) dp[W][n]=max(val[n-1]+knapSack(W-wt[n-1],wt,val,n-1),knapSack(W,wt,val,n-1));
    //     else dp[W][n]= knapSack(W,wt,val,n-1);
    //     return dp[W][n];
    // }
    
    
    // Solution() {
    //     memset(dp, -1, sizeof(dp));
    // }





//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends