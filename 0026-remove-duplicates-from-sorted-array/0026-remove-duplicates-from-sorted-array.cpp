class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int j=1, x;
        int i=1, n=nums.size();
        if(n==1) return 1;

        while(i<n){
            while(i<n && nums[i-1]==nums[i]) i++;
            if(i>=n) break;
            nums[j]=nums[i];
            j++;
            i++;
        }
      
        // cout<<j<<endl;
        return j;
        
    }
};