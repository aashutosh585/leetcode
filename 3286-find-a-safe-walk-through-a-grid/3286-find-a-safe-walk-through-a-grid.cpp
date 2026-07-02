class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int h) {
        int n=grid.size(), m=grid[0].size();

        vector<int>dx={1,0,-1,0}, dy={0, 1, 0, -1};
        vector<vector<int>>dist(n,  vector<int>(m, -1));
        priority_queue< tuple<int, int, int>>pq;

        int sh=h-grid[0][0];
        if(sh<=0) return false;

        dist[0][0]=sh;
        pq.push({sh, 0, 0});

        while(!pq.empty()){
            auto [ch, i, j]=pq.top();
            pq.pop();

            if(ch < dist[i][j]) continue;
            if(i==n-1 && j==m-1) return true;

            for(int k=0;k<4;k++){
                int ni= i+ dx[k];
                int nj= j+dy[k];

                if(ni>=0 && ni<n && nj>=0 && nj<m ){
                    int nh = ch - grid[ni][nj];
                    
                    if(nh > 0 && nh > dist[ni][nj]) {
                        dist[ni][nj] = nh;
                        pq.push({nh, ni, nj});
                    }
                }
            }
        }

        return false;

    }
};