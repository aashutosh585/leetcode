class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> time(n, vector<int>(m, -1));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                    time[i][j] = 0; 
                }
            }
        }

        vector<int> d = {0,1,0,-1,0};
        int ans = 0;

   
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int x = i + d[k];
                int y = j + d[k+1];

                if(x>=0 && x<n && y>=0 && y<m && grid[x][y] == 1){
                    grid[x][y] = 2; 
                    time[x][y] = time[i][j] + 1;
                    ans = max(ans, time[x][y]);
                    q.push({x,y});
                }
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};
