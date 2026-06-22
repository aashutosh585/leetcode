class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<int>r,c;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }

        for(auto &x: r){
            for(int i=0;i<m;i++){
                matrix[x][i]=0;
            }
        }

        for(auto &x: c){
            for(int i=0;i<n;i++){
                matrix[i][x]=0;
            }
        }

        return;
    }
};