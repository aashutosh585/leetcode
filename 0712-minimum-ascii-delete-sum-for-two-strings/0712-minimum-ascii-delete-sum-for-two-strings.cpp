class Solution {
public:
vector<vector<int>>dp;
    
    int solve(int i, int j, string &s1, string &s2){
        if(i==s1.size() && j==s2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(i==s1.size()){
            int x=0;
            for(int k=j;k<s2.size();k++) x+=s2[k];
            return dp[i][j]= x;
        }
        if(j==s2.size()){
            int x=0;
            for(int k=i;k<s1.size();k++) x+=s1[k];
            return dp[i][j]=x;
        }


        if(s1[i]==s2[j]) return dp[i][j]= solve(i+1,j+1,s1,s2);
        else{
            return dp[i][j]= min(s1[i]+solve(i+1,j,s1,s2),s2[j]+solve(i,j+1,s1,s2));
        }
    }
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.size(),m=s2.size();
        dp.resize(n+1,vector<int>(m+1,-1));
        return solve(0,0,s1,s2);
    }
};