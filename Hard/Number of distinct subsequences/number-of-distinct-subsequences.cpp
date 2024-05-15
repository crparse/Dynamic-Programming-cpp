//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

//User function template for C++


  class Solution{
  public:
  const int mod=1e9+7;
    int distinctSubsequences(string s){
        vector<int>check(256,-1);
        int n=s.length();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<=n;i++){  
            dp[i]=(2*dp[i-1])%mod; 
            if(check[s[i-1]]!=-1) dp[i]=(dp[i]-dp[check[s[i-1]]]+mod)%mod;
            check[s[i-1]]=i-1;
        }return dp[n]%mod;
    }
};




//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends