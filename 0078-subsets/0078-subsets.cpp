class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>& nums,int idx,vector<int>arr){

        if(idx==nums.size()){
            ans.push_back(arr);
            return;
        }

        solve(ans,nums,idx+1,arr);
        arr.push_back(nums[idx]);
        solve(ans,nums,idx+1,arr);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>arr;
        solve(ans,nums,0,arr);
        return ans;
    }
};