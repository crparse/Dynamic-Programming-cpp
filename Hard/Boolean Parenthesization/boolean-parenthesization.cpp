//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int countWays(int n, string s){
        // code here
        vector<vector<int>> dpTrue(n, vector<int>(n));
        vector<vector<int>> dpFalse(n, vector<int>(n));
        int mod = 1003;
        
        for(int gap = 0; gap < n; gap+=2){
            for(int left = 0; left < n - gap; left+=2){
                int right = left + gap;
                if(gap == 0){
                    dpTrue[left][right] = (s[left] == 'T')? 1: 0;
                    dpFalse[left][right] = (s[left] == 'F')? 1: 0;
                }
                else{
                    for(int i = left + 1; i < right; i+=2){
                        int ltrue = dpTrue[left][i-1];
                        int rtrue = dpTrue[i+1][right];
                        int lfalse = dpFalse[left][i-1];
                        int rfalse = dpFalse[i+1][right];
                        
                        if(s[i] == '&'){
                            dpTrue[left][right] += ltrue*rtrue;
                            dpFalse[left][right] += lfalse*rtrue + ltrue*rfalse + lfalse*rfalse;
                        }
                        else if(s[i] == '|'){
                            dpTrue[left][right] += ltrue*rtrue + lfalse*rtrue + ltrue*rfalse;
                            dpFalse[left][right] += lfalse*rfalse;
                        }
                        else if(s[i] == '^'){
                            dpTrue[left][right] += lfalse*rtrue + ltrue*rfalse;
                            dpFalse[left][right] += ltrue*rtrue + lfalse*rfalse;
                        }
                    }
                    // cout<<left<<" "<<right<<" "<<dpTrue[left][right]<<" "<<dpFalse[left][right]<<"\n";
                    dpTrue[left][right] %= mod;
                    dpFalse[left][right] %= mod;
                    
                }
            }
        }
        return dpTrue[0][n-1];
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends