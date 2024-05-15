//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
  public:
  
  bool dfs(vector<int> adj[], vector<int> &vis, int node, int &count) {
        vis[node] = 1;
        bool select = false;
        for (auto it: adj[node]) {
            
            if (!vis[it]) {
                
                if (!dfs(adj, vis, it, count)) 
                    select = true;
                
            }
        }
        if (select==true) count++;
        return select;
  }  
    int countVertex(int N, vector<vector<int>>edges){
        // code here
        vector<int> adj[N+1];
        
        for (auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
         
        vector<int> vis(N+1, 0);
        int count = 0;
        dfs(adj, vis, 1, count);
        return count;
    }
};


//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends