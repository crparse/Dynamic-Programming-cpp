//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

/*
class Solution{
public:
	int perfectSum(int arr[], int n, int sum){
        // Your code goes here
        int dp[n+1][sum+1];
        for(int i=0;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(i==0) dp[i][j]=0;
                if(j==0) dp[i][j]=1;
                
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=0;j<sum+1;j++){
                if(arr[i-1]<=j) dp[i][j] =dp[i-1][j] +dp[i-1][j-arr[i-1]];
                else dp[i][j]= dp[i-1][j];
            }
        }
        return dp[n][sum];
	}
	  
};
*/

class Solution{

	public:
    int perfectSum(int arr[], int n, int sum){
    vector<int> dp(sum + 1, 0);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = sum; j >= arr[i]; j--) {
            dp[j] += dp[j - arr[i]];
            dp[j] %= 1000000007;  
        }
    }
    return dp[sum];
}
	  
};




//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends