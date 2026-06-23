class Solution {
public:
    vector<long long> dp;

    long long fact(int n) {
        if (n == 0 || n == 1){
            dp[n]=1;
            return 1;
        }
        if (dp[n] != -1) return dp[n];

        return dp[n] = 1LL * n * fact(n - 1);
    }

    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;

        // dp.resize(n + 1, -1);
        // fact(n);

        for(int i = 0; i < n; i++) {
            vector<int> arr(i+1, 1);

            for(int j = 1; j < i; j++) {
                arr[j]= res[i-1][j-1] + res[i-1][j];
                
            }
            res.push_back(arr);
        }

        return res;
    }
};