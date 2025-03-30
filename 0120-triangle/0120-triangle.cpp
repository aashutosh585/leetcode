class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int l,vector<vector<int>>&arr){
        int n=arr.size();
        if(l>=n) return 0;
        if(i>=arr[l].size()) return INT_MAX;



        // int x=arr[l][i]+min(solve(i,l+1,arr),solve(i+1,l+1,arr));

        if(dp[l][i]!=-1) return dp[l][i];
        int way1 = arr[l][i] + solve(i,l+1,arr);
        int way2 = arr[l][i] + solve(i+1,l+1,arr);

        return dp[l][i] = min(way1,way2);

    }
    int minimumTotal(vector<vector<int>>& arr) {
        int n=arr.size();
        int last = arr[n-1].size();
        dp.resize(n,vector<int>(last,-1));
        return solve(0,0,arr);
    }
};