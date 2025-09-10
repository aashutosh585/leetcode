class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& l, vector<vector<int>>& f) {
        unordered_map<int, unordered_set<int>> mpp;
        int m = l.size();
        for (int i = 0; i < m; ++i) {
            for (int lang : l[i]) mpp[i+1].insert(lang);
        }

        unordered_set<int> st;
        for (auto &pr : f) {
            int a = pr[0], b = pr[1];
            const auto &sa = mpp[a];
            const auto &sb = mpp[b];
            bool share = false;
            if (sa.size() < sb.size()) {
                for (int x : sa) if (sb.find(x) != sb.end()) { share = true; break; }
            } else {
                for (int x : sb) if (sa.find(x) != sa.end()) { share = true; break; }
            }
            if (!share) { st.insert(a); st.insert(b); }
        }

        if (st.empty()) return 0;

        vector<int> known(n+1, 0);
        for (int u : st) {
            for (int lang : mpp[u]) if (lang >= 1 && lang <= n) known[lang]++;
        }

        int ans = m;
        int need = st.size();
        for (int i = 1; i <= n; ++i) ans = min(ans, need - known[i]);

        return ans;
    }
};
