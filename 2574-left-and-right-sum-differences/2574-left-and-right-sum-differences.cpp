class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int>arr(nums.size());
        int psum=0;
        for(int i=0;i<arr.size();i++){
            psum+=nums[i];
            arr[i]= abs(sum-psum);
            sum=sum-nums[i];
        }

        return arr;
    }
};