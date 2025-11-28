class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,int j,vector<int>&arr){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int res=0;
        for(int k=i;k<=j;k++){
            int val= arr[i-1] * arr[k] * arr[j+1] + solve(i,k-1,arr) + solve(k+1,j,arr);
            res=max(res,val);
        }
        return dp[i][j]=res;
    }

    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        dp.resize(n+2,vector<int>(n+2,-1));
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        return solve(1,n,nums);
    }
};