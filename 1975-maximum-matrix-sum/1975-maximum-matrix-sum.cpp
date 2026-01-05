class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum=0;
        int mn=INT_MAX,cnt=0;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                sum+=abs(matrix[i][j]);
                mn= min(mn, abs(matrix[i][j]) );
                if(matrix[i][j]<0) cnt++;
            }
        }
        if(cnt%2!=0){
            sum=sum-2*mn;
        }
        return sum;
    }
};