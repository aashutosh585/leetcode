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
   
    pair<int,TreeNode*> solve(TreeNode* node){
        if(node==NULL) return {0, NULL};

        auto l=solve(node->left), r=solve(node->right);

        if(l.first==r.first) return {l.first +1, node}; 
        else if(l.first > r.first) return {l.first + 1, l.second}; 
        else return {r.first + 1, r.second}; 
        
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};