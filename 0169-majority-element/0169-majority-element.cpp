class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt=0;
        int res=0;
        for(auto &it:nums){
            if(cnt==0) res=it;

            if(res==it) cnt++;
            else cnt--;
        }

        return res;
    }
};