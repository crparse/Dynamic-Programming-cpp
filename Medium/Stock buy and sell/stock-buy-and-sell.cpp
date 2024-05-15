//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Function to find the days of buying and selling stock for max profit.
    vector<vector<int>> stockBuySell(vector<int> A, int n) {
        vector<vector<int>> result;
        if (n <= 1) return result;  // No profit can be made with less than two days.
        int buyDay = 0;
        int sellDay = 0;
        for (int i = 1; i < n; i++) {
            if (A[i] > A[i - 1]) {
                // If the stock price is increasing, extend the selling day.
                sellDay = i;
            } else {
                // If the stock price is not increasing, sell on the previous sell day (if any).
                if (buyDay < sellDay) result.push_back({buyDay, sellDay});
                // Set the next buy day to the current index.
                buyDay = sellDay = i;
            }
        }

        // Add the last transaction if the last element is part of an increasing sequence.
        if (buyDay < sellDay) result.push_back({buyDay, sellDay});
        return result;
    }
};




//{ Driver Code Starts.

int check(vector<vector<int>> ans, vector<int> A, int p)
{
    int c = 0;
    for(int i=0; i<ans.size(); i++)
        c += A[ans[i][1]]-A[ans[i][0]];
    return (c==p) ? 1 : 0;
}

int main()
{   
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> A(n);
        for (int i=0; i<n; ++i){
            cin>>A[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.stockBuySell(A, n);
        int p = 0;
        for(int i=0; i<n-1; i++)
        {
            int x = A[i+1]-A[i];
            if(x>0)
                p += x;
        }
        if(ans.size()==0)
            cout<<"No Profit";
        else{
            cout<<check(ans,A,p);
        }cout<<endl;
    }
    return 0;
}


// } Driver Code Ends