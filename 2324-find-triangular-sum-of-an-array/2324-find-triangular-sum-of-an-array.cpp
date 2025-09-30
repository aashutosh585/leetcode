class Solution {
public:
    int triangularSum(vector<int>& nums) {
        int n=nums.size(),j=0;
   
        while(j!=n){

            for(int i=1;i<n-j;i++){
                nums[i-1] = (nums[i-1]+nums[i])%10;
            }
            j++;
        }

        return nums[0];
    }
};