class Solution {
public:
    vector<vector<int>>dp;
    int solve(string &s, int i, int j){
        if(i>j) return 0;
        if(i==j) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        int res=0;

        if(s[i]==s[j]) res=2+solve(s,i+1,j-1);
        else res=solve(s,i+1,j-1);

        int x=solve(s,i+1,j);
        int y=solve(s,i,j-1);
        res=max({x,y,res});

        return dp[i][j]=res;
    }

    int longestPalindromeSubseq(string s) {
        int n=s.size();
        dp.resize(n+1,vector<int>(n+1,-1));
       return solve(s,0,n-1);
    }
};