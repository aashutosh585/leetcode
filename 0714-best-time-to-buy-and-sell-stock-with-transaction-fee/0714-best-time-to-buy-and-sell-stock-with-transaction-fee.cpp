class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, vector<int>& arr, bool f,int &fee){
        if(i >= arr.size()) return 0;
        if(dp[i][f] != -1) return dp[i][f];
        int t, n;
        if(f == 0){
            t = -arr[i]-fee + solve(i + 1, arr, 1,fee);
        } else{
            t = arr[i] + solve(i + 1, arr, 0,fee);
        }
        n = solve(i + 1, arr, f,fee);
        return dp[i][f] = max(t, n);
    }

    int maxProfit(vector<int>& arr,int fee){
        int n = arr.size();
        dp.resize(n + 1, vector<int>(2, -1));
        return solve(0, arr, 0,fee);
    }
};
