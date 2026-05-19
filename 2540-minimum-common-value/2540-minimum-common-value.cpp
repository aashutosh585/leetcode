class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int res=INT_MAX;
        int i=0,j=0, n=nums1.size(), m= nums2.size();

        while(i<n && j<m){
            if(nums1[i]==nums2[j]){
                res=min(res, nums1[i]);
                i++,j++;
            }
            else if(nums1[i]>nums2[j]) j++;
            else i++;
        }

        return res==INT_MAX? -1: res;
  
    }
};