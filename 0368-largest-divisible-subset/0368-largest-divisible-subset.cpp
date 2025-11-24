class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // Fill DP bottom-up
        for (int i = n - 1; i >= 0; i--) {
            for (int prev = n; prev >= 0; prev--) {

                int take = 0;
                if (prev == n || nums[i] % nums[prev] == 0) {
                    take = 1 + dp[i + 1][i];
                }

                int ntake = dp[i + 1][prev];
                dp[i][prev] = max(take, ntake);
            }
        }

        // Reconstruction
        vector<int> ans;
        int i = 0, prev = n;

        while (i < n) {
            int take = 0;

            // If divisible, compute take
            if (prev == n || nums[i] % nums[prev] == 0) {
                take = 1 + dp[i + 1][i];
            }

            int ntake = dp[i + 1][prev];

            // TAKE only if it matches dp[i][prev]
            if ((prev == n || nums[i] % nums[prev] == 0) 
                && dp[i][prev] == take) {

                ans.push_back(nums[i]);
                prev = i;
            }
            // else skip

            i++;
        }

        return ans;
    }
};
