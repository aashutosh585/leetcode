class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n=nums.size(),msb=0;
        vector<bool>ans;
        for(int i=0; i<n; i++){
            msb=((msb<<1)+nums[i])%5;
            ans.push_back(msb==0);
        }
        return ans;

    }
};