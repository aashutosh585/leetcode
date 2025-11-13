class Solution {
public:
    int maxOperations(string s) {
        int ans = 0, n = s.size(), f = 0, cnt = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                f = 1;
                cnt++;
            } else {
                if (f == 1)
                    ans += cnt;
                f = 0;
            }
        }
        return ans;
    }
};