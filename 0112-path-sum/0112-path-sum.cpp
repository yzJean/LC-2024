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
private:
    void Dfs(TreeNode* node, int sum, int targetSum, bool& has_sum) {
        if (has_sum) {
            return;
        }
        if (!node->left && !node->right) {
            has_sum = sum == targetSum;
            return;
        }
        if (node->left) Dfs(node->left, sum + node->left->val, targetSum, has_sum);
        if (node->right) Dfs(node->right, sum + node->right->val, targetSum, has_sum);
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        bool has_sum = false; // Need to initialize because the compiler set the default as true
        Dfs(root, root->val, targetSum, has_sum);
        return has_sum;
    }
};