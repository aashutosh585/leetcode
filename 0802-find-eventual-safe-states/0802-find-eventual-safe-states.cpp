class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis) {
        if (vis[node] == 1) return false; 
        if (vis[node] == 2) return true;  

        vis[node] = 1; 

        for (int nxt : adj[node]) {
            if (!dfs(nxt, adj, vis))
                return false;
        }

        vis[node] = 2;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> vis(n, 0);
        vector<int> ans;

        for(int i = 0; i < n; i++) {
            if(dfs(i, adj, vis))
                ans.push_back(i);
        }

        return ans;
    }
};