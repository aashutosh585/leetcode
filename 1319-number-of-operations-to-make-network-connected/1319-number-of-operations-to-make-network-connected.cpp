class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& con) {
        vector<int> par(n), rank(n, 0);

        for(int i = 0; i < n; i++)
            par[i] = i;

        int ex = 0;

        for(auto &e : con) {
            int u = e[0], v = e[1];

            if(par[u] != par[v]) {
                if(rank[par[u]] >= rank[par[v]]) {
                    int old = par[v];
                    int nw = par[u];

                    for(int i = 0; i < n; i++) {
                        if(par[i] == old)
                            par[i] = nw;
                    }

                    rank[nw]++;
                }
                else {
                    int old = par[u];
                    int nw = par[v];

                    for(int i = 0; i < n; i++) {
                        if(par[i] == old)
                            par[i] = nw;
                    }

                    rank[nw]++;
                }
            }
            else {
                ex++;
            }
        }

        set<int> st;
        for(int x : par)
            st.insert(x);

        int res = st.size();

        return ex >= res - 1 ? res - 1 : -1;
    }
};