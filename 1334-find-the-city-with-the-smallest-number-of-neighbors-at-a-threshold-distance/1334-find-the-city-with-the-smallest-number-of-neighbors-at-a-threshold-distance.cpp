class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int d) {
        vector<vector<int>>dist(n,vector<int>(n,INT_MAX));

        for(int i = 0; i < n; i++)
            dist[i][i] = 0;

        for(auto &it:edges){
            dist[it[0]][it[1]]=it[2];
            dist[it[1]][it[0]]=it[2];
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    int x=dist[i][k], y=dist[k][j];
                    if(x!=INT_MAX && y!=INT_MAX)
                    dist[i][j]=min(dist[i][j], x+y);
                }
            }
        }

        int res = -1;
        int minCount = INT_MAX;

        for(int k = 0; k < n; k++) {
            int cnt = 0;
            for(int i = 0; i < n; i++) {
                if(i != k && dist[k][i] <= d)
                    cnt++;
            }
            if(cnt <= minCount) {
                minCount = cnt;
                res = k;   
            }
        }

        return res;
    }
};