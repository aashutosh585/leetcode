class Solution {
public:
    int cnt=0;
    int solve(vector<vector<int>>&adj, vector<int>&values, int k, int curr,int parent=-1){
        long long sum=values[curr];
        for(int it:adj[curr]){
            if(it!=parent) sum += solve(adj,values,k,it,curr);
        }
        sum %=k;
        if(sum==0) cnt++;

        return sum;
    }

    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>>adj(n);
        for(auto it:edges){
            int a=it[0],b=it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        solve(adj,values,k,0);
        return cnt;

       


        
    }
};