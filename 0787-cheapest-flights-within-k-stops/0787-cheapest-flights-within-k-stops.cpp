class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& arr, int src, int dst, int k) {
        vector<vector<pair<int, int>>>adj(n);
        for(auto &it: arr){
            int u=it[0], v=it[1], c=it[2];
            adj[u].push_back({v,c}); 
        }

        vector<vector<int>>dist(n, vector<int>(k+2, INT_MAX));
     
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>> >q;
      

        // cost , { index, k }
        q.push({0, {src, k+1}});
        dist[src][k]=0;
        int res=0;

        while(!q.empty()){
            int c1=q.top().first;
            auto [i, kk] = q.top().second;
            q.pop();

            if(i==dst && kk>=0) return c1;

            kk=kk-1;
            for(auto &it: adj[i]){
                int v=it.first, c2=it.second;
                if(kk>=0){
                    if(dist[v][k] > c2+ c1){
                        int c= c1+c2;
                        dist[v][kk]=c2+c1;
                        q.push({c,{v,kk}});
                    }
                }
            }
        }

        return -1;
        
    }
};