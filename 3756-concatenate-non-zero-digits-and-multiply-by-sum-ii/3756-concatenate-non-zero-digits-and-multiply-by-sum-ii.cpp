class Solution {
public:
    static constexpr int MOD = 1000000007;

    vector<int> sumAndMultiply( string s,vector<vector<int>>& queries) {
        int n = s.size();

        vector<long long> sum(n + 1, 0);
        vector<int> cnt(n + 1, 0);
        vector<long long> val(n + 1, 0);
        vector<long long> power10(n + 1, 1);

        for (int i = 0; i < n; i++) {
            int d = s[i] - '0';

            sum[i + 1] = sum[i] + d;
            cnt[i + 1] = cnt[i];
            val[i + 1] = val[i];

            if (d != 0) {
                cnt[i + 1]++;
                val[i + 1] = (val[i] * 10 + d) % MOD;
            }
        }

        for (int i = 1; i <= n; i++) {
            power10[i] = power10[i - 1] * 10 % MOD;
        }

        vector<int> ans;

        for (auto& it : queries) {
            int l = it[0];
            int r = it[1];

            long long digitSum =
                sum[r + 1] - sum[l];

            int digits =
                cnt[r + 1] - cnt[l];

            long long number =
                (val[r + 1]
                 - val[l] * power10[digits] % MOD
                 + MOD) % MOD;

            long long result =
                digitSum % MOD * number % MOD;

            ans.push_back((int)result);
        }

        return ans;
    }
};