class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& arr) {
        if(i < 0 || i >= n || j < 0 || j >= m) return;
        if(grid[i][j] == 0 || arr[i][j] == 1) return;
        arr[i][j] = 1;

        dfs(i + 1, j, grid, arr);
        dfs(i - 1, j, grid, arr);
        dfs(i, j + 1, grid, arr);
        dfs(i, j - 1, grid, arr);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int cnt = 0;
        n = grid.size(), m = grid[0].size();
        vector<vector<int>> arr(n, vector<int>(m, 0));

        for(int i = 0; i < n; i++) {
            dfs(i, 0, grid, arr);     
            dfs(i, m - 1, grid, arr); 
        }

       
        for(int j = 0; j < m; j++){
            dfs(0, j, grid, arr);    
            dfs(n - 1, j, grid, arr); 
        }

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if (grid[i][j] == 1 && arr[i][j] == 0) cnt++;
            }
        }

        return cnt;
    }
};
