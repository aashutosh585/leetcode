class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int>mpp;
        int psum=0, cnt=0;
        for(auto &c:nums){
            psum+=c;
            int val= psum-k;
            if(val==0) cnt++;

            if(mpp.find(val)!=mpp.end()){
                cnt+=mpp[val];
            }

            mpp[psum]++;
        }

        return cnt;
    }
};