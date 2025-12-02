class Solution {
public:
    int mod=1e9+7;
    int countTrapezoids(vector<vector<int>>& arr) {
        int cnt=0;
        unordered_map<int,int>mpp;
        for(auto it:arr) mpp[it[1]]++;

        long long ans = 0, sum = 0;
        
        for(auto& [_, it] : mpp) {
            long long val = (long long)it * (it - 1) / 2;
            ans += val * sum;
            sum += val;
        }
        return ans % mod;
    }
};