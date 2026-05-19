class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int res=INT_MAX;
        set<int>st;
        for(auto &x:nums1) st.insert(x);
        for(auto &y:nums2) if(st.find(y)!=st.end()) res=min(res, y);
        
        return res==INT_MAX? -1: res;
  
    }
};