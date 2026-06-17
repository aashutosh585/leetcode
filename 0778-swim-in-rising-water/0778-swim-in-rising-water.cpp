class Solution {
public:
int n;
    vector<int> dx={1,0,-1,0},dy={0, 1, 0, -1};
    bool solve(int i, int j, vector<vector<int>> &grid, int t, vector<vector<bool>>& vis){
        if(i<0 || i>=n || j<0 || j>=n || vis[i][j] || grid[i][j]>t ) return false;

        if(i==n-1 && j==n-1) return true;

        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int di= dx[k]+i;
            int dj=dy[k]+j;

            if(solve(di, dj, grid, t, vis)) return true;
        }

        return false;
    }

    int swimInWater(vector<vector<int>>& grid) {
         n=grid.size();
        int l=0, h= n*n -1;
        int mid, res;
        while(l<=h){
            mid=(h-l)/2+l;
            vector<vector<bool>>vis(n, vector<bool>(n, false));
            if(solve(0,0,grid, mid, vis)){
                h=mid-1;
                res=mid;
            }
            else{
                l=mid+1;
            }
        }

        return res;
    }
};