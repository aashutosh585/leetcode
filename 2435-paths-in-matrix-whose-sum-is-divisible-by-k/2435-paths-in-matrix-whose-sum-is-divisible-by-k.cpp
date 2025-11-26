class Solution {
public:
    int n, m, K;
    vector<vector<vector<int>>> dp;

    int solve(int i, int j, vector<vector<int>>& grid, int mod) {
        if(i == n-1 && j == m-1){
            return (mod + grid[i][j]) % K == 0;
        }

        int &res = dp[i][j][mod];
        if(res != -1) return res;

        int newMod = (mod + grid[i][j]) % K;
        long long ways = 0;

        if(i + 1 < n) ways += solve(i+1, j, grid, newMod);
        if(j + 1 < m) ways += solve(i, j+1, grid, newMod);

        return res = ways % 1000000007;
    }

    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        K = k;

        dp.assign(n, vector<vector<int>>(m, vector<int>(k, -1)));
        return solve(0, 0, grid, 0);
    }
};
