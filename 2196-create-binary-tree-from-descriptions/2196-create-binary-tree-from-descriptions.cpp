class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& arr) {
        unordered_map<int, TreeNode*> mpp;
        unordered_set<int> child;

        for (auto &it : arr) {
            int x = it[0];
            int y = it[1];
            int b = it[2];

            if (mpp.find(x) == mpp.end())
                mpp[x] = new TreeNode(x);

            if (mpp.find(y) == mpp.end())
                mpp[y] = new TreeNode(y);

            if (b == 1)
                mpp[x]->left = mpp[y];
            else
                mpp[x]->right = mpp[y];

            child.insert(y);
        }

        for (auto &p : mpp) {
            if (child.find(p.first) == child.end())
                return p.second;
        }

        return nullptr;
    }
};