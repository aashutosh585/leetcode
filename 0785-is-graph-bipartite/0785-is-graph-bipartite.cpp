class Solution {
public:
    bool dfs(int node, int color, vector<vector<int>>& graph, vector<int>& visit) {
        if (visit[node] != -1) {
            return visit[node] == color;
        }
        
        visit[node] = color;
        
        for(auto &n : graph[node]) {
            if(!dfs(n, 1 - color, graph, visit)) {
                return false;
            }
        }
        
        return true;
    }

    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visit(n, -1);
        
        for(int i = 0; i < n; i++) {
            if (visit[i] == -1){
                if(!dfs(i, 0, graph, visit)){
                    return false;
                }
            }
        }
        
        return true;
    }
};
