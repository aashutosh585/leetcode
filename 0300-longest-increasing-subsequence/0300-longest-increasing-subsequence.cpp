class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,vector<int>&arr,int pi){
        if(i==arr.size()) return 0;
        if(dp[i][pi+1]!=-1) return dp[i][pi+1];

        int l=0,r;
        if(pi==-1 || arr[pi]<arr[i]) l=1+ solve(i+1,arr,i);
        r=solve(i+1,arr,pi);
        return dp[i][pi+1]=max(l,r);

    }
    int lengthOfLIS(vector<int>& arr) {
        int n=arr.size();
        dp.resize(n,vector<int>(n+1,-1));
        return solve(0,arr,-1);
    }
};