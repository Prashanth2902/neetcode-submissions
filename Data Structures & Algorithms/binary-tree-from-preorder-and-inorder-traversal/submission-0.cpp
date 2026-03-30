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

    TreeNode* dfs(vector<int>& preorder, vector<int>& inorder, int& preIdx, 
    unordered_map<int,int>& m, int l, int r) {
        if(l > r) return nullptr;
        int rootVal = preorder[preIdx++];
        TreeNode* root = new TreeNode(rootVal);
        int mid = m[rootVal];
        root->left = dfs(preorder, inorder, preIdx, m, l, mid-1);
        root->right = dfs(preorder, inorder, preIdx, m, mid+1, r);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i = 0; i<inorder.size();i++) {
            m[inorder[i]] = i;
        }
        int preIdx = 0;
        return dfs(preorder, inorder, preIdx, m, 0, inorder.size() - 1);
    }
};
