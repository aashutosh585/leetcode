class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int tar) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);
        for(int i = 0; i < n; i++) pref[i + 1] = pref[i] + (nums[i] == tar);

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int occ = pref[i + 1] - pref[j];
                int len = i - j + 1;

                if(occ > len / 2) cnt++;
            }
        }

        return cnt;
    }
};