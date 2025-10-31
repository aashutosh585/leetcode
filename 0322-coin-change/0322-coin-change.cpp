class Solution {
public:
    vector<int> dp;

    int solve(vector<int>& coins, int amt) {
        if (amt == 0) return 0;
        if (amt < 0) return INT_MAX - 1; 
        if (dp[amt] != -1) return dp[amt];

        int x = INT_MAX - 1;
        for (int c : coins) {
            int take = solve(coins, amt - c);
            x = min(x, take + 1);
        }

        return dp[amt] = x;
    }

    int coinChange(vector<int>& coins, int amt) {
        dp.resize(amt + 1, -1);
        int res = solve(coins, amt);
        return (res >= INT_MAX - 1) ? -1 : res;
    }
};
