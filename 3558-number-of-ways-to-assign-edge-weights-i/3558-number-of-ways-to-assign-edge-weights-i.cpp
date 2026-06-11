
class Solution {
public:
    int mod = 1e9 + 7;

    int pow(int n) {
        if(n < 0) return 0; 
        long long ans = 1;
        long long base = 2;

        while(n > 0) {
            if(n & 1) ans = (ans * base) % mod;
            base = (base * base) % mod;
            n >>= 1;
        }

        return ans;
    }

    int dfs(int u, vector<vector<int>>& adj, vector<int>& dp) {
        if (dp[u] != -1) return dp[u];

        int mx = 0;
        for(auto &v : adj[u]) {
            mx = max(mx, dfs(v, adj, dp));
        }

        return dp[u] = mx + 1;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {

        int n = edges.size() + 1;
        vector<vector<int>> adj(n);
        vector<int> dp(n, -1); 

        for(auto &e : edges) {
            adj[e[0] - 1].push_back(e[1] - 1);
        }

        int d = 0;
        for(int i = 0; i < n; i++) {
            d = max(d, dfs(i, adj, dp));
        }

        return pow(d - 2);
    }
};