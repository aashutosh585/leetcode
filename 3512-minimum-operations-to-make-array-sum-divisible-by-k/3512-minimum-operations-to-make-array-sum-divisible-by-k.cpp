class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int sum=accumulate(nums.begin(),nums.end(),0),n=nums.size();
        if(sum%k==0) return 0;
        return sum%k;
    }
};