class Solution {
public:
    vector<vector<int>>dp;
    int solve(int i,vector<int>&arr,bool f){
        if(i==arr.size()) return 0;
        if(dp[i][f]!=-1) return dp[i][f];
        int t;
        if(f==0){
            t= -arr[i]+solve(i+1,arr,1);
        }
        else{
            t=arr[i]+solve(i+1,arr,0);
        }
        int n=solve(i+1,arr,f);
        return dp[i][f]= max(n,t);

    }
    
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        dp.assign(n + 1, vector<int>(2, -1));
        return solve(0,arr,0);
    }
};