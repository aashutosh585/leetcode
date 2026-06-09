class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mn=INT_MAX,mx=0;
        for(auto &it:nums){
            mn=min(mn, it);
            mx=max(mx,it);
        }

        long long ans = (mx -mn),res=0;
        while(k--){
            res += ans;
        }
        return res;
    }
};