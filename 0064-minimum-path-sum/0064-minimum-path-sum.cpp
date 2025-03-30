class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,int n,int m,vector<vector<int>>&grid){
        if(i==n || j==m) return INT_MAX;
        if(i==n-1 && j==m-1) return dp[i][j]=grid[i][j];
        if(dp[i][j]!=-1) return dp[i][j];

        int x=solve(i+1,j,n,m,grid);
        int y=solve(i,j+1,n,m,grid);

        return dp[i][j]=grid[i][j]+min(x,y);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,n,m,grid);
    }
};