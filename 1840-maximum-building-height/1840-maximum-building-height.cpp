class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& res) {
        res.push_back({1, 0});

        sort(res.begin(), res.end());

        // Add restriction for building n
        if (res.back()[0] != n) {
            res.push_back(
                {n, res.back()[1] + (n - res.back()[0])}
            );
        }

        int m = res.size();

        // Left -> Right
        for (int i = 1; i < m; i++) {
            res[i][1] = min(
                res[i][1],
                res[i - 1][1] +
                    (res[i][0] - res[i - 1][0])
            );
        }

        // Right -> Left
        for (int i = m - 2; i >= 0; i--) {
            res[i][1] = min(
                res[i][1],
                res[i + 1][1] +
                    (res[i + 1][0] - res[i][0])
            );
        }

        long long ans = 0;

        for (int i = 1; i < m; i++) {
            long long x1 = res[i - 1][0];
            long long h1 = res[i - 1][1];

            long long x2 = res[i][0];
            long long h2 = res[i][1];

            long long d = x2 - x1;

            long long peak =
                max(h1, h2) + (d - abs(h1 - h2)) / 2;

            ans = max(ans, peak);
        }

        return (int)ans;
    }
};