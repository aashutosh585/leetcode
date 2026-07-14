class Solution {
public:
    int MOD=1e9+7;
    vector<vector<vector<int>>>dp;
    
    int solve(int idx, int g1, int g2, vector<int>& nums) {
        if(idx == nums.size()) return (g1 != 0 && g2 != 0 && g1 == g2);
        if(dp[idx][g1][g2] != -1) return dp[idx][g1][g2];

        long long ans = 0;
        ans += solve(idx + 1, __gcd(g1, nums[idx]), g2, nums);
        ans += solve(idx + 1, g1, __gcd(g2, nums[idx]), nums);
        ans += solve(idx + 1, g1, g2, nums);

        return dp[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+1, vector<vector<int>>(201, vector<int>(201, -1)));

        return solve(0,0,0,nums);
    }
};