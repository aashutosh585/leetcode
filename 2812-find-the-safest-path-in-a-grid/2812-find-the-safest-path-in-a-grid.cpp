class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
    
        vector<int>dx={1,0, -1, 0}, dy={0, 1, 0, -1};

        // first filling the dist grid -> BFS
        queue<pair<int, int>>q;

        // initalizing
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                if(grid[i][j]==1) 
                    q.push({i,j});

        // fill dist 
        while(!q.empty()){
            auto [idx, jdx]=q.front();
            q.pop();

            int v=grid[idx][jdx];

            for(int i=0;i<4;i++){
                int x= idx+dx[i];
                int y= jdx+ dy[i];

                if(min(x,y)>=0 && max(x,y)<n && grid[x][y]==0){
                    grid[x][y]=v+1;
                    q.push({x,y});
                }
            }
        }

        // calculate path with maximum distance from thief
        // min_di, idx, jdx
        
        priority_queue<tuple<int, int, int>> pq;
        pq.push({grid[0][0], 0, 0});

        while(!pq.empty()){
            auto [sf, i, j]= pq.top();
            pq.pop();

            if(i==n-1 && j==n-1) return sf-1;

            for(int k=0;k<4;k++){
                int x= i+ dx[k];
                int y= j+ dy[k];

                if(min(x,y)>=0 && max(x,y)<n && grid[x][y]>0){
                    pq.push({min(sf, grid[x][y]), x, y});
                    grid[x][y]*=-1;
                }
            }
        }

        return grid[n-1][n-1];

    }
};