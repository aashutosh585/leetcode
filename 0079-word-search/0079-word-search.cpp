class Solution {
public:
  
    bool solve(int idx,int i,int j,vector<vector<char>>& board, string &word){

        if(idx==word.size()) return true;

        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || board[i][j] != word[idx])
            return false;
        
        char s=board[i][j];
        board[i][j]='@';


        if(solve(idx+1,i+1,j,board,word) || solve(idx+1,i-1,j,board,word) || solve(idx+1,i,j+1,board,word) || solve(idx+1,i,j-1,board,word)) return true;


        board[i][j]=s;

        return  false;

    }
    bool exist(vector<vector<char>>& board, string word) {
        
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(solve(0,i,j,board,word)) return true;
                }
            }
        }

        return false;
    }
};