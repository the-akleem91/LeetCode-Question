//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool dfs(int i , vector<int> adj[] , vector<int>&vis , vector<int>&path)
   {
       vis[i] = 1;
       path[i] = 1;
       for(auto node : adj[i])
       {
           if(vis[node] == 0)
           {
               vis[node] = 1;
               path[node] = 1;
               if(dfs(node , adj , vis , path)) return true;
               path[node] = 0;
           }
           
           else if(path[node] == 1 ) return true;
       }
       path[i] = 0;
       return false;
   }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> vis (V , 0);
        vector<int> path(V , 0);
        
        for(int i = 0 ; i < V ; i++)
        {
            if(vis[i]==0) 
            {
                if(dfs(i , adj , vis , path)) return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends