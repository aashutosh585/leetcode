class Solution {
public:

    void dfs(int i, unordered_map<int,vector<int>> &adj, vector<bool>&visit){
        if(visit[i]) return;

        visit[i]=true;

        for(auto it:adj[i]){
            dfs(it,adj,visit);
        }
    }

    int findCircleNum(vector<vector<int>>& isCo) {
        int n=isCo.size();
        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++) 
            for(int j=0;j<n;j++) 
                if(isCo[i][j]==1 && i!=j) adj[i].push_back(j);

        vector<bool>visit(n,false);
        int cnt=0;

        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i,adj,visit);
                cnt++;
            }
        }

        return cnt;
        
    }
};