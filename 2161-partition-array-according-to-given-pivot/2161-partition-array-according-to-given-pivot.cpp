class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
       
       int n=nums.size();
       int l=0, h=0;
        vector<int>ans(n,pivot);
        for(auto &it:nums){
            if(it<=pivot) h++;
        }

        for(int i=0;i<n;i++){
            if(nums[i] < pivot){
                ans[l]=nums[i];
                l++;
            }
            else if(nums[i]>pivot){
                ans[h]=nums[i];
                h++;
            }
        }

        return ans;
    }
};