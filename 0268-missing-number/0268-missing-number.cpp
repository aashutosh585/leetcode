class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int m = n + 1;

        for(int i = 0; i < n; i++) {
            int val = nums[i] % m;   

            if(val == n) continue;

            nums[val] += m;        
        }

        for(int i = 0; i < n; i++) {
            if(nums[i] < m)       
                return i;
        }

        return n;
    }
};