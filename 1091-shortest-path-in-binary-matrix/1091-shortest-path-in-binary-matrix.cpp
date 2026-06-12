class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        if(grid[0][0] == 1 || grid[n - 1][n - 1] == 1) return -1;

        queue<pair<int, int>> q;
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        dist[0][0] = 1;
        q.push({0, 0});

        vector<pair<int, int>> dir = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},           { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();

            if(i == n - 1 && j == n - 1)
                return dist[i][j];

            for(auto [di, dj] : dir) {
                int ni = i + di;
                int nj = j + dj;

                if(ni >= 0 && ni < n &&
                    nj >= 0 && nj < n &&
                    grid[ni][nj] == 0 &&
                    dist[ni][nj] == INT_MAX) {

                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return -1;
    }
};