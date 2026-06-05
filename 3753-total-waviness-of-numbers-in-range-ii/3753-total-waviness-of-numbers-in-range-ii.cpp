class Solution {
public:
    // key -> {count, waves}
    unordered_map<string, vector<long long>> mpp;

    vector<long long> solve(string &s, int idx, bool bound,
                            int tb, int ob, bool leadZero) {

        if (idx == (int)s.size()) {
            return leadZero ? vector<long long>{0, 0}
                            : vector<long long>{1, 0};
        }

        string key = to_string(idx) + "#" +
                     to_string(bound) + "#" +
                     to_string(tb) + "#" +
                     to_string(ob) + "#" +
                     to_string(leadZero);

        if (mpp.find(key) != mpp.end())
            return mpp[key];

        int ub = bound ? s[idx] - '0' : 9;

        long long totalCount = 0;
        long long totalWaves = 0;

        for (int i = 0; i <= ub; i++) {
            long long wave = 0;

            int nexttb, nextob;

            if (leadZero) {
                nexttb = -1;
                nextob = (i == 0) ? -1 : i;
            } else {
                nexttb = ob;
                nextob = i;

                if (tb >= 0 && ob >= 0) {
                    if ((tb > ob && ob < i) ||
                        (tb < ob && ob > i))
                        wave = 1;
                }
            }

            bool nextBound = bound && (i == ub);
            bool nextLeadZero = leadZero && (i == 0);

            vector<long long> sub =
                solve(s, idx + 1, nextBound,
                      nexttb, nextob, nextLeadZero);

            totalCount += sub[0];
            totalWaves += sub[1] + sub[0] * wave;
        }

        vector<long long> res = {totalCount, totalWaves};
        mpp[key] = res;
        return res;
    }

    long long getWaves(long long n) {
        if (n <= 0) return 0;

        mpp.clear();

        string s = to_string(n);

        if (s.size() < 3) return 0;

        vector<long long> ans =
            solve(s, 0, true, -1, -1, true);

        return ans[1];
    }

    long long totalWaviness(long long num1, long long num2) {
        return getWaves(num2) - getWaves(num1 - 1);
    }
};