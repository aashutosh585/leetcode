class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&arr){
        if(i+1==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int res=INT_MAX;
        
        for(int k=i+1;k<j;k++){
            int val = arr[j]-arr[i] + solve(i,k,arr) + solve(k,j,arr);
            res=min(res,val);
        }
        return dp[i][j]=res;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        int m=cuts.size();
        dp.resize(m,vector<int>(m,-1));
        return solve(0,m-1,cuts);
    }
};