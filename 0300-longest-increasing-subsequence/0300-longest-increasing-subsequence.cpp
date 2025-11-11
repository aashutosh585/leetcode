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
        if(n==1) return 1;
        dp.resize(n+1,vector<int>(n+1,0));
        // return solve(0,arr,-1);
        for(int i=n-1;i>=0;i--){
            for(int pi=i-1;pi>=-1;pi--){
                int l=0,r;
                if(pi==-1 || arr[pi]<arr[i]) l=1+dp[i+1][i+1];
                r=dp[i+1][pi+1];
                dp[i][pi+1]=max(r,l);
            }
        }
        return dp[0][0];
    }
};