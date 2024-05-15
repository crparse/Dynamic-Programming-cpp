//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    int F(string S){
        int a[26] = {};
        for(char c : S) a[c - 'a'] = accumulate(begin(a),end(a),1);
        return accumulate(begin(a),end(a),0);
    }
public:
    string betterString(string s1, string s2){
        int cnt1 = F(s1) , cnt2 = F(s2);
        if(cnt1 == cnt2) return s1;
        return cnt1 > cnt2 ? s1 : s2;
    }
};





//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends