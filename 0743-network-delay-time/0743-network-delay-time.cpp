class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &it : times){
            adj[it[0]-1].push_back({it[1]-1, it[2]});
        }

        vector<int> delay(n, INT_MAX);

        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        delay[k-1] = 0;
        pq.push({0, k-1});

        while(!pq.empty()){

            auto [dist, node] = pq.top();
            pq.pop();

            if(dist > delay[node]) continue;

            for(auto &[next, wt] : adj[node]){

                if(delay[next] > dist + wt){
                    delay[next] = dist + wt;
                    pq.push({delay[next], next});
                }
            }
        }

        int ans = 0;

        for(int d : delay){
            if(d == INT_MAX) return -1;
            ans = max(ans, d);
        }

        return ans;
    }
};