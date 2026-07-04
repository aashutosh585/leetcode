class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);

        for(auto &it : roads) {
            int u = it[0] - 1;
            int v = it[1] - 1;
            int w = it[2];

            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int ans = INT_MAX;

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            for(auto [j, cost]:adj[i]){
                ans = min(ans, cost);
                if(!vis[j]) {
                    vis[j] = true;
                    q.push(j);
                }
            }
        }

        return ans;
    }
};