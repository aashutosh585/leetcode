class Solution {
public:
    bool check(vector<string>& s1, vector<string>& s2) {
        for (int i = 1; i < s1.size(); i++) {
            for (int j = 1; j < s2.size(); j++) {
                if (s1[i] == s2[j])
                    return true;
            }
        }
        return false;
    }

    int findpar(int u, vector<int>& par) {
        if (u == par[u])
            return u;

        return par[u] = findpar(par[u], par);
    }

    void solve(int u, int v, vector<int>& par, vector<int>& rank) {
        int pu = findpar(u, par);
        int pv = findpar(v, par);

        if (pu == pv)
            return;

        if (rank[pu] >= rank[pv]) {
            par[pv] = pu;
            if (rank[pu] == rank[pv])
                rank[pu]++;
        } else {
            par[pu] = pv;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& acc) {
        int n = acc.size();
        vector<vector<string>> res;

        vector<int> par(n);
        vector<int> rank(n, 0);

        for (int i = 0; i < n; i++)
            par[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (check(acc[i], acc[j])) {
                    solve(i, j, par, rank);
                }
            }
        }

        unordered_map<int, set<string>> mp;

        for (int i = 0; i < n; i++) {
            int p = findpar(i, par);

            for (int j = 1; j < acc[i].size(); j++) {
                mp[p].insert(acc[i][j]);
            }
        }

        for (auto& it : mp) {
            int p = it.first;

            vector<string> ans;
            ans.push_back(acc[p][0]);

            for (auto& mail : it.second)
                ans.push_back(mail);

            res.push_back(ans);
        }

        return res;
    }
};