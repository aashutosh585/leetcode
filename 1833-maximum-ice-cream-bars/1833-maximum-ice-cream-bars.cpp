class Solution {
public:
    int maxIceCream(vector<int>& cos, int coins) {
        int mx = *max_element(cos.begin(), cos.end());
        vector<int> freq(mx + 1, 0);

        for(int cost : cos) freq[cost]++;

        int ans = 0;
        for (int cost = 1; cost <= mx; cost++) {
            while (freq[cost] > 0 && coins >= cost) {
                coins -= cost;
                ans++;
                freq[cost]--;
            }
        }

        return ans;
    }
};