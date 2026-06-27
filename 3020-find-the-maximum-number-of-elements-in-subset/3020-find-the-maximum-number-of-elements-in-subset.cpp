class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> mpp;
        int cnt = 0;

        for(int x : nums) x == 1? cnt++ : mpp[x]++;
    
        int ans = 1;
        if(cnt>0) cnt % 2 == 0? ans = max(ans, cnt - 1) : ans = max(ans, cnt);
        
        auto freq = [&](long long x) {
            auto it = mpp.find(x);
            return (it == mpp.end()) ? 0 : it->second;
        };

        for(auto &[x, f] : mpp) {
            long long cur = x;
            int len = 1;

            while(freq(cur) >= 2) {
                len += 2;
                if(cur > 1000000000LL / cur) break;
                cur *= cur;
            }
            freq(cur) == 1? ans = max(ans, len): ans = max(ans, len - 2);
        }

        return ans;
    }
};