//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    int dp[302][302];
public:
    int maxCoins(int N, vector<int> &nums){
        memset(dp,0,sizeof(dp));
        nums.push_back(1);
        nums.insert(nums.begin(),1);
        int n = nums.size();
        for(int i = n-2 ; i>=1 ; --i){
            for(int j = i ; j<n-1 ; ++j){
                int maxi = -1e9;
                for(int k = i ; k<j+1 ; ++k) {
                    int val = nums[i-1]*nums[k]*nums[j+1] + dp[i][k-1] + dp[k+1][j];
                    maxi = max(maxi,val);
                }
                dp[i][j] = maxi;
            }
        }
        return dp[1][n-2];
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin>>arr[i];

        Solution obj;
        cout << obj.maxCoins(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends