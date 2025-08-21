
class Solution {
public:
    vector<vector<string>> ans;

    void fill(vector<vector<bool>>& allowed, int i, int j) {
        int n = allowed.size();

        //  mark col
        for (int r = 0; r < n; r++) allowed[r][j] = true;

        // diagonal ↙ and ↗
        for (int x=i, y=j; x>=0 && y>=0; x--, y--) allowed[x][y] = true;
        for (int x=i, y=j; x<n && y<n; x++, y++) allowed[x][y] = true;

        // diagonal ↘ and ↖
        for (int x=i, y=j; x>=0 && y<n; x--, y++) allowed[x][y] = true;
        for (int x=i, y=j; x<n && y>=0; x++, y--) allowed[x][y] = true;
    }

    void solve(int queen, int row, vector<vector<bool>> allowed, vector<string>& arr, string s) {
        int n = allowed.size();
        if (queen == 0) {
            ans.push_back(arr);
            return;
        }
        if (row >= n) return;

        for (int col = 0; col < n; col++) {
            if (!allowed[row][col]) {
                auto newAllowed = allowed;
                fill(newAllowed, row, col);

                string a = s;
                a[col] = 'Q';
                arr.push_back(a);

                solve(queen - 1, row + 1, newAllowed, arr, s);

                arr.pop_back(); 
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        string s(n, '.');

        for (int i = 0; i < n; i++) {
            vector<vector<bool>> allowed(n, vector<bool>(n, false));
            vector<string> arr;

            fill(allowed, 0, i);
            string a = s;
            a[i] = 'Q';
            arr.push_back(a);

            solve(n - 1, 1, allowed, arr, s);
        }

        return ans;
    }
};

