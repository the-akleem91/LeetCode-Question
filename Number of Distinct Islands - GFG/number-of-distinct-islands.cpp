//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:

  
  void bfs(int x, int y, vector<vector<int>>& grid,
         vector<vector<int>>& vis, vector<pair<int, int>>& res) {

    int m = grid.size();
    int n = grid[0].size();

    queue<pair<int, int>> q;
    q.push({x, y});
    vis[x][y] = 1;

    vector<int> nrow = {-1, 0, 1, 0};
    vector<int> ncol = {0, -1, 0, 1};

    while (!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();

        res.push_back({i - x, j - y}); // Using absolute coordinates

        for (int k = 0; k < 4; k++) {
            int row = i + nrow[k];
            int col = j + ncol[k];

            if (row >= 0 && row < m && col >= 0 && col < n &&
                grid[row][col] == 1 && vis[row][col] == 0) {
                vis[row][col] = 1;
                q.push({row, col});
            }
        }
    }
}


  int countDistinctIslands(vector<vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    vector<vector<int>> vis(m, vector<int>(n, 0));
    set<vector<pair<int, int>>> s;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (vis[i][j] == 0 && grid[i][j] == 1) {
                vector<pair<int, int>> res;
                bfs(i, j, grid, vis, res);
                s.insert(res);
            }
        }
    }

    return s.size();
}
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends