class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1);
        unordered_map<int, int> lake; 
        set<int> dry; 

        for (int i = 0; i < n; ++i) {
            if (rains[i] > 0) {
                ans[i] = -1;
                if(lake.count(rains[i])) {
                    int lastRain = lake[rains[i]];
                    auto it = dry.lower_bound(lastRain);
                    if (it == dry.end()) return {}; 
                    ans[*it] = rains[i];
                    dry.erase(it);
                }
                lake[rains[i]] = i;
            } else {
                dry.insert(i);
            }
        }
        return ans;
    }
};
