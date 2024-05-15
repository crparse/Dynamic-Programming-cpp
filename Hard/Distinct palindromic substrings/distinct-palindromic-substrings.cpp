//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
        // code here
    set<string>st;
        
        for(auto it:s)
            st.insert(to_string(it));
        
        
        int n=s.size();
        for(int i=0;i<s.size();i++){
            int a=i-1;
            int b=i+1;
            while(a>=0 && b<n && s[a]==s[b]){
                st.insert(s.substr(a,b-a+1));
                a--;
                b++;
            }
        }
        for(int i=0;i<s.size();i++){
            int a=i;
            int b=i+1;
            while(a>=0 && b<n && s[a]==s[b]){
                st.insert(s.substr(a,b-a+1));
                a--;
                b++;
            }
        }
        return st.size();
        
    }
};


//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends