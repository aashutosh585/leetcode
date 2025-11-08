class Solution {
public:
// #define int long long 
    int numDistinct(string s, string t) {
        // int n=s.size(),m=t.size();
        // vector<vector<unsigned long long>> dp(m + 1, vector<unsigned long long>(n + 1, 0));
        // for(int j = 0; j <= n; j++) {
        //     dp[0][j] = 1;  
        // }

        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         if(t[i - 1] == s[j - 1]) {
        //             dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1];
        //         } else {
        //             dp[i][j] = dp[i][j - 1];
        //         }
        //     }
        // }

        // // for(int i=0;i<=m;i++){
        // //     for(int j=0;j<=n;j++){
        // //         cou<<
        // //         cout<<dp[i][j]<<" ";
        // //     }
        // //     cout<<endl;
        // // }

        // return dp[m][n];

        int n=s.size(),m=t.size();
        vector<unsigned long long>dp(m+1);
        dp[0]=1;

        for(int i=1;i<=n;i++){
            for(int j=m;j>=1;j--){
                if(s[i-1]==t[j-1]){
                    dp[j]+=dp[j-1];
                }
            }
        }

        return dp[m];

    }
};