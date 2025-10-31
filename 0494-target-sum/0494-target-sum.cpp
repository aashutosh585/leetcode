class Solution {
public:
    int solve(int idx,vector<int>&nums, int target){
        if(idx==nums.size()){
            return target==0? 1: 0;
        }

        int x=solve(idx+1,nums,target-nums[idx]);
        int y=solve(idx+1,nums,target+nums[idx]);

        return x+y;
    }

    int findTargetSumWays(vector<int>& nums, int target){
        return solve(0,nums,target);
    }
};