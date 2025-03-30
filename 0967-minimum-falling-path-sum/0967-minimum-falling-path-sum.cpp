class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int l,vector<vector<int>>&matrix){
        if(l==matrix.size()) return 0;
        
        int m=matrix[l].size();
        
        int ans=INT_MAX;

        if(dp[l][i]!=INT_MIN) return dp[l][i];
        
        if(i-1>=0 && i-1<m)
        ans=min(ans,matrix[l][i]+solve(i-1,l+1,matrix));
        if(i>=0 && i<m)
        ans=min(ans,matrix[l][i]+solve(i,l+1,matrix));
        if(i+1>=0 && i+1<m)
        ans=min(ans,matrix[l][i]+solve(i+1,l+1,matrix));

        return dp[l][i]=ans;

    }

    int minFallingPathSum(vector<vector<int>>& matrix) {

        int ans=INT_MAX,m=matrix[0].size();
        dp.resize(matrix.size(),vector<int>(m,INT_MIN));

        for(int i=0;i<m;i++){
            int x=solve(i,0,matrix);
            ans=min(ans,x);
        }

        return ans;
        
    }
};