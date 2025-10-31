class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int amt, vector<int>& coins) {
        if (amt == 0) return 1;
        if (i == coins.size() || amt < 0) return 0;
        if(dp[i][amt]!=-1) return dp[i][amt];

        int take = solve(i, amt - coins[i], coins);
        int skip = solve(i + 1, amt, coins);

        return dp[i][amt]=take + skip;
    }

    int change(int amt, vector<int>& coins){
        dp.assign(coins.size(), vector<int>(amt + 1, -1));
        return solve(0, amt, coins);
    }
};
