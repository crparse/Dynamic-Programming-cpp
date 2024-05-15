//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
public:
  int rec(int level,int sum,int nums[],int n,vector<vector<int> >& dp){
      //pruning
      
      //base case
      if(level==n){
          if(sum==0) return 1;
          else return 0;
      }
      //cache check
      if(dp[level][sum]!=-1) return dp[level][sum];
      
      
      //computations
      int ans=0;
      if(sum>=nums[level]){
          ans|=rec(level+1,sum-nums[level],nums,n,dp);
      }
      ans|=rec(level+1,sum,nums,n,dp);
      //save and return
      return dp[level][sum]=ans;
  }
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum=accumulate(arr,arr+n,0);
	    int maxTarget=sum/2;
	    vector<vector<int> > dp(n+1,vector<int>(sum+1,-1)) ;
	    int maxi=INT_MIN;
	    for(int i=0;i<=maxTarget;i++){
	        if(rec(0,i,arr,n,dp)){
	            maxi=max(maxi,i);
	        }
	    }
	    int ans=(sum-maxi)-maxi;
	    return ans;
	}
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends