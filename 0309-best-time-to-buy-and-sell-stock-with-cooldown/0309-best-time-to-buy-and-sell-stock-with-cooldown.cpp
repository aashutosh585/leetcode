class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, vector<int>& arr, bool f) {
        if (i >= arr.size()) return 0;
        if (dp[i][f] != -1) return dp[i][f];
        int t, n;
        if (f == 0) {
            t = -arr[i] + solve(i + 1, arr, 1);
        } else {
            t = arr[i] + solve(i + 2, arr, 0);
        }
        n = solve(i + 1, arr, f);
        return dp[i][f] = max(t, n);
    }

    int maxProfit(vector<int>& arr) {
        int n = arr.size();
        dp.resize(n + 1, vector<int>(2, -1));
        return solve(0, arr, 0);
    }
};
