/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
int ans=0;
    void store(TreeNode* root,int level,unsigned long long x, vector<vector<unsigned long long>>&lev){
        if(root==NULL) return;

        if(lev.size()==level){
            lev.push_back({});
        }
        lev[level].push_back(x);
        // cout<<x<<" "<<"*";
        store(root->left,level+1,x*2,lev);
        store(root->right,level+1,x*2+1,lev);
    }

    int widthOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        } 
        vector<vector<unsigned long long>>lev;
        store(root,0,1,lev);
        unsigned long long ans=0;
        for(int i=0;i<lev.size();i++){
           unsigned long long a = lev[i].front();
           unsigned long long b = lev[i].back();
            ans=max(ans,b-a+1);
        }
        return (int)ans;
        


        
  

    }
};