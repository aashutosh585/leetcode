/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void check(TreeNode *root,TreeNode *p,bool &flag){
        if(root==NULL){
            return;
        }
        if(root==p){
            flag=true;
            return;
        }
        check(root->left,p,flag);
        check(root->right,p,flag);
    }

    void store(TreeNode* root,vector<TreeNode*>&l,TreeNode* p){
        if(root==NULL){
            return;
        }
        l.push_back(root);
        if(root==p) return;

        store(root->left,l,p);
        store(root->right,l,p);
        if(!l.empty() && l.back()==p) return;

        l.pop_back();
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool flag=false;
        check(p,q,flag);
        if(flag) return p;

        flag=false;
        check(q,p,flag);
        if(flag) return q;

        vector<TreeNode*>l;
        vector<TreeNode*>r;
        store(root,l,p);
        store(root,r,q);
        TreeNode* ans;
        int i=0,j=0,n=l.size(),m=r.size();
        for(;i<n && j<m;i++,j++){
            if(l[i]==r[j]){
                ans=l[i];
            }
            else
            break;
        }
        return ans;
    }
};