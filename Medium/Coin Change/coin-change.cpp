//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    long long int count(int coins[], int N, int sum) {

        // code here.
        
        long long dp[sum+1] [N+1], i,j;
        for(i=0; i<=sum; i++){
            for(j=0; j<=N; j++) dp[i][j]=0;
        }
        for(i=0; i<=N; i++) dp[0][i]=1;
        for(j=1; j<=N; j++){
            for(i=1; i<=sum; i++){
                if(coins[j-1]<=i)
                    dp[i][j]=dp[i-coins[j-1]] [j] + dp[i][j-1];
                else
                    dp[i][j]=dp[i][j-1];
            }
        }return dp[sum][N];
        
       
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends