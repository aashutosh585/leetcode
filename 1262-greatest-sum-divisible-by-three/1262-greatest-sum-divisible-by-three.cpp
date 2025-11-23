class Solution {
public:
    vector<vector<int>> dp;

    int solve(int i, vector<int> &nums, int rem) {
        if (i == nums.size()) {
            return rem == 0 ? 0 : INT_MIN;
        }

        if (dp[i][rem] != -1) return dp[i][rem];

        int take = solve(i+1, nums, (rem + nums[i] % 3) % 3);
        if (take != INT_MIN) take += nums[i];

        int skip = solve(i+1, nums, rem);

        return dp[i][rem] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        dp.resize(n+1, vector<int>(3, -1));

        int ans = solve(0, nums, 0);
        return ans == INT_MIN ? 0 : ans;
    }
};
