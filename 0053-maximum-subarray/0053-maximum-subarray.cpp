class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=nums[0];
        int psum=nums[0];

        for(int i=1;i<nums.size();i++){
            int val=nums[i];
            if(psum<0){
                if(val>=psum) psum=val;
            }
            else{
                if(val>=0 || abs(val)< psum){
                    psum+=val;
                }
                else psum = min(psum, val);
            }
            ans=max(ans, psum);
        }
        return ans;
    }
};