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
    void Dfs(TreeNode* node, int& sum, bool is_left) {
        if (node->left == nullptr &&
            node->right == nullptr && is_left) {
            sum += node->val;
            return;
        }
        if (node->left) Dfs(node->left, sum, true);
        if (node->right) Dfs(node->right, sum, false);
    }
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int sum = 0;
        Dfs(root, sum, false);
        return sum;
    }
};