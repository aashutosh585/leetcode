class Solution {
public:
    vector<vector<int>>dp;
    bool solve(int i,int j,string &s,string &p){
        if(i==s.size() && j==p.size()) return true;
        if(j==p.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];

        if(p[j]=='*'){
           return dp[i][j]= solve(i, j + 1, s, p) || (i < s.size() && solve(i + 1, j, s, p));
        }
        if (i < s.size() && (p[j] == '?' || s[i] == p[j])) {
            return dp[i][j]= solve(i + 1, j + 1, s, p);
        }
        return dp[i][j]= false;
    }
    bool isMatch(string s, string p) {
        dp.resize(s.size()+1,vector<int>(p.size()+1,-1));
        return solve(0,0,s,p);
    }
};