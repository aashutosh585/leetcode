class Solution {
public:

    void solve(int idx,vector<vector<int>>&ans,vector<int>arr,vector<int>nums){
        ans.push_back(arr);
        for(int i=idx;i<nums.size();i++){
            if(i>idx && nums[i]==nums[i-1]) continue;

            arr.push_back(nums[i]);
            solve(i+1,ans,arr,nums);
            arr.pop_back();
        }

    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        vector<int>arr;
        solve(0,ans,arr,nums);
        return ans;
    }
};