class Solution {
public:
    int n, m;

    void dfs(int i, int j, vector<vector<char>>& arr, vector<vector<int>>& visit) {
        if(i<0 || i>=n || j<0 || j>=m || arr[i][j] == 'X' || visit[i][j] == 1) return;

        visit[i][j] = 1;
        dfs(i-1, j, arr, visit);
        dfs(i+1, j, arr, visit);
        dfs(i, j-1, arr, visit);
        dfs(i, j+1, arr, visit);
    }

    void solve(vector<vector<char>>& arr) {
        n = arr.size();
        m = arr[0].size();
        vector<vector<int>> visit(n, vector<int>(m, 0));

        for(int i=0; i<n; i++){
            if(arr[i][0] == 'O') dfs(i, 0, arr, visit);
            if(arr[i][m-1] == 'O') dfs(i, m-1, arr, visit);
        }
        for(int j=0; j<m; j++){
            if(arr[0][j] == 'O') dfs(0, j, arr, visit);
            if(arr[n-1][j] == 'O') dfs(n-1, j, arr, visit);
        }

        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(arr[i][j] == 'O' && visit[i][j] == 0){
                    arr[i][j] = 'X';
                }
            }
        }
    }
};
