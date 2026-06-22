class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return;

        int pv=-1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]<nums[i+1]){
                pv=i;
                break;
            }
        }

        if(pv == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        cout<<pv;
        for(int i=n-1;i>pv;i--)
            if(nums[pv]<nums[i]){
                swap(nums[pv], nums[i]);
                break;
            }

        reverse(nums.begin()+pv+1, nums.end());

        return;

    }
};