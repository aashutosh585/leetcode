class Solution {
public:
vector<int>dp;
    int ways(int i,int n){
        if(i==n) return 1;
        if(i==n+1) return 0;

        if(dp[i]!=-1) return dp[i];
        return dp[i]=ways(i+1,n)+ways(i+2,n);
    }

    int climbStairs(int n) {
        dp.resize(n,-1);
        return ways(0,n);
    }
};