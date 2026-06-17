class Solution {
public:
    vector<int> par, sz;

    int findPar(int x) {
        if (par[x] == x) return x;
        return par[x] = findPar(par[x]);
    }

    void unite(int u, int v) {
        int pu = findPar(u);
        int pv = findPar(v);

        if (pu == pv) return;

        if (sz[pu] < sz[pv])
            swap(pu, pv);

        par[pv] = pu;
        sz[pu] += sz[pv];
    }

    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();

        par.resize(n * n);
        sz.resize(n * n, 1);

        for (int i = 0; i < n * n; i++)
            par[i] = i;

        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};

        // Build DSU for all 1's
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                int u = i * n + j;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 &&
                        ni < n && nj < n &&
                        grid[ni][nj] == 1) {

                        int v = ni * n + nj;
                        unite(u, v);
                    }
                }
            }
        }

        int ans = 0;

        // Existing island sizes
        for (int i = 0; i < n * n; i++) {
            if (par[i] == i)
                ans = max(ans, sz[i]);
        }

        // Try converting each 0 to 1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1) continue;

                unordered_set<int> comps;
                int cur = 1;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni >= 0 && nj >= 0 &&
                        ni < n && nj < n &&
                        grid[ni][nj] == 1) {

                        int p = findPar(ni * n + nj);

                        if (comps.insert(p).second)
                            cur += sz[p];
                    }
                }

                ans = max(ans, cur);
            }
        }

        return ans;
    }
};