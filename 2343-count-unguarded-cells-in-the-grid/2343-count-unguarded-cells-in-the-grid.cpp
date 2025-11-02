class Solution {
public:
    void X(vector<vector<int>>& grid, int i, int j, int p) {
        int m = grid.size(), n = grid[0].size();
        for (int x = i + p; x >= 0 && x < m; x += p) {
            if (grid[x][j] == -1 || grid[x][j] == 1) break; 
            if (grid[x][j] == 0) grid[x][j] = 2; 
        }
    }

    void Y(vector<vector<int>>& grid, int i, int j, int p) {
        int m = grid.size(), n = grid[0].size();
        for (int y = j + p; y >= 0 && y < n; y += p) {
            if (grid[i][y] == -1 || grid[i][y] == 1) break;
            if (grid[i][y] == 0) grid[i][y] = 2; 
        }
    }

    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto &w : walls) grid[w[0]][w[1]] = -1; 
        for (auto &g : guards) grid[g[0]][g[1]] = 1;

        for (auto &g : guards) {
            int i = g[0], j = g[1];
            X(grid, i, j, 1);
            X(grid, i, j, -1);
            Y(grid, i, j, 1);
            Y(grid, i, j, -1);
        }

        int cnt = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) cnt++; 
            }
        }
        return cnt;
    }
};
