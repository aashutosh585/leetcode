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
    int mod=1e9+7;
    long long ans=0;
    long long sum=0;

    long long FSum(TreeNode* node){
        if(node==NULL) return 0;
        return node->val + FSum(node->left) + FSum(node->right);
    }

    long long solve(TreeNode* node){
        if(node==NULL) return 0;

        long long x=solve(node->left);
        long long y=solve(node->right);
        ans=max(ans,((sum-x)*x));
        ans=max(ans, ((sum-y)*y));
        
        return (x+y+node->val)%mod;
    }

    int maxProduct(TreeNode* root) {
        sum=FSum(root);
        solve(root);

        return ans%mod;
    }
};