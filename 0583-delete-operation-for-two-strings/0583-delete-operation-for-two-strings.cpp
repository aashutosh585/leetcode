class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i, int j,string &w1, string &w2){
        if(i==w1.size() || j==w2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        if(w1[i]==w2[j]){
            return dp[i][j]= 1+ solve(i+1,j+1,w1,w2);
        }
        else{
            return dp[i][j]= max(solve(i,j+1,w1,w2),solve(i+1,j,w1,w2));
        }

    }
    int minDistance(string w1, string w2){
        int n=w1.size(), m=w2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        int x=solve(0,0,w1,w2);
        return n+m - 2*x;
    }
};