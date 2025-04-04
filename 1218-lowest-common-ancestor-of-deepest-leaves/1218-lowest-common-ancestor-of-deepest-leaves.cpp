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
    int LSD(TreeNode *root){
        if(root==NULL) return 0;

        return 1+max(LSD(root->left),LSD(root->right));
    }

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL || root->left==NULL && root->right==NULL)
        return root;
        
        int x=LSD(root->left); //height of left subtree
        int y=LSD(root->right); //height of right subtree

        if(x==y){
            return root;
        }
        else if(x>y){
            return lcaDeepestLeaves(root->left);
        }
        else{
            return lcaDeepestLeaves(root->right);
        }
        
    }
};