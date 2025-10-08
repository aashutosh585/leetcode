class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int n = spells.size(), m = potions.size();

        sort(potions.begin(), potions.end());

        for (auto x : spells) {
            int low = 0, high = m - 1, idx = m;
            while (low <= high) {
                int mid = low + (high - low) / 2;
                if (1LL * potions[mid] * x >= success) {
                    idx = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }
            ans.push_back(m - idx);
        }

        return ans;
    }
};
