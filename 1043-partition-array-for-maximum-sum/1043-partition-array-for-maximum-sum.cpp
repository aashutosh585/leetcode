class Solution {
public:
    vector<int>dp;
    int solve(int i, int k,vector<int>&arr){
        if(i==arr.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int m=0,res=0;
        for(int j=0;j<k && j+i< arr.size();j++){
            m=max(m,arr[i+j]);
            int val= m * (j+1) + solve(i+j+1,k,arr);
            res=max(res,val);
        }

        return dp[i]=res;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        dp.resize(n+1,-1);
        return solve(0,k,arr);
    }
};