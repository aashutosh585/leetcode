class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<int>dp(n,1),prev(n,-1);

        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
        }

        vector<int> ans;
        int idx = max_element(dp.begin(), dp.end()) - dp.begin();
        for(int i=idx;i>=0;i=prev[i]){
            ans.push_back(nums[i]);
        }


        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // for (int i = n - 1; i >= 0; i--) {
        //     for (int prev = n; prev >= 0; prev--) {

        //         int take = 0;
        //         if (prev == n || nums[i] % nums[prev] == 0) {
        //             take = 1 + dp[i + 1][i];
        //         }

        //         int ntake = dp[i + 1][prev];
        //         dp[i][prev] = max(take, ntake);
        //     }
        // }

        // int i = 0, prev = n;

        // while (i < n) {
        //     int take = 0;

        //     if (prev == n || nums[i] % nums[prev] == 0) {
        //         take = 1 + dp[i + 1][i];
        //     }

        //     int ntake = dp[i + 1][prev];

        //     if ((prev == n || nums[i] % nums[prev] == 0) &&
        //         dp[i][prev] == take) {

        //         ans.push_back(nums[i]);
        //         prev = i;
        //     }

        //     i++;
        // }

        return ans;
    }
};
