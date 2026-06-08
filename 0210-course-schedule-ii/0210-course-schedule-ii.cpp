class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& arr) {
        vector<vector<int>> adj(n);
        vector<int> deg(n);
       
        for(auto &it : arr){
            adj[it[1]].push_back(it[0]);
            deg[it[0]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++){
            if(deg[i] == 0) q.push(i);
        }

        vector<int> res;
        int cnt = 0;

     
        while(!q.empty()){
            int x = q.front();
            q.pop();

            cnt++;
            res.push_back(x);
            
            for(auto &it : adj[x]){
                deg[it]--;
                if(deg[it] == 0){
                    q.push(it);
                }
            }
        }

     
        return (cnt == n) ? res : vector<int>{};
    }
};