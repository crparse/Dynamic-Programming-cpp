//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    public:
     bool solve(int ind , int n , int k , int m , vector<int> & A){
        if(ind >= n) return 1;
        int ans = 0;
        for(int i = ind + k - 1  ; i < n ; i++){
            if(A[i] - A[ind] <= m) ans |= solve(i + 1 , n , k , m , A);
            if(ans) break;
        } return ans;
    }
    bool partitionArray(int N, int K, int M, vector<int> &A){
        // code here
        sort(A.begin() , A.end());
        return solve(0 , N , K , M , A);
    }
};



//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, K, M;
        cin >> N >> K >> M;
        vector<int> A(N);
        for(int i = 0; i < N; i++){
            cin >> A[i];
        }
        Solution obj;
        bool ans = obj.partitionArray(N, K, M, A);
        if(ans){
            cout << "YES\n";
        }
        else{
            cout<< "NO\n";
        }
    }
}

// } Driver Code Ends