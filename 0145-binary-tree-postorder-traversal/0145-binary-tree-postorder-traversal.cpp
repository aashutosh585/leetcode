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
    // void postorder(TreeNode* root,vector<int>&arr){
    //     if(root==NULL){
    //         return;
    //     }
    //     postorder(root->left,arr);
    //     postorder(root->right,arr);
    //     arr.push_back(root->val);

    // }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>arr;
        if(root==NULL) return arr;
        // postorder(root,arr);
        // return arr;
        
        // using two stack
        stack<TreeNode* >s1,s2;
        s1.push(root);
        while(!s1.empty()){
            root =s1.top();
            s2.push(root);
            s1.pop();

            if(root->left!=NULL)
            s1.push(root->left);

            if(root->right!=NULL)
            s1.push(root->right);
        }
        while(!s2.empty()){
     
            arr.push_back(s2.top()->val);
            s2.pop();
        }
        return arr;


    }
};