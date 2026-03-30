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
vector<int> rightSideView(TreeNode* root) {
    vector<int> res;
    if (!root) return res; // Fix Runtime Error: Handle null root

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size(); // Track how many nodes are in the current level
        
        for (int i = 0; i < n; i++) {
            TreeNode* node = q.front();
            q.pop();

            // If it's the last node in the current level, add to result
            if (i == n - 1) {
                res.push_back(node->val);
            }

            // Add children for the next level
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    return res;
}
};
