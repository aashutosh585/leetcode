class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>mpp;
        for(auto it:nums){
            mpp[it]++;
        }
        int ans=0;
        for(auto it:mpp){
            ans=max(ans,it.second);
        }
        int cnt=0;

        for(auto it:mpp){
            if(it.second==ans) cnt++;
        }

        return cnt*ans;
        
    }
};