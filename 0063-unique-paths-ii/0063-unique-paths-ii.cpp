class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,int n,int m,vector<vector<int>>& arr){
        if(i==n || j==m) return 0;
        if(arr[i][j]==1) return 0;

        if(i==n-1 && j==m-1) return 1;

        if(dp[i][j]!=-1) return dp[i][j];

        dp[i][j]=solve(i+1,j,n,m,arr)+solve(i,j+1,n,m,arr);
        return dp[i][j];
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n=arr.size(),m=arr[0].size();
        dp.resize(n,vector<int>(m,-1));
        return solve(0,0,n,m,arr);
    }
};