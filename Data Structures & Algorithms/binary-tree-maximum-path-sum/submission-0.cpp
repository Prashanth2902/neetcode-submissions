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

    int getMax(TreeNode* root) {
        if(!root) return 0;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = root->val + max(left, right);
        return max(0, path);
    }

    void dfs(TreeNode* root, int& res) {
        if(!root) return;
        int left = getMax(root->left);
        int right = getMax(root->right);
        int path = root->val + left + right;
        res = max(res, path);
        dfs(root->left, res);
        dfs(root->right, res);
    }

    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        dfs(root, res);
        return res;
    }
};
