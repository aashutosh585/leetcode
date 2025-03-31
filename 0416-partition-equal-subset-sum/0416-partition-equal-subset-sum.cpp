class Solution {
public:
    vector<vector<bool>>dp;
    // bool solve(int n,int sum,vector<int>&arr){
    //     if(sum==0) return true;
    //     if(n==0) return false;

    //     if(dp[n][sum]) return dp[n][sum];

    //     if(sum<arr[n-1]) return dp[n][sum]=solve(n-1,sum,arr);

    //     return dp[n][sum]=solve(n-1,sum-arr[n-1],arr) || solve(n-1,sum,arr);
    // }
    bool canPartition(vector<int>& nums) {

        int n=nums.size(),sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0) return false;

        sum=sum/2;
        // dp.resize(nums.size()+1,vector<bool>(sum+1,false));
        // return solve(nums.size(),sum,nums);

        //  bottom up approch
        dp.resize(nums.size()+1,vector<bool>(sum+1,false));

        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(j<nums[i-1]){
                    dp[i][j]=dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
            }
        }
        return dp[n][sum];





        // int target = sum ;
        // vector<bool> dp(target + 1, false);
        // dp[0] = true;



        //  for (int n : nums) {
        //     for (int i = target; i >= n; i--) {
        //         if (dp[i]) continue;
        //         if (dp[i - n]) dp[i] = true;
        //         if (dp[target]) return true;
        //     }
        // }

        // return false;  






    }
};