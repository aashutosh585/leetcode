class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=nums[0];
        int st=0, end=nums.size()-1;

        while(st<=end){
            int mid= st + (end-st)/2;
            if(nums[mid]<ans) ans=nums[mid];

            if(nums[st]<=nums[mid]){
                if(nums[st]<ans) end=mid-1;
                else st= mid+1;
            }
            else end= mid-1;
        }
        return ans;
    }
};