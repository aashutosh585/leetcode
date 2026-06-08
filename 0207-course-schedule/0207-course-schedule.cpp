class Solution {
public:
    bool dfs(int i, vector<vector<int>> &adj, vector<bool> &vis, vector<bool> cvis){
        if(i==adj.size()) return false;

        vis[i]=true;
        cvis[i]= true;

        for(auto &it:adj[i]){
            if(cvis[it]) return true;

            if(!vis[it]) if( dfs(it, adj, vis, cvis)) return true;
        }

        cvis[i]=false;
        return false;

    }

    bool canFinish(int n, vector<vector<int>>& arr) {

        vector<vector<int>>adj(n);
        for(auto &it:arr) adj[it[1]].push_back(it[0]);

        vector<bool>vis(n, false), cvis(n, false);

        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, cvis)) return false; 
            }
        }

        return true;
        
    }
};