//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        int i,j;
        int val[n+1];
        val[0]=0;
        
        for(int i=1; i<=n; i++){
            int max_val=INT_MIN;
            for(j=0; j<i; j++) max_val=max(max_val,price[j] + val[i-j-1]);
            val[i]=max_val;
        }
        
        return val[n];
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends