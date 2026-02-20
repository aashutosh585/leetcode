class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        queue<pair<int,int>> q;

       
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == 0){
                    q.emplace(i, j);
                } else {
                    mat[i][j] = -1; 
                }
            }
        }

        vector<int> dx = {1,0,-1,0};
        vector<int> dy = {0,1,0,-1};

    
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();

            for(int k=0; k<4; k++){
                int x = i + dx[k];
                int y = j + dy[k];

                if(x>=0 && x<n && y>=0 && y<m && mat[x][y] == -1){
                    mat[x][y] = mat[i][j] + 1;
                    q.emplace(x, y);
                }
            }
        }

        return mat;
    }
};
