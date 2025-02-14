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
    void store(TreeNode* root,int level,vector<vector<int>> &arr){
        if(root==NULL){
            return;
        }
        if(level==arr.size()){
            arr.push_back({});
        }
        arr[level].push_back(root->val);
        store(root->left,level+1,arr);
        store(root->right,level+1,arr);


    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> arr;
        if(root==NULL)  return arr;
        int level=0;
        store(root,level,arr);
        return arr;


    }
};