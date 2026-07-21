class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=-1, j=-1;
        int l=0, h=nums.size()-1;

        while(l<=h){
            int mid = l + (h-l)/2;

            if(nums[mid]==target){
                i=mid;
                h= mid-1;
            }
            else if(nums[mid]>target) h=mid-1;
            else l= mid+1;
        }

        l=0, h=nums.size()-1;
        while(l<=h){
            int mid = l + (h-l)/2;
            // cout<<"l="<<l<<" mid="<<mid<<" h="<<h<<endl;

            if(nums[mid]==target){
                j=mid;
                l= mid+1;
            }
            else if(nums[mid]>target) h=mid-1;
            else l= mid+1;
        }

        return {i,j};
    }
};