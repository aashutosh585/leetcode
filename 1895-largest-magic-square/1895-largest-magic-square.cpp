class Solution {
public:
    int largestMagicSquare(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 1;

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                
                for(int k=2; i+k<=n && j+k<=m; k++){
                    int target = 0;
                  
                    for(int d=0; d<k; d++) target += grid[i+d][j+d];

                    
                    int diag2 = 0;
                    for(int d=0; d<k; d++) diag2 += grid[i+d][j+k-1-d];
                    if(diag2 != target) continue;

                    bool ok = true;
                   
                    for(int r=0; r<k && ok; r++){
                        int sumRow = 0;
                        for(int c=0; c<k; c++) sumRow += grid[i+r][j+c];
                        if(sumRow != target) ok = false;
                    }
                  
                    for(int c=0; c<k && ok; c++){
                        int sumCol = 0;
                        for(int r=0; r<k; r++) sumCol += grid[i+r][j+c];
                        if(sumCol != target) ok = false;
                    }

                    if(ok) ans = max(ans, k);
                }
            }
        }
        return ans;
    }
};
