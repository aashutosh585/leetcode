class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int m=nums.size();
        unordered_map<int,int>mpp;
        int ans=0,res=0;

        for(int i=0;i<m;i++){
            mpp[nums[i]]++;
            if(ans<mpp[nums[i]]){
                res=nums[i];
                ans=mpp[nums[i]];
            }
        }

        return res;
        
        
        
    }
};