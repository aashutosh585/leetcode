class Solution {
public:
    vector<vector<vector<int>>>dp;
    int solve(int i,vector<int>&arr,bool f,int use){
        if(i==arr.size()) return 0;
        if(use==0) return 0;
        if(dp[i][f][use]!=-1) return dp[i][f][use];

        int t;
        if(f==0){
            t= -arr[i]+solve(i+1,arr,1,use);
        }
        else{
            t=arr[i]+solve(i+1,arr,0,use-1);
        }
        int n=solve(i+1,arr,f,use);
        return dp[i][f][use]= max(n,t);

    }

    int maxProfit(int k,vector<int>& arr) {
        int n=arr.size();
        dp.assign(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, arr,0,k);
    }
};
