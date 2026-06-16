class Solution {
public:
    int removeStones(vector<vector<int>>& sto) {
        int n = sto.size();
        vector<int> par(n), rank(n, 0);

        for (int i = 0; i < n; i++)
            par[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sto[i][0] == sto[j][0] || sto[i][1] == sto[j][1]) {
                    int u = i, v = j;
                    if (par[u] != par[v]) {
                        if (rank[par[u]] >= rank[par[v]]) {
                            int old = par[v];
                            int nw = par[u];

                            for (int i = 0; i < n; i++) {
                                if (par[i] == old)
                                    par[i] = nw;
                            }

                            rank[nw]++;
                        } else {
                            int old = par[u];
                            int nw = par[v];

                            for (int i = 0; i < n; i++) {
                                if (par[i] == old)
                                    par[i] = nw;
                            }

                            rank[nw]++;
                        }
                    }
                }
            }
        }

        set<int> st;
        for (auto& it : par) {
            st.insert(it);
        }

        return n - st.size();
    }
};