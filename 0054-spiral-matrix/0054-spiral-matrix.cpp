class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) {
        int n=mat.size(), m=mat[0].size();
        int tl=0, tr=m-1, br=n-1, bl=0;

        vector<int>ans;

        while(tl<=br && bl<=tr){
            for(int i=bl;i<=tr;i++){
                ans.push_back(mat[tl][i]);
            }
            tl++;

            for(int i=tl;i<=br;i++){
                ans.push_back(mat[i][tr]);
            }
            tr--;

            if(tl <= br) {
                for(int i = tr; i >= bl; i--)
                    ans.push_back(mat[br][i]);
                br--;
            }

            if(bl <= tr) {
                for(int i = br; i >= tl; i--)
                    ans.push_back(mat[i][bl]);
                bl++;
            }
        }
        return ans;
    }
};