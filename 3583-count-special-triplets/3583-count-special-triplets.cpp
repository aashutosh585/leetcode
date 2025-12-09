class Solution {
public:
    const int MOD = 1e9 + 7;
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<int,long long> right, left;
        for(int x : nums) right[x]++;  // initially all elements are in "right"
        
        long long cnt = 0;
        for(int j = 0; j < n; j++) {
            int val = nums[j];
            right[val]--;  
            
            long long before = left[2*val];  
            long long after  = right[2*val]; 
            
            cnt = (cnt + before * after) % MOD;
            left[val]++; 
        }
        
        return (int)cnt;
    }
};
