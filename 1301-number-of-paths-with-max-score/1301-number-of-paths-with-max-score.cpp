class Solution {
public:
    const int MOD = 1e9 + 7;
    
    vector<int> pathsWithMaxScore(vector<string>& grid) {
        int n=grid.size(), m= grid[0].size();

        vector<vector<int>>dp(n+1, vector<int>(m+1, -1)), arr(n+1, vector<int>(m+1, 0));

        dp[n-1][m-1]=0;
        arr[n-1][m-1]=1;
        vector<pair<int, int>> d= {{1,1}, {1,0}, {0,1}};

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){

                if(grid[i][j] == 'X') continue;
                if(grid[i][j] == 'S') continue;

                int best=-1;
                long long cnt=0;
                for(auto [x,y]:d){
                    int ni= i+x;
                    int nj= j+y;

                    int va= dp[ni][nj];

                    if(va!=-1){
                        if(best==va) cnt= (cnt + arr[ni][nj])%MOD;
                        else if(best<va){
                            best=va;
                            cnt=arr[ni][nj];
                        }
                        
                    }
                }
                
                if(best == -1) continue;

                int val = (grid[i][j] == 'E') ? 0 : grid[i][j] - '0';

                arr[i][j]=cnt;
                dp[i][j] = val + best;
            }
        }

        if(dp[0][0] == -1) return {0, 0};
        return {dp[0][0],arr[0][0]};
    }
};