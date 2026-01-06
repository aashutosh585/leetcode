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
    int maxLevelSum(TreeNode* root) {

        queue<TreeNode*>q;
        int res=root->val,id=1,l=1;

        q.push(root);
        while(!q.empty()){
            int cnt=q.size();
            int sum=0;
            for(int i=0;i<cnt;i++){
                TreeNode* temp= q.front();
                q.pop();

                sum+=temp->val;
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);

            }

            if(sum>res){
                res=sum;
                id=l;
            }
            l++;
            
        }

        return id ;

    }
};